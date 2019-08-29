inherit "/obj/monster";

void setup()
  {
  set_race("monster");
  switch(random(3))
  {
    case 0:
      set_name("mujer");
      set_short("Mujer");
      set_long("Es una habitante de Rongrond, es de estatura media, ojos claros y pelo oscuro, tiene un aire "
	  "de campesina, sus ropajes no son lujosos por lo que observamos que es de una familia de econom�a media.\n");
      add_alias("mujer");
      set_main_plural("mujeres");
      add_plural("mujeres");
      set_gender(1);
	  load_chat(20,
            ({
              1,":te mira de reojo.",
              1,"'donde estara mi ninyo?",
             }));
      set_level(10+random(3));
      break;
    case 1:
      set_name("ninyo");
      set_short("Ninyo");
      set_long("Es un ninyo pequenyo, est� correteando por las calles, y jugando con los amigos, tiene los "
	  "rasgos marcados a pesar de su corta edad, sus ropajes son normales, ni pobres ni lujosos.\n");
      add_alias("ninyo");
      set_main_plural("ninyos");
      add_plural("ninyos");
      set_gender(2);
	   load_chat(20,
            ({
              1,":juega con los amigos",
              1,"'alguien ha visto a mi mama?",
             }));
      set_level(5+random(2));
      break;
    case 2:
      set_name("perro");
      set_short("Perro");
      set_long("Es un perro pequenyo y flaco, no parece estar muy hambriento y descuidado.\n");
      set_main_plural("perros");
	  add_plural("perros");
      set_gender(2);
	  load_chat(20,
            ({
              1,":te ladra.",
			}));
      set_level(3+random(5));
      break;
	case 3:
      set_name("gato");
      set_short("Gato");
      set_long("Es un gato callejero.\n");
      set_main_plural("gatos");
	  add_plural("gatos");
      set_gender(2);
	  load_chat(20,
            ({
              1,":ronronea",
		     }));
      set_level(3+random(5));
      break;
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
} /* setup */


#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 