// Tienda para Ninetears - 25.10.2002
// Basado (muy libremente pero basado al fin y al cabo) en la Tienda de Rutseg en Reinos de Leyenda (Los Anyos Oscuros)
// No quitar la alusion a pusa por razones de copyright xD
#include <money.h>
#include <tiempo.h>

#define SUMIN 77760 // Es el numero de segundos reales que dura una semana en Driade
#define TIPOS ({"standard","herreria","armeria"}) // Aki van los tipos de tienda que vayamos metiendo
#define AJUSTES ({"raza","clase","gremio","alineamiento","ciudad"})

inherit "/std/room";

nosave mixed ajustes=({});
nosave mixed prohibidos=({});
nosave mixed permitidos=({});
nosave mixed suministro=({});
nosave object dependiente;
nosave string tipo;
nosave int solo_per=0;
nosave int no_vender=0;
nosave string depend;
mixed inventario=({});
int ultimo_suministro;

void suministrar();
int ajustar_objeto(string objeto,int can);
int query_numero_objetos(string archivo);

void prohibir_venta() { no_vender=1; }

object add_dependiente() {
	if(!dependiente=clone_object(depend)) {
		log_file("errores_comercios","No se pudo realizar con exito la clonacion de \""+depend+"\" en "+file_name(TO)+"\n");
		return 0;
		}
	if(CICLO_HANDLER->query_noche()) tell_room(TO,"El dependiente sale de la trastienda murmurando algo sobre los indeseables que le despiertan a estas horas.\n");
	else tell_room(TO,"El dependiente sale de la trastienda para atenderte.\n");
	dependiente->move(TO);
	return dependiente;
	}

void set_dependiente(string archivo) { depend=archivo; }

void create() {
	tipo= "standard";
	::create();
	restore_object(file_name(TO));
	if (time()>ultimo_suministro+SUMIN) suministrar();
	if (!depend) depend="/baseobs/npcs/dependiente";
	call_out("add_dependiente",5);
	}

void set_tipo(string str) {
	str=lower_case(str);
	if(!member_array(str,TIPOS)==-1) log_file("errores_comercios","Tipo de tienda inexistente  en "+file_name(TO)+"\n");
	else tipo= str;
	}

string query_tipo() { return tipo; }

void init() {
	::init();
	add_action("vender","vender");
	add_action("comprar","comprar");
	add_action("listar","listar");
	add_action("examinar","examinar");
	add_action("valorar","valorar");
	add_action("reparar","reparar");
	}

void suministrar() {
	int i;
	for (i=0;i<sizeof(suministro);i+=2) ajustar_objeto(suministro[i],suministro[i+1]);
	ultimo_suministro=time();
	}

void add_suministro(string objeto, int cantidad) {
	if (!objeto||cantidad<1) return;
	if (strlen(objeto)>2) if (objeto[strlen(objeto)-2..strlen(objeto)-1]==".c") objeto=objeto[0..strlen(objeto)-3];
	suministro+=({objeto,cantidad});
	}

void add_ajuste(string str, string arg, int porc) {
	if (!str||!arg||porc<50||porc>500) return;
	str=lower_case(str);
	if (member_array(str,AJUSTES)==-1) {
		log_file("errores_comercios","Ajuste inexistente en "+file_name(TO)+"\n");
		return;
		}
	ajustes+=({str,lower_case(arg),porc});
	}

void add_prohibido(string str, string arg) {
	if (!str||!arg) return;
	str=lower_case(str);
	if (member_array(str,AJUSTES)==-1) {
		log_file("errores_comercios","Prohibicion inexistente en "+file_name(TO)+"\n");
		return;
		}
	prohibidos+=({str,lower_case(arg)});
	}

void add_permitido(string str, string arg) {
	if (!str||!arg) return;
	str=lower_case(str);
	if (member_array(str,AJUSTES)==-1) {
		log_file("errores_comercios","Permision inexistente en "+file_name(TO)+"\n");
		return;
		}
	permitidos+=({str,lower_case(arg)});
	}

