//Kivara & Flangerant 3/11/2002
//Doble_Golpe
//Es bastante sencillo, pero debido al uso de recursividad, 
//solo es aconsejable usarlo como modelo si se controla el tema.
//Para comandos intant,mirar codazo.c del mismo autor

#define EPCOST 10


inherit "/d/gremios/hechizos/bases/patch.c";


object pRoom;


int DG_primero(object enemy,object me,int jerbit);
int DG_segundo(object enemy, object me, int jerbit);

string help(){
	return 
	  "\n\n"
    "Nombre del Comando: Doble Golpe\n"
    "Coste en Ep: "+EPCOST+"\n"
    "Sintaxis: dobleg <objetivo>\n"
    "Descripci�n: \n"
    "		Esta t�cnica es la preferida de "
    "los guerreros de Faeleen. Consiste "
    "en dos golpes seguidos que destrozan "
    "al rival mas preparado.\n\n";
}

int dobleg(string args, object player){
	object me;
//	object pRoom;
	object enemy;	
	int jerbit;
	
	if(!player){
		me=TP;
	}else{
		me=player;
	}
	
	//precondiciones al doble_golpe
	if(me->query_dead()){
		return notify_fail("Int�ntalo cuando te cuentes entre los vivos...\n");
	}
	if(me->query_timed_property("DG_done")){
		return notify_fail("Necesitas m�s tiempo para preparar tu doble golpe.\n");
	}
	if(me->query_timed_property("DG_doing")){
		return notify_fail("Ya estas preparando un doble golpe.\n");
	}	
	if(me->query_timed_property("Com_GuerFaeleen_Doing")){
		return notify_fail("Estas demasido ocupado para intentar un doble golpe.\n");
	}
	if(me->query_ep()<EPCOST){
		return notify_fail("Tu cuerpo est� cansado, intentalo m�s tarde.\n");
	}	
	if ((args,"")==0 || !args){
		return notify_fail("Sintaxis: dobleg <victima>.\n");
	}	
	if(strcmp(args,"all")==0 || strcmp(args,"todos")==0 || strcmp(args,"todo")==0){
		return notify_fail("No tienes suficientes manos para eso.\n");
	}
	
	//ok, gastamos GP's
	me->adjust_gp(-EPCOST);
	me->add_timed_property("DG_doing",1,10);
	me->add_timed_property("DG_done",1,10);
	me->add_timed_property("Com_GuerFaeleen_Doing",1,10);	
	
		
	enemy=find_one_match(args,environment(me));	
	if(!enemy || enemy->query_hidden()){
		return notify_fail("Intentas golpear a tu enemigo, pero no lo ves por aqui.\n");
	}
	if(enemy->query_dead()){
		return notify_fail("Un magn�fico golpe atraviesa el espiritu de "+enemy->QCN+", pero no produce ningun resultado.\n");
	}
	
	if(enemy==me){
		return notify_fail("Ser�a mejor que s�lo usases esta t�cnica con tus enemigos.\n");
	}
		
	if (me->query_property("noguild")||me->query_pacify_spell()||enemy->query_pacify_spell()) {
		return notify_fail("Algo te impide realizar tu doble golpe.\n");
	}
	
	

	//falta comprovar ke las dos armas son del mismo tipo
	//falta inhabilitar el cambio de armas
	//falta prohibir un codazo mientras doblegolpeamos
		
	//ok, vamos a meterle
	pRoom=environment(me);
	tell_object(me,"Tu preparas para realizar un devastador primer golpe.\n");
  jerbit=0;
	call_out("DG_primero",1,enemy,me,jerbit);
	return 1;
}
	
