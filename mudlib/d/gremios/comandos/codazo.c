//Kivara 1/11/2002
//Codazo

inherit "/std/comando";

#define GPCOST 5
#define NOM codazo

object me;	
object enemy;
	
void setup() {
	poner_ayuda("\n\n"
    "Nombre del Comando: codazo\n"
    "Coste en Pg: "+GPCOST+"\n"
    "Sintaxis: codazo <objetivo>\n"
    "Descripci�n: \n"
    "    Esta habilidad te permite asestar un "
    "terrible codazo a tu enemigo de una forma "
    "r�pida y eficaz.\n\n");
 	gasta_energia(0); //<-- fallo de vilat :_ si se pone en el efecto, no mola
	impedir_movimiento("Detienes tu golpe aplastante al moverte.\n");
	poner_retardo(0);
}


int precondiciones(){
	string argu;

		me=query_ejecutor();	
	::precondiciones();
	argu=query_argumento();
	//precondiciones al codazo
	if(me->query_dead()){
		return notify_fail("Los muertos no pueden dar codazos...\n");
	}
	if(me->query_timed_property("Codazo_done")){
		return notify_fail("Tus articulaciones no aguantarian otro impacto de ese calibre.\n");
	}	
	if(me->query_timed_property("Com_GuerFaeleen_Doing")){ //haciendo algun otro comando
		return notify_fail("Estas demasido ocupado para intentar un codazo.\n");
	}
	if(me->query_gp()<GPCOST){
			return notify_fail("Te sientes sin fuerzas para realizar un golpe asi.\n");
	}
	if (!argu || strcmp(argu,"")==0 ){
		return notify_fail("Sintaxis: codazo <victima>.\n");
	}		
	if(strcmp(argu,"all")==0 || strcmp(argu,"todos")==0 || strcmp(argu,"todo")==0){
		return notify_fail("No tienes tantos codos como para intentar semejante estupidez.\n");
	}
	//GASTAMOS EPS!!!!!!
	me->adjust_ep(-GPCOST);	
	if(sizeof(find_match(argu,ENV(me)))){
		 enemy=find_match(argu,ENV(me))[0];
	}else{
		return notify_fail("Intentas golpear a tu enemigo, pero no lo ves por aqui.\n");
	}					
	if(enemy->query_hidden()){
		return notify_fail("Intentas golpear a tu enemigo, pero no lo ves por aqui.\n");
	}
	if(enemy->query_dead()){
		return notify_fail("Tu golpe atraviesa el espiritu de "+enemy->QCN+" sin que este se entere de nada.\n");
	}
	if(enemy==me){
		return notify_fail("Casi te dislocas un hombro al realizar un movimiento tan est�pido.\n");
	}
	
	if (me->query_property("noguild")||me->query_pacify_spell()||enemy->query_pacify_spell()) {
		return notify_fail("Algo te impide realizar tu codazo.\n");
	}
	//A partir de aki a esperar para reintentar
	me->add_timed_property("Codazo_done",1,8);
	return 1;
}

int efecto(string nose, object tampoco){
		int opAt, opDef;
		string nomAt,nomDef;
	::efecto();			
	//ok, vamos a meterle		
	//jur jur, esto hay ke mirarlo bien, pk aun no he fallado ni un codazo xDD	
	opAt=me->query_level()+me->query_dex()+20;	
	opAt*=(250-me->query_thac0());
	opDef=enemy->query_level()+enemy->query_dex();
	opDef*=(100-enemy->query_total_ac());	
	nomAt=me->QCN;
	nomDef=enemy->QCN;
	if(random(opAt)>random(opDef)){
		tell_room(ENV(me),nomAt+" propina un terrible codazo a "+nomDef+"!\n",({me,enemy}));
		tell_object(me,"Tu codo golpea brutalmente el pecho de "+nomDef+ " dejandolo sin respiracion!\n");
		tell_object(enemy,nomAt+" te golpea fuertemente en el pecho con su codo, rompiendote un par de costillas!!\n");
		enemy->adjust_hp(-(random(15)+me->query_level()+10),me);
	}else{
		tell_room(ENV(me),nomDef+ "consigue esquivar el terrible codazo de "+nomAt+"!\n",({me,enemy}));
		tell_object(enemy,"Consigues esquivar el codazo que "+nomAt+" intentaba contra ti!\n");
		tell_object(me,"Tu enemigo es m�s listo de lo que parec�a y ha conseguido esquivar tu codazo!\n");
	}
	enemy->attack_by(me);
	return 1;
}