void restringir_permitidos() { solo_per=1; }

int ajustar_precio(object me,int precio) {
	int i,ajuste=0;
	mixed *razas=({});
	mixed *clases=({});
	mixed *gremios=({});
	mixed *alins=({});
	mixed *citys=({});
	if(!precio || !me) return 0; // Error raro, no bien recibido

	// Comprobamos si la raza, clase, gremio, alineamiento o ciudadania del player esta prohibida
	for(i=0;i<sizeof(prohibidos);i+=2) if (prohibidos[i]=="raza") razas+=({prohibidos[i+1]});
	for(i=0;i<sizeof(prohibidos);i+=2) if (prohibidos[i]=="clase") clases+=({prohibidos[i+1]});
	for(i=0;i<sizeof(prohibidos);i+=2) if (prohibidos[i]=="gremio") gremios+=({prohibidos[i+1]});
	for(i=0;i<sizeof(prohibidos);i+=2) if (prohibidos[i]=="alineamiento") alins+=({prohibidos[i+1]});
	for(i=0;i<sizeof(prohibidos);i+=2) if (prohibidos[i]=="ciudad") citys+=({prohibidos[i+1]});

	ajuste=1;
	if(member_array(lower_case(me->query_race()),razas)!=-1) ajuste=0;
	if(member_array(lower_case(me->query_property("clase")),clases)!=-1) ajuste=0;
	if(member_array(lower_case(me->query_guild_name()),gremios)!=-1) ajuste=0;
	if(member_array(lower_case(me->query_alineamiento_name()),alins)!=-1) ajuste=0;
	if(member_array(lower_case(me->query_ciudadania()),citys)!=-1) ajuste=0;

	// Si la tienda es solo para permitidos chequeamos los permisos
	if(solo_per) {
		razas=({});
		clases=({});
		gremios=({});
		alins=({});
		citys=({});
		for(i=0;i<sizeof(permitidos);i+=2) if (permitidos[i]=="raza") razas+=({permitidos[i+1]});
		for(i=0;i<sizeof(permitidos);i+=2) if (permitidos[i]=="clase") clases+=({permitidos[i+1]});
		for(i=0;i<sizeof(permitidos);i+=2) if (permitidos[i]=="gremio") gremios+=({permitidos[i+1]});
		for(i=0;i<sizeof(permitidos);i+=2) if (permitidos[i]=="alineamiento") alins+=({permitidos[i+1]});
		for(i=0;i<sizeof(permitidos);i+=2) if (permitidos[i]=="ciudad") citys+=({permitidos[i+1]});
		ajuste=0;
		if(member_array(lower_case(me->query_race()),razas)!=-1) ajuste=1;
		if(member_array(lower_case(me->query_property("clase")),clases)!=-1) ajuste=1;
		if(member_array(lower_case(me->query_guild_name()),gremios)!=-1) ajuste=1;
		if(member_array(lower_case(me->query_alineamiento_name()),alins)!=-1) ajuste=1;
		if(member_array(lower_case(me->query_ciudadania()),citys)!=-1) ajuste=1;
		}

	if (!ajuste) return 0; // No es bien recibido
	// Si ha llegado aqui es que esta permitido, asi que hacemos los calculos del ajuste
	razas=({});
	clases=({});
	gremios=({});
	alins=({});
	citys=({});
	for(i=0;i<sizeof(ajustes);i+=3) if (ajustes[i]=="raza") razas+=({ajustes[i+1],ajustes[i+2]});
	for(i=0;i<sizeof(ajustes);i+=3) if (ajustes[i]=="clase") clases+=({ajustes[i+1],ajustes[i+2]});
	for(i=0;i<sizeof(ajustes);i+=3) if (ajustes[i]=="gremio") gremios+=({ajustes[i+1],ajustes[i+2]});
	for(i=0;i<sizeof(ajustes);i+=3) if (ajustes[i]=="alineamiento") alins+=({ajustes[i+1],ajustes[i+2]});
	for(i=0;i<sizeof(ajustes);i+=3) if (ajustes[i]=="ciudad") citys+=({ajustes[i+1],ajustes[i+2]});

	ajuste=100;
	if(member_array(lower_case(me->query_race()),razas)!=-1) {
		for (i=0;i<sizeof(razas);i+=2) if (razas[i]==lower_case(me->query_race())) break;
		ajuste=ajuste*razas[i+1]/100;
		}
	if(member_array(lower_case(me->query_property("clase")),clases)!=-1) {
		for (i=0;i<sizeof(clases);i+=2) if (clases[i]==lower_case(me->query_property("clase"))) break;
		ajuste=ajuste*clases[i+1]/100;
		}
	if(member_array(lower_case(me->query_guild_name()),gremios)!=-1) {
		for (i=0;i<sizeof(gremios);i+=2) if (gremios[i]==lower_case(me->query_guild_name())) break;
		ajuste=ajuste*gremios[i+1]/100;
		}
	if(member_array(lower_case(me->query_alineamiento_name()),alins)!=-1) {
		for (i=0;i<sizeof(alins);i+=2) if (alins[i]==lower_case(me->query_alineamiento_name())) break;
		ajuste=ajuste*alins[i+1]/100;
		}
	if(member_array(lower_case(me->query_ciudadania()),citys)!=-1) {
		for (i=0;i<sizeof(citys);i+=2) if (citys[i]==lower_case(me->query_ciudadania())) break;
		ajuste=ajuste*citys[i+1]/100;
		}
	// Ya no tenemos en cuenta la carisma, sino la reputacion
	switch (me->query_rp()/5) {
		case 0..2:
		return 0; // No es bien recibido
		break;
		case 3:
		ajuste=ajuste*2;
		break;
		case 4:
		ajuste=ajuste*15/10;
		break;
		case 5:
		ajuste=ajuste*14/10;
		break;
		case 6:
		ajuste=ajuste*13/10;
		break;
		case 7:
		ajuste=ajuste*12/10;
		break;
		case 8:
		ajuste=ajuste*12/10;
		break;
		case 9:
		ajuste=ajuste*11/10;
		break;
		default:
		break;
		case 15:
		ajuste=ajuste*9/10;
		break;
		case 16:
		ajuste=ajuste*9/10;
		break;
		case 17:
		ajuste=ajuste*8/10;
		break;
		case 18:
		ajuste=ajuste*7/10;
		break;
		case 19:
		ajuste=ajuste*6/10;
		break;
		case 20:
		ajuste=ajuste*5/10;
		break;
		}
	return precio*ajuste/100;
	}

