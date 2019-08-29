// Vilat 29.10.2002
// Hostal para Ninetears

// - Soporte para comida en malas condiciones

#include <money.h>
inherit "/std/room";

#define AJUSTES ({"raza","clase","gremio","alineamiento","ciudad"}) //Tipos de ajustes validos

int calidad; // Esta variable es como las "estrellas" de un hotel o los "tenedores" de un restaurante
object dependiente; // El dependiente del establecimiento
string *platos=({}); // Los archivos de los platos
mixed ajustes=({});
mixed prohibidos=({});
mixed permitidos=({});
int solo_per;

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
		if(member_array(me,dependiente->query_attacker_list())||member_array(me,dependiente->query_call_outed()) ) {
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

void set_dependiente(string archivo) {
	dependiente=clone_object(archivo);
	if (!dependiente) {
		log_file("errores_comercios","No se ha podido clonar al dependiente en "+file_name(TO)+"\n");
		return;
		}
	dependiente->move(TO,dependiente->query_short()+" deja de limpiar el establecimiento para atenderte.\n");
	return;
	}

void create() {
	::create();
	this_object()->add_property("no_undead",1);
	if (calidad<0||calidad>5) calidad=0;
	if (!dependiente) set_dependiente("/baseobs/npcs/tabernero");
	}

void set_calidad(int i) { calidad=i; }
int query_calidad() { return calidad; }

void set_salida(string archivo) {
	TO->add_exit("fuera",archivo,"standard");
	renew_exits();
	TO->modify_exit("fuera",({"function","validar_salida"}));
	}

int validar_salida() {
	object *inventario;
	inventario=all_inventory(TP);
	for (int a=0;a<sizeof(inventario);a++) if(inventario[a]->query_comida()&&inventario[a]->query_property("plato")) return notify_fail("No pretenderas realmente irte con un plato de comida verdad? Donde piensas llevarlo?\n");
	return 1;
	}

void add_plato(string archivo) {
	if (archivo[strlen(archivo)-2..strlen(archivo)-1]!=".c") archivo+=".c";
	if (file_size(archivo)<1||(!archivo->query_comida()&&!archivo->query_bebida())) {
		log_file("errores_comercios","Plato incorrecto en "+file_name(TO)+"\n");
		return;
		}
	if (member_array(archivo,platos)==-1) platos+=({archivo});
	return;
	}

void init() {
	::init();
	add_action("listar","menu");
	add_action("comprar","comprar");
	}

int listar() {
	string *comida=({});
	string *bebida=({});
	string *alcohol=({});
	int co=TP->query_cols();
	int i,a,j;
	int ajuste;
	string ret="{%^RESET%^ Menu de "+TO->query_short()+" %^ORANGE%^}";
	for (a=longitud(TO->query_short())+14;a<co;a+=2) ret="="+ret+"=";
	ret="%^ORANGE%^O"+ret+"O%^RESET%^\n";
	if (!ajuste=validar_transaccion(TP,100)) return notify_fail("");
	if(!sizeof(platos)) return notify_fail("Parece que "+dependiente->query_short()+" no ha preparado ningun plato aun.\n");
	for (a=0;a<sizeof(platos);a++){
		if(platos[a]->query_tipo()=="comida") comida+=({platos[a]});
		if(platos[a]->query_tipo()=="bebida") bebida+=({platos[a]});
		if(platos[a]->query_tipo()=="alcohol") alcohol+=({platos[a]});
		}
	ret+="\n";
	if (sizeof(comida)) {
		ret+="\t%^BOLD%^ Plato de Comida";
		for(i=24;i<co-14;i++) ret+=" ";
		ret+="Precio%^RESET%^\n";
		for (i=0;i<sizeof(comida);i++) {
			ret+="       ";
			ret+=comida[i]->query_short();
			for (j=longitud(comida[i]->query_short())+7;j<co-16;j++) ret+=" ";
			ret+=aproximar(ajuste*comida[i]->query_value()/100)+"\n";
			}
		ret+="\n";
		}
	if (sizeof(bebida)) {
		ret+="\t%^BOLD%^     Bebida";
		for(i=19;i<co-14;i++) ret+=" ";
		ret+="Precio%^RESET%^\n";
		for (i=0;i<sizeof(bebida);i++) {
			ret+="       ";
			ret+=bebida[i]->query_short();
			for (j=longitud(bebida[i]->query_short())+7;j<co-16;j++) ret+=" ";
			ret+=aproximar(ajuste*bebida[i]->query_value()/100)+"\n";
			}
		ret+="\n";
		}
	if (sizeof(alcohol)) {
		ret+="\t%^BOLD%^Bebida Alcoholica";
		for(i=25;i<co-14;i++) ret+=" ";
		ret+="Precio%^RESET%^\n";
		for (i=0;i<sizeof(alcohol);i++) {
			ret+="       ";
			ret+=alcohol[i]->query_short();
			for (j=longitud(alcohol[i]->query_short())+7;j<co-16;j++) ret+=" ";
			ret+=aproximar(ajuste*alcohol[i]->query_value()/100)+"\n";
			}
		ret+="\n";
		}
	ret+="%^ORANGE%^O";
	for(i=0;i<co-1-!(longitud(TO->query_short())%2);i++) ret+="=";
	ret+="O%^RESET%^\n";
	tell_object(TP,ret+"\n");
	return 1;
	}

varargs void add_cartel(string cartel) {
	if (!cartel) cartel="cartel";

	add_sign("Un "+cartel+" de madera con algo escrito.\n",
		TO->query_short()+"\n"
		"  Si deseas algo los comandos son los siguientes:\n"
		"  <%^ORANGE%^menu%^RESET%^>     para ver el menu\n"
		"  <%^ORANGE%^comprar%^RESET%^>  para comprar algo del menu\n"+
		"\n",
		cartel,cartel);
	}

int comprar(string str) {
	object plato;
	int ajuste;
	if(!ajuste=validar_transaccion(TP,100)) return notify_fail("");
	if(!str) return notify_fail("Deberias especificar que quieres comprar, no crees?\n");
	for (int i=0;i<sizeof(platos);i++) {
		if(str!=platos[i]->query_name()) continue;
		if(catch(TP->pay_money(({"cobre",ajuste*platos[i]->query_value()/100}))) ) return notify_fail("Eres demasiado pobre.\n");
		plato=clone_object(platos[i]);
		if(!plato) {
			log_file("errores_comercios","Se produjo un error al clonar el plato "+platos[i]+"\n");
			return notify_fail(dependiente->query_short()+" no tiene ganas de cocinar ese plato ahora mismo.\n");
			}
		plato->add_property("plato",1);
		 // En un local de infima calidad la comida esta mala una de cada 50 veces, mientras que en uno de calidad maxima, una de cada 300 veces
		if (plato->query_tipo()=="comida") if(!random((calidad+1)*50)) plato->corromper();
		plato->move(TP);
		tell_object(TP,"Compras "+plato->query_short()+".\n");
		tell_room(TO,TP->query_cap_name()+" compra "+plato->query_short()+".\n",TP);
		return 1;
		}
	return notify_fail("Parece que el plato que quieres no esta a la venta.\n");
	}