int DG_primero(object el,object yo,int jerbit){
	int dany;
	string nomAt,nomDef;
	int opAt, opDef;
	object enemy,me;
	enemy=el;
	me=yo;
	
	if (me->query_dead()){
		return tell_object(TP,"Tu muerte te impide acabar de realizar el doble golpe.\n");
	}
	if(!enemy || enemy->query_hidden()){
		return tell_object(TP,"Intentas golpear a tu enemigo, pero no lo ves por aqui.\n");
	}		
	if(enemy->query_dead()){
		return tell_object(TP,"La muerte de tu enemigo le evita sufrir otro duro castigo.\n");
	}
	if (pRoom!=environment(me)){
		return tell_object(TP,"No puedes golpear a tu enemigo si estas en movimiento.\n");
	}	
	if(pRoom!=environment(enemy)){
		return tell_object(TP,"Tu enemigo ha escapado antes de que pudieses golpearle.\n");
	}		
	if (me->query_property("noguild")||me->query_pacify_spell()||enemy->query_pacify_spell()){
		return tell_object(TP,"Algo te impide continuar con tu doble golpe.\n");
	}
	//ke empieze la fiesta ;)	
	if(jerbit==0){ //opcion no recursiva
		opAt=me->query_level()+me->query_dex()+20;	
		opAt*=(250-me->query_thac0());
		opDef=enemy->query_level()+enemy->query_dex();
		opDef*=(100-enemy->query_total_ac());	
		nomAt=me->QCN;
		nomDef=enemy->QCN;
		dany=me->query_level()*2+random((me->query_level())*0.5);
		if(random(opAt)>random(opDef)){
			tell_room(ENV(me),nomAt+" asesta un brutal golpe a "+nomDef+", mientras prepara su brazo izquierdo para otro demoledor ataque!\n",({me,enemy}));
			tell_object(me,"Asestas un brutal golpe a "+nomDef+", mientras preparas otro magistral golpe con tu brazo izquierdo!\n");
			tell_object(enemy,nomAt+" te golpea brutalmente en el pecho, pero parece que a�n prepara otro demoledor ataque!!\n");
			enemy->adjust_hp(-dany,me);
			call_out("DG_segundo",1,enemy,me,0);
		}else{ //si el primero falla, lo dejamos :(
			tell_room(ENV(me),nomDef+" esquiva el golpe que "+nomAt+" tramaba contra el!\n",({me,enemy}));
			tell_object(enemy,"Consigues esquivar el doble golpe que "+nomAt+" preparaba contra ti!\n");
			tell_object(me,"Tu diestro enemigo consigue esquivar el doble golpeo!\n");
			me->add_timed_property("DG_done",1,10);
		}
		enemy->attack_by(me);
		return 1;
	}else{ //opcion recursiva
		call_out("DG_primero",1,enemy,me,jerbit-1);//jeje, inmersion de eficiencia i tal xD
	}	
}

int DG_segundo(object el, object yo,int jerbit){
	int dany;
	string nomAt,nomDef;
	int opAt, opDef;
	object enemy,me;
	
	enemy=el;
	me=yo;
	
	if (me->query_dead()){
		return tell_object(TP,"Tu muerte te impide acabar de realizar el doble golpe.\n");
	}
	if(!enemy || enemy->query_hidden()){
		return tell_object(TP,"Intentas golpear a tu enemigo, pero no lo ves por aqui.\n");
	}	
	if (pRoom!=environment(me)){
		return tell_object(TP,"No puedes golpear a tu enemigo si estas en movimiento.\n");
	}
	if(pRoom!=environment(enemy)){
		return tell_object(TP,"Parece que tu enemigo ya ha tenido bastante y huye despavorido.\n");
	}	
	if(enemy->query_dead()){
		return tell_object(TP,"La muerte de tu enemigo le evita sufrir otro duro castigo.\n");
	}
	if (me->query_property("noguild")||me->query_pacify_spell()||enemy->query_pacify_spell()){
		return tell_object(TP,"Algo te impide continuar con tu doble golpe.\n");
	}
	//ke empieze la fiesta (otra vez xD)
	
	if(jerbit==0){
		opAt=me->query_level()+me->query_dex()+20;	
		opAt*=(250-me->query_thac0());
		opDef=enemy->query_level()+enemy->query_dex();
		opDef*=(100-enemy->query_total_ac());	
		nomAt=me->QCN;
		nomDef=enemy->QCN;
		dany=me->query_level()*2+random((me->query_level()*1.25)); //el segundo pega mas :)_ __
		
		if((0.75*random(opAt))>random(opDef)){ //el segundo cuesta mas de meter
			tell_room(ENV(me),nomAt+" revienta el cuerpo de "+nomDef+" con un rapid�simo segundo ataque!\n",({me,enemy}));
			tell_object(me,nomDef+" siente tu inmenso poder cuando le alcanzas por segunda vez!!\n");
			tell_object(enemy,nomAt+" te rompe varias costillas con un segundo ataque!!\n");
			enemy->adjust_hp(-dany,me);	
		}else{
			tell_room(ENV(me),nomDef+"esquiva el segundo golpe que "+nomAt+" tramaba contra el!\n",({me,enemy}));
			tell_object(enemy,"Consigues esquivar el segundo golpe que "+nomAt+" preparaba contra ti!\n");
			tell_object(me,"No logras golpear a tu enemigo por segunda vez!\n");
			me->add_timed_property("DobleG_done",1,10);
		}
		me->add_timed_property("DobleG_done",1,10);
		me->remove_timed_property("DG_doing");	
		me->remove_timed_property("Com_GuerFaeleen_Doing",1,10);	
		enemy->attack_by(me);
		return 1;
	}else{
		call_out("DG_segundo",1,enemy,me,jerbit-1);
	}
}