int validar_transaccion(object me, int precio) {
	if(!dependiente) {
		tell_object(me,"El dependiente no esta.\n");
		return 0;
		}

	if(dependiente->query_fighting() ) {
		if(member_array(me,dependiente->query_attacker_list()+dependiente->query_call_outed())!=-1 ) {
			if(!dependiente->enemigo(me)) dependiente->do_command("'Moriras estupid"+((me->query_gender()-1)?"a":"o")+"!!!");
			return 0;
			}
		else {
			if(!dependiente->ayuda(me)) dependiente->do_command("'Ayudame, "+me->query_cap_name()+"!");
			return 0;
			}
		}
	if(me->query_fighting()) {
		if(!dependiente->calma(me)) dependiente->do_command("'Tranquilizate un poco, "+me->query_cap_name()+", no quiero disputas aqui.");
		return 0;
		}
	if(!precio=ajustar_precio(me,precio) ) {
		if(!dependiente->no_tolerado(me) ) dependiente->do_command("'Fuera "+me->query_cap_name()+", aqui no queremos a gentuza de tu de calanya!");
		return 0;
		}
// Si es de noche el tendero sube un poco los precios por molestarle :)
	if(CICLO_HANDLER->query_noche()) precio=precio*10/9;

// Aqui va el aumento de precio por el Impuesto de Ventas


	return precio;
	}

