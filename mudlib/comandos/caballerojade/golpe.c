//.oO JaDe Oo.  Febrero'03

inherit "/std/comando";

#define ECOST 15

object me;	
object enemy;
	
void setup() {
	poner_ayuda("\n\n"
    "Nombre del Comando: Golpe de Escudo\n"
    "Coste en Pg: "+ECOST+"\n"
    "Sintaxis: golpeescudo <objetivo>\n"
    "Descripci�n: \n"
    "Has pensado que un escudo puede ser �til "
    "para algo m�s que parar los golpes? En efecto, "
    "utilizar tu escudo como ataque en lugar de defensa "
    "puede salvar m�s de una situaci�n.\n\n");
 	gasta_energia(0); 
	impedir_movimiento("Detienes la maniobra al moverte.\n");
	poner_retardo(0);
}

int precondiciones(){
	string argu;
	me=query_ejecutor();
		
	::precondiciones();
	argu=query_argumento();
	
        
        for(i=0;i<sizeof(equipado);i++) if(equipado[i]->query_shield()) escudos+=({equipado[i]});
		return notify_fail("Prueba a golpear usando un escudo.\n");
	
	if(me->query_dead()){
		return notify_fail("Los muertos no pueden usar escudos...\n");
	}
	if(me->query_timed_property("golpe_done")){
		return notify_fail("Tus articulaciones no aguantar�an otro impacto de ese calibre en tan poco tiempo.\n");
	}	
	if(me->query_timed_property("Com_GuerFaeleen_Doing")){ //haciendo algun otro comando
		return notify_fail("Dos ataques a la vez? Naaah...\n");
	}
	if(me->query_ep()<ECOST){
		return notify_fail("A duras penas puedes sostener tu escudo, imag�nate intentar golpear con �l.\n");
	}
	if (!argu || strcmp(argu,"")==0 ){
		return notify_fail("Sintaxis: golpeescudo <victima>.\n");
	}		
	if(strcmp(argu,"all")==0 || strcmp(argu,"todos")==0 || strcmp(argu,"todo")==0){
		return notify_fail("S�lo tienes un escudo, por tanto s�lo puedes golpear a un enemigo.\n");
	}
	if(sizeof(find_match(argu,ENV(me)))){
		 enemy=find_match(argu,ENV(me))[0];
	}
	else {
		return notify_fail("Intentas golpear a tu enemigo, pero no parece estar aqu�.\n");
	}					
	if(enemy->query_hidden()){
		return notify_fail("Intentas golpear a tu enemigo, pero no parece estar aqu�.\n");
	}
	if(enemy->query_dead()){
		return notify_fail("Tu golpe atraviesa el espiritu de "+enemy->QCN+" sin que este se entere de nada.\n");
	}
	if(enemy==me){
		return notify_fail("Casi te dislocas un hombro al realizar un movimiento tan est�pido.\n");
	}
	
	if (me->query_property("noguild")||me->query_pacify_spell()||enemy->query_pacify_spell()) {
		return notify_fail("Algo te impide realizar el golpe.\n");
	}
	
	me->adjust_ep(-ECOST);	
	me->add_timed_property("golpe_done",1,8);
	return 1;
}

int efecto(string nose, object tampoco){
		int opAt, opDef;
		string nomAt,nomDef;
	::efecto();			
			
	opAt=me->query_level()+me->query_dex()+20;	
	opAt*=(250-me->query_thac0());
	opDef=enemy->query_level()+enemy->query_dex();
	opDef*=(100-enemy->query_total_ac());	
	nomAt=me->QCN;
	nomDef=enemy->QCN;
	if(random(opAt)>random(opDef)){
		tell_room(ENV(me),nomAt+" golpea h�bilmente a "+nomDef+" haci�ndole perder el equilibrio.\n",({me,enemy}));
		tell_object(me,"Con un diestro movimiento golpeas a "+nomDef+ " con tu escudo, haci�ndole perder el equilibrio.\n");
		tell_object(enemy,nomAt+" te golpea h�bilmente con su escudo, haci�ndote perder el equilibrio.\n");
		enemy->adjust_hp(-(random(15)+me->query_level()+10),me);
	}else{
		tell_room(ENV(me),nomDef+ "consigue esquivar el h�bil golpe de "+nomAt+"!\n",({me,enemy}));
		tell_object(enemy,"Consigues esquivar el golpe que "+nomAt+" intentaba contra ti!\n");
		tell_object(me,"Tu enemigo es m�s h�bil de lo que parec�a y ha conseguido esquivar tu golpe!\n");
	}
	enemy->attack_by(me);
	return 1;
}