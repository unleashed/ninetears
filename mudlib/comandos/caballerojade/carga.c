//.oO JaDe Oo.  Enero'03

inherit "/std/comando";

#define ECOST 25

object me,enemy;

//string * bonusraces = ({ "Orco","Hombre-Lagarto","Dragon","Gigante","Troll" });
//string * bonus_items = ({ "escudo templanza","escudo templario", "portador de tormentas",
//                          "escudo negro" , "gran escudo del demonio", "desplazador" });

void setup() {
	poner_ayuda("\n\n"
    "Nombre del Comando: Carga\n"
    "Coste en Ep: "+ECOST+"\n"
    "Sintaxis: carga <objetivo>\n"
    "Descripci�n: \n"
    "Este es el ataque por excelencia del "
    "gremio. Consiste en embestir con tu escudo y "
    "el peso de tu cuerpo a tu enemigo.\n\n");
 	gasta_energia(0); 
	impedir_movimiento("Detienes tu carga al moverte.\n");
	poner_retardo(0);
}
	
int precondiciones() {
  string argu;
  me=query_ejecutor();
    
  ::precondiciones();
  argu=query_argumento();
  
  if(me->query_dead()){
	return notify_fail("Eres un espiritu, qu� pretendes hacer?\n");
  }
  if(me->query_timed_property("carga_done")){
  	return notify_fail("S�lo los Caballeros m�s poderosos pueden intentar una segunda carga en tan poco tiempo.\n");
  }
  if (me->query_ep()<ECOST){
  	return notify_fail("Est�s demasiado cansado para cargar a tus enemigos.\n");
  }
  if (!argu || strcmp(argu,"")==0 ){
	return notify_fail("Sintaxis: cargar <victima>.\n");
  }	
  if(strcmp(argu,"all")==0 || strcmp(argu,"todos")==0 || strcmp(argu,"todo")==0){
	return notify_fail("S�lo puedes realizar tu carga contra un �nico enemigo.\n");
  }
  if(sizeof(find_match(argu,ENV(me)))){
	 enemy=find_match(argu,ENV(me))[0];
  }
  else {
	return notify_fail("Intentas cargar a tu enemigo, pero no parece estar aqu�.\n");
  }
  if(enemy->query_hidden()){
	return notify_fail("Intentas cargar a tu enemigo, pero no parece estar aqu�.\n");
  }
  if(enemy->query_dead()){
	return notify_fail("Tu golpe atraviesa el espiritu de "+enemy->QCN+" sin que este se entere de nada.\n");
  }
  if(enemy==me){
	return notify_fail("C�mo pretendes hacerlo? Corriendo hacia ti mismo?.\n");
  }
  if (me->query_property("noguild")||me->query_pacify_spell()||enemy->query_pacify_spell()) {
	return notify_fail("Algo te impide realizar el golpe.\n");
  }
  
  me->adjust_ep(-ECOST);		
  me->add_timed_property("carga_done",1,10);
   
tell_object(me, "Exclamas: Dobl�gate ante el %^BOLD%^%^BLACK%^Mal%^RESET%^! \nAl tiempo que corres hacia "+enemy->query_cap_name()+".\n");
tell_room(environment(me), me->query_cap_name()+" exclama: Dobl�gate ante el %^BOLD%^%^BLACK%^Mal%^RESET%^!\n Al tiempo que corre hacia "+enemy->query_cap_name()+".\n", ({me,enemy}));
tell_object(enemy, me->query_cap_name()+" exclama: Dobl�gate ante el %^BOLD%^%^BLACK%^Mal%^RESET%^!\n Al tiempo que corre hacia ti.\n");
    
  return 1;
}

int efecto(string nose, object tampoco){
		int opAt, opDef;
		string nomAt,nomDef;
	::efecto();			
			
	opAt=me->query_level()+me->query_dex()+20+me->query_habilidad("carga");	
	opAt*=(250-me->query_thac0());
	opDef=enemy->query_level()+enemy->query_dex();
	opDef*=(100-enemy->query_total_ac());	
	nomAt=me->QCN;
	nomDef=enemy->QCN;
	if(random(opAt)>random(opDef)){
		tell_room(ENV(me),nomAt+" impacta contra "+nomDef+" con un sensacional golpe!.\n",({me,enemy}));
		tell_object(me,"Impactas contra "+nomDef+ " con un sensacional golpe!.\n");
		tell_object(enemy,nomAt+" impacta contra ti con un sensacional golpe!.\n");
		enemy->adjust_hp(-(random(50)+me->query_level()+100),me);
	}else{
		tell_room(ENV(me),nomDef+ "consigue esquivar la carga que "+nomAt+" dirig�a en su contra!\n",({me,enemy}));
		tell_object(enemy,"Consigues esquivar la carga que "+nomAt+" dirig�a contra ti!\n");
		tell_object(me,"Tu enemigo consigue esquivar tu carga!\n");
	}
	enemy->attack_by(me);
	return 1;
}