string aproximar(int valor) {
	int coste;

	if(coste= valor/500) return CAP(query_num(coste,9000))+" platino"+(coste>1 ? "s":"");
	if(coste= valor/100) return CAP(query_num(coste,9000))+" oro"+(coste>1 ? "s":"");
	if(coste= valor/50) return CAP(query_num(coste,9000))+" esta�o"+(coste>1 ? "s":"");
	if(coste= valor/10){
		if(coste==1) return "Una plata";
		else return CAP(query_num(coste,9000))+" platas";
		}
	return CAP(query_num(coste,9000))+" cobre"+(coste>1 ? "s":"");
	}

int listar() {
	int ajuste,a,i;
	string *objetos=({});
	string ret,nombre;

	if(!ajuste=validar_transaccion(TP,100)) return notify_fail("");

	if(!sizeof(inventario)) return notify_fail("La tienda esta sin stock.\n");

	for (a=0;a<sizeof(inventario);a+=2) objetos+=({inventario[a]});
	ret= "\n %^CYAN%^Objeto                         Cantidad\tPrecio aproximado\n%^RESET%^";
	for(a=0;a<sizeof(objetos);a++) {
		if(!load_object(objetos[a])) {
			log_file("errores_comercios","Error al cargar el objeto \""+objetos[a]+"\" en "+file_name(TO)+"\n");
			continue;
			}
		nombre=objetos[a]->query_short();
		ret+=CAP(nombre);
		for (i=0;i<35-longitud(nombre);i++) ret+=" ";
		for (i=0;i<sizeof(inventario);i+=2) if (inventario[i]==objetos[a]) break;
		ret+=inventario[i+1]+"\t\t"+aproximar(objetos[a]->query_value()*ajuste/100)+"\n";
		}
	tell_object(TP,ret+"\n");
	return 1;
	}

int examinar(string objeto) {
	int ajuste,a;
	string *objetos=({});

	if(!objeto) return notify_fail("Uso: examinar <objeto>\n");

	if(!ajuste=validar_transaccion(TP,100)) return notify_fail("");

	for (a=0;a<sizeof(inventario);a+=2) objetos+=({inventario[a]});

	for(a=0;a<sizeof(objetos);a++) {
		if(member_array(objeto,objetos[a]->query_alias()+({objetos[a]->query_name()}))==-1) continue;


		if(!dependiente->do_examinar(TP,objeto) ) {
			tell_object(TP,dependiente->query_short()+" saca "+CAP(objeto)+" de la trastienda para que le eches un vistazo.\n");
			tell_room(TO,dependiente->query_short()+" saca un objeto de la trastienda y se lo muestra a "+TP->query_cap_name()+" para que le eche un vistazo.\n",TP);
			}
		tell_object(TP,"\nExaminas "+CAP(objeto)+" detenidamente:\n"+objetos[a]->query_long()+"\nEsta valorado en "+MONEY_HAND->money_value_string(objetos[a]->query_value()*ajuste/100)+".\n");
		return 1;
		}
	return notify_fail("Parece que aqui no tienen "+objeto+(member_array(objeto[strlen(objeto)-1..strlen(objeto)-1],({"a","e","i","o","u"}))!=-1?"s":"es")+" en este lugar.\n");
	}

int valorar(string objeto) {
	object tmp;

	if(no_vender) return notify_fail("Esta tienda no compra articulos.\n");

	if(!objeto) return notify_fail("Uso: vender <objeto>\n");

	if(!validar_transaccion(TP,100)) return notify_fail("");

	tmp= present(objeto,TP);
	if(!tmp) return notify_fail("No tienes ningun objeto con ese nombre que vender.\n");

	if(!dependiente->do_valorar(TP,tmp)) dependiente->do_command("'A ver que me traes... umm... te ofrezco "+MONEY_HAND->money_value_string(tmp->query_value())+" por tu "+tmp->query_short()+".\n");
	return 1;
	}

