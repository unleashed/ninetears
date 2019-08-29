//Gareth 19.12.02
//Cabezazo para los Khurgars

inherit "/std/comando";

#define STUN "/d/gremios/comandos/shadows/stun_cabezazo.c"
object me,ob;

void setup() {
  poner_ayuda("\nNombre del Comando: Cabezazo\nCoste en Energia: 15\nSintaxis: cabezazo <objetivo>\nDescripcion: \n    Este comando hara que un Khurgar cargue contra un enemigo, embiestiendole con la cabeza en el estomago, dejandolo aturdido durante unos segundos. La fuerza de la embestida dependera de la proteccion que lleve el Khurgar y de la constitucion del oponente.\n");
  impedir_movimiento("Te desvias de tu objetivo al moverte.\n");
  poner_retardo(1);
}

int precondiciones() {
  me=query_ejecutor();
  
  ::precondiciones();

  if(sizeof(find_match(query_argumento(),ENV(me)))) ob=find_match(query_argumento(),ENV(me))[0];
  else return notify_fail("A quien quieres embestir?\n");
  if (ob==me) return notify_fail("Eso no seria una buena idea!!\n");
  if (ob->query_dead()) return notify_fail("No puedes embestir a un espiritu!.\n");
  if (ob->query_property("cabezazo")) return notify_fail("Ya estas lanzando un cabezazo.\n");
  if (me->query_ep()<15) return notify_fail("No tienes suficiente energia para darle un cabezazo a alguien.\n");
  ob->add_property("cabezazo",1);
  tell_object(me, "Te preparas, cojes fuerzas y te dirijes corriendo a toda "
      "velocidad contra "+ob->query_cap_name()+".\n");
  tell_room(environment(me), me->query_cap_name()+" echa a correr rapidamente "
        "hacia "+ob->query_cap_name()+".\n", ({me,ob}));
  tell_object(ob, "Ves a "+me->query_cap_name()+" corriendo enloquecido "
    	"hacia ti con un gesto de furia.\n");
  return 1;
}

int condiciones() {
  if (me->query_dead()) {
  	ob->remove_property("cabezazo");
  	return notify_fail("Eres un espiritu, no serviria de mucho embestir a alguien.\n");
      }
  ::condiciones();
  if (!ob||ob->query_dead()) {
  	ob->remove_property("cabezazo");
  	return notify_fail("Tu objetivo ha muerto y no puedes embestirle.\n");
      }
  if (ENV(ob)!=ENV(me)) {
  	ob->remove_property("cabezazo");
  	return notify_fail("Tu oponente ha huido rapidamente!!\n");
      }
  return 1;
}

int efecto( string inutil, object masinutil ) {
  int mychance,itschance,j;
  object shad;

  ::efecto(inutil,masinutil);
  mychance=random(me->query_level()+me->query_con())+me->query_habilidad("cabezazo");
  itschance=ob->query_level()+ob->query_con()+ob->query_dex();
  itschance*=(100-ob->query_total_ac());
  mychance*=(300-me->query_thac0());

  if(random(mychance)>random(itschance)) {
  j = random(5)+1;
  tell_object(me, "Le das un fuerte cabezazo en el estomago, dejandolo "
  	"dolorido en suelo.\n");
  tell_room(environment(me), "Le pega un fuerte cabezazo en "
    	"el estomago, dejandolo momentaneamente aturdido.\n", ({me,ob}));
  tell_object(ob, "Te da un fuerte cabezazo en el estomago, dejandote "
  	"dolorido en el suelo.\n");
  me->adjust_ep(-15);
  ob->add_timed_property("stun_on", 1, j);
  ob->add_timed_property("nocast",1, j);
  ob->add_timed_property("noguild",1, j);
  ob->add_timed_property("passed out", "Aun te encuentras aturdido por el "
  			 "golpe de "+me->query_cap_name()+" y no puedes "
  			 "moverte.\n");
  shad = clone_object(STUN);
  shad->setup_shadow(ob, j);
  ob->add_extra_look(shad);
  ob->attack_by(me);
  ob->remove_property("cabezazo");
  if(me->query_level()<ob->query_level()) me->adjust_sp(1);
  }
  else {
  tell_object(me, ""+ob->query_cap_name()+" consigue esquivarte en el "
  	"ultimo momento!\n");
  tell_room(environment(me),"Intenta embestirle, pero no lo consigue.\n",({me,ob}));
  tell_object(ob," Intenta embestirte, pero consigues esquivarlo rapidamente.\n");
  me->adjust_ep(-15);
  ob->attack_by(me);
  ob->remove_property("cabezazo");
  return 1;
  }
 }