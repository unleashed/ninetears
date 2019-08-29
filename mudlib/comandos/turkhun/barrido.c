//Gareth 19.12.02
//Cabezazo para los Khurgars
// Aprendiendo, por Dagda para los Turkhun

inherit "/std/comando";

#define STUN "/comandos/shadows/stun_zancadilla.c"
object me,ob;

void setup() {
  poner_ayuda("\nNombre del Comando: Barrido \nCoste en Energia: 10\nSintaxis: barrido <objetivo>\nDescripcion: \nEste comando te permite barrer del suelo los pies de tu enemigo, haciendo que este caiga al suelo, impidiendole el movimiento por unos momentos.\n");
  gasta_energia(25);
  impedir_movimiento("Te desvias de tu objetivo al moverte.\n");
  poner_retardo(1);
}

int precondiciones() {
  me=query_ejecutor();
  
  ::precondiciones();
  
    if(me->query_property("barrido")) return notify_fail("Ya est�s intentando tumbar a un enemigo.\n");
  if(sizeof(find_match(query_argumento(),ENV(me)))) ob=find_match(query_argumento(),ENV(me))[0];
  else return notify_fail("A quien quieres tirar al suelo?\n");
  if (ob==me) return notify_fail("Solo los grandes maestros pueden hacer eso!!\n");
  if (ob->query_dead()) return notify_fail("Eso es un espiritu.. no tiene piernas!.\n");
  tell_object(me, "Te preparas para hacerle una jugarreta a "+ob->query_cap_name()+".\n");
  tell_room(environment(me), me->query_cap_name()+" se coloca en una posicion mas baja para golpear a "+ob->query_cap_name()+".\n", ({me,ob}));
  tell_object(ob, "Ves a "+me->query_cap_name()+ "hacer una rapida y extra�a maniobra, te preparas para lo peor.\n");
    me->add_property("barrido",1);
  return 1;
}

int condiciones() {
    me->remove_property("barrido");
  if (me->query_dead()) return notify_fail("Eres un espiritu, no serviria de mucho tirar al suelo a alguien.\n");
  ::condiciones();
  if (!ob||ob->query_dead()) return notify_fail("Tu objetivo ha muerto y no puedes tumbarlo.\n");
  if (ENV(ob)!=ENV(me)) return notify_fail("Tu oponente ha visto tu maniobra y a huido rapidamente!!\n");
  if ( me->query_ep() < 0 ) return notify_fail("No tienes suficiente energia para hacer esa maniobra.\n");
  me->add_property("barrido",1);
  return 1;
}

int efecto( string inutil, object masinutil ) {
  int mychance,itschance,j;
  object shad;

  ::efecto(inutil,masinutil);
  mychance=me->query_level()+me->query_total_ac()+20+me->query_habilidad("barrido");
  itschance=ob->query_level()+ob->query_con();
  itschance*=(100-ob->query_total_ac());
  mychance*=(300-me->query_thac0());

  if(random(mychance)>random(itschance)) {
  j = random(5)+6;
  tell_object(me,"De un agil golpe, le golpeas bajo la rodilla haciendole caer ruidosamente al suelo.\n");
  tell_room(environment(me), "Le da un golpe seco bajo las rodillas, haciendole caer al suelo ruidosamente.\n", ({me,ob}));
  tell_object(ob, "Te golpea las piernas, perdes el equilibrio y caes ruidosamente al suelo.\n");
  ob->add_timed_property("stun_on", 1, j);
  ob->add_timed_property("nocast",1, j);
  ob->add_timed_property("noguild",1, j);
  ob->add_timed_property("passed out", "Aun te encuentras aturdido por el "
  			 "golpe de "+me->query_cap_name()+" y no puedes "
  			 "levantarte.\n");
  shad = clone_object(STUN);
  shad->setup_shadow(ob, j);
  ob->add_extra_look(shad);
  ob->attack_by(me);
  if(me->query_level()<=ob->query_level()) me->adjust_sp(1);
  }
  else {
  tell_object(me, ""+ob->query_cap_name()+" consigue esquivarte en el "
  	"ultimo momento!\n");
  tell_room(environment(me),me->query_cap_name()+" intenta una extra�a maniobra, pero falla en su intento.\n");
  tell_object(ob,"Intenta tirarte, pero consigues esquivarlo rapidamente de un salto.\n");
  ob->attack_by(me);
  }
  me->remove_property("barrido");
  return 1;
 }