mixed query_inventario() { return inventario; }

int ajustar_objeto(string objeto,int cant) {
	int hay,i;
	if(!cant) return 0;
	if(cant>0) {
		for (i=0;i<sizeof(inventario);i+=2) if (objeto==inventario[i]) {
			inventario[i+1]+=cant;
			hay=1;
			}
		if(!hay) inventario+=({objeto,cant});
		return 1;
		}
	for (i=0;i<sizeof(inventario);i+=2) if (objeto==inventario[i]) {
		inventario[i+1]+=cant;
		if (inventario[i+1]<1) inventario=delete(inventario,i,2);
		break;
		}
	return -1;
	}

int comprar(string objeto) {
	string compra;
	string *objetos=({});
	int i;
	int precio;
	object ob;
	mixed pago;

	if(!objeto) return notify_fail("Uso: comprar <objeto>\n");

	for (int a=0;a<sizeof(inventario);a+=2) if(find_object(inventario[a]))objetos+=({inventario[a]});
	    else ajustar_objeto(inventario[a],-inventario[a+1]);

	for(i=0;i<sizeof(objetos);i++) {
		if(member_array(objeto,(objetos[i]->query_alias()+({objetos[i]->query_name()})))==-1) continue;
		precio=1;
		compra=objetos[i];
		break;
		}

	if(!precio) return notify_fail("Parece que aqui no tienen "+objeto+(member_array(objeto[strlen(objeto)-1..strlen(objeto)-1],({"a","e","i","o","u"}))!=-1?"s":"es")+".\n");
	if(!precio= validar_transaccion(TP,100)) return notify_fail("");
	precio=compra->query_value()*precio/100;
	precio=precio*(100-(random(TP->query_habilidad("regateo")/(2+random(3) ) ) ))/100;
	pago=({"cobre",precio});
	if(catch(TP->pay_money(pago)) ) return notify_fail(compra->query_short()+" cuesta "+MONEY_HAND->money_value_string(precio)+" y no tienes tanto dinero.\n");

	if(ajustar_objeto(compra,-1)>=0) return notify_fail(dependiente->query_short()+"exclama: Mira! Detras de ti! Un monstruo! Eh? Que dices de dinero?\n"); // Esto es porque ha pasado algun error, el player habra gastado dinero y no le han dado nada

	ob=clone_object(compra);
	if(!ob) {
		log_file("errores_comercios",compra+" no se cargo correctamente en la tienda "+file_name(TO)+" cuando "+TP->query_short()+" intento comprarlo en "+ctime(time())+"\n");
		return notify_fail("El objeto debia estar en malas condiciones, porque nada mas dartelo se ha desecho...\n");
		}
	ob->move(TP);

	if(!dependiente->do_comprar(TP,objeto))	{
		tell_room(TO,dependiente->query_short()+" va a la trastienda y trae "+ob->query_short()+".\n");
		dependiente->do_command("'A ver... Me das "+MONEY_HAND->money_value_string(precio)+", y esto para usted.\n");
		tell_room(TO,dependiente->query_short()+" sonrie.\n");
		}
	if(environment(ob)!=TP) {
		tell_object(TP,"Tu "+ob->query_short()+" pesa demasiado y se te cae.\n");
		tell_room(environment(TP),TP->query_cap_name()+" no es capaz de aguantar el peso de su "+ob->query_short()+" y se le cae.\n",TP);
		ob->move(TO);
		}
	return 1;
	}

int vender(string objeto) {
	object *venta,*en_uso=({}),*tipo_incorrecto=({});
	int i,dinero,ajuste;
	float ajuste2;
	if(no_vender) return notify_fail("Esta tienda no compra articulos.\n");
	if(!objeto) return notify_fail("Uso: vender <objeto>\n");

	if(!ajuste=validar_transaccion(TP,100)) return notify_fail("");
	venta= find_match(objeto,TP);
	if(!i= sizeof(venta)) return notify_fail("No tienes ningun objeto con ese nombre que vender.\n");

	for(;i--;) {
		if(venta[i]->query_in_use()) {
			en_uso+= ({venta[i]});
			continue;
			}
		if(venta[i]->query_property("player")) {
			tell_object(TP,venta[i]->query_short()+" es un objeto personal y no puede venderse.\n");
			tipo_incorrecto+= ({venta[i]});
			continue;
			}
		if(venta[i]->drop() || venta[i]->query_property("maldito")) {
			tell_object(TP,"No logras quitarte tu "+venta[i]->query_short()+", asi que no podras vender dicho objeto.\n");
			tipo_incorrecto+= ({venta[i]});
			continue;
			}
		switch(tipo) {
/*			case "joyeria":
				//La verdad es que no hay gemas de estas hoy en dia, pero quien sabe
				if(!venta[i]->query_gema() && !venta[i]->query_mineral() && !venta[i]->query_joyeria())
				{
					tipo_incorrecto+= ({venta[i]});
					continue;
				}
				break; */
			case "herreria":
				//No se aceptan armas encantadas
				if(venta[i]->query_enchant())
				{
					tipo_incorrecto+= ({venta[i]});
					continue;
				}
			case "armeria":
				//Tanto herreria como armeria solo aceptan armas y armaduras
				if(!venta[i]->query_armour() && !venta[i]->query_weapon()&&!venta[i]->query_shield())
				{
					tipo_incorrecto+= ({venta[i]});
					continue;
				}
				break;
/*			case "magia":
				//Solo aceptamos articulos magicos (que respondan a la siguiente funcion)
				//El sizeof es porque la funcion puede devolver ""
				if(!sizeof(venta[i]->enchant_string()))
				{
					tipo_incorrecto+= ({venta[i]});
					continue;
				}
				break;
			case "herboristeria":
				//Solo acepta objetos que hereden de /obj/planta.c o lo que es lo mismo que pasen las siguiente funcion
				if(venta[i]->query_planta())
				{
					tipo_incorrecto+= ({venta[i]});
					continue;
				}
				break; */
			case "standard":
			default:
				//Lo aceptamos todo
		}
		ajuste= venta[i]->query_value()*100/ajuste;
		ajuste2=1;
		for(int z=0;z<query_numero_objetos(explode(file_name(venta[i]),"#")[0]);z++) ajuste2*=1.1;
		ajuste=ajuste/(int)ajuste2;
		if(ajuste<1) ajuste=1;
		dinero+=ajuste;
		ajustar_objeto(explode(file_name(venta[i]),"#")[0],1);
		}
	venta-= en_uso+tipo_incorrecto;
	if(sizeof(venta)) {
		if(!dependiente->do_vender(TP,objeto)) dependiente->do_command("'Tome, "+MONEY_HAND->money_value_string(dinero)+" para usted, y me quedo con "+query_multiple_short(venta)+".\n");
		venta->dest_me();
		TP->adjust_money(MONEY_HAND->create_money_array(dinero));
		}
	if(sizeof(en_uso)) tell_object(TP,"No puedes vender "+query_multiple_short(en_uso)+" ya que estas usandolo.\n");
	if(sizeof(tipo_incorrecto)) dependiente->do_command("'Puede quedarse con "+query_multiple_short(tipo_incorrecto)+", esos objetos no nos interesan.\n");
	return 1;
	}

varargs void add_cartel(string placa) {
	if(!placa) placa= "placa";

	add_sign("Un "+placa+" de madera con algo escrito.\n",
		TO->query_short()+"\n"
		"  En este establecimiento denunciamos los hurtos. Si quieres algo los comandos son los siguientes:\n\n"
		"  <%^ORANGE%^listar%^RESET%^>   para ver los objetos en venta\n"
		"  <%^ORANGE%^comprar%^RESET%^>  para comprar uno de los objetos en venta\n"
		+(!no_vender ? "  <%^ORANGE%^vender%^RESET%^>   para vender uno de tus objetos\n"
		"  <%^ORANGE%^valorar%^RESET%^>  para valorar uno de tus objetos antes de venderlo\n":"")+
		"  <%^ORANGE%^examinar%^RESET%^> para examinar el objeto y saber su valor\n"+
		(tipo=="herreria" ? "  <%^ORANGE%^reparar%^RESET%^>  para reparar tus objetos\n":"\n"),
		placa,placa);
	}

void dest_me() {
	save_object(file_name(TO));
	::dest_me();
	}

int query_numero_objetos(string archivo) {
	int i;
	for(i=0;i<sizeof(inventario);i+=2) if (inventario[i]==archivo) break;
	if (i<sizeof(inventario)) return inventario[i+1];
	return 0;
	}

int query_reparable(object ob) { return (ob->query_weapon()||ob->query_armour()||ob->query_shield()); }

int reparar(string objeto) {
	int ajuste,low_c,max_c,val,total,diff,pobreval;
	object *objetos;
	object *tipo_incorrecto=({});
	object *buen_estado=({});
	object *pobre=({});

	if(tipo!="herreria") return notify_fail("Parece que aqui no reparan objetos.\n");
	if(!objeto) return notify_fail("Uso: reparar <objeto>\n");
	if(!ajuste=validar_transaccion(TP,100)) return notify_fail("");
	objetos=find_match(objeto,TP);

	if(!sizeof(objetos)) return notify_fail("No tienes nada asi en tu inventario.\n");

	for (int a=0;a<sizeof(objetos);a++) {
		if (query_reparable(objetos[a])) continue;
		tipo_incorrecto+=({objetos[a]});
		}

	objetos-=tipo_incorrecto;

	for (int i=0;i<sizeof(objetos);i++) {
    		low_c = objetos[i]->query_lowest_cond();
    		max_c = objetos[i]->query_max_cond();
    		diff = objetos[i]->query_cond();
    		val = objetos[i]->query_value()*ajuste/100;
		diff = (max_c-diff)*100/max_c;
    		if (diff/max_c < 0) diff = 0;
    		if (!diff) {
      			buen_estado += ({ objetos[i] });
			continue;
    			}
    		val = (diff * val)/100;
		if (val+total>TP->query_value()) {
      			pobre += ({ objetos[i] });
			pobreval+=val;
      			continue;
			}
		objetos[i]->adjust_cond(diff);
    		total += val;
		}
	objetos-=buen_estado;
	objetos-=pobre;
	total=total*(100-(random(TP->query_habilidad("regateo")/(2+random(3) ) ) ))/100;
	if (total) if(catch(TP->pay_money(({"cobre",total}))) ) {
		log_file("errores_comercios",TP->query_cap_name()+" ha reparado objetos sin pagar.");
		return notify_fail("Se ha producido un error, avisa a un Inmortal.\n");
		}

	if(!dependiente->do_reparar(TP,objetos,tipo_incorrecto,pobre,buen_estado)) {
		if(sizeof(objetos)) {
			tell_room(TO,dependiente->query_short()+" coge tu "+query_multiple_short(objetos)+" y se pone a dar golpes en su yunque.\n");
			dependiente->do_command("'De acuerdo, aqui tienes "+query_multiple_short(objetos)+". Son "+MONEY_HAND->money_value_string(total)+", gracias.");
			}
		if(sizeof(buen_estado)) dependiente->do_command("'No he reparado "+query_multiple_short(buen_estado)+" porque estaba en buen estado.");
		if(sizeof(pobre)) dependiente->do_command("'No tenias suficiente dinero para pagar la reparacion de "+query_multiple_short(pobre)+", te habria costado "+MONEY_HAND->money_value_string(pobreval)+".");
		if(sizeof(tipo_incorrecto)) dependiente->do_command("'En cuanto a "+query_multiple_short(tipo_incorrecto)+"... En fin, esas cosas no las reparamos aqui.");
		}
	return 1;
	}
