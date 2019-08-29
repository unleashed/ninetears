/* A temple for raising..
 * Needs money to work...
 * Inherits /std/raiseroom.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

inherit "/std/raiseroom";

object helper;

void setup()
  {
   set_helper_name("sheedril");
  set_short("Sala de Resurrecion Ninetears");
  set_save_file(file_name(this_object()));
    set_long("\nSala de Resurrecion del Fuckin' Fic Mud.\n\n"
    "   This is the room you come to when you are dead and wish to get raised. "
    "It is a quiet, peaceful room, and in contrast to the rest of the village, "
"it has been well-maintained. The walls and floor have been freshly "
   "scrubbed, and there is a pleasant odor in the air.\n"
         "If you want to get raised, you might want to look at the"
	 " sign first. \n\n");
  set_percentage(100);
  set_light(60);

    add_smell("air","There is a pleasant smell of roses in the air.\n");
add_item("shrine", "A small altar to Hokemj sits in the corner.  There"
	" are several lit candles around the shrine, but it"
	" really doesn't attract your attention when you first"
	" enter the room. \n");
add_item(({"cot", "cots"}), "Uncomfortable looking wooden tables where the"
	" bodies are placed for examination and treatment. \n");
add_item(({"healer", "healers"}), "Stern looking individuals who spend their"
	" days raising people from the dead.  They move about the"
	" room, their movements fluid and purposeful.  They are busy"
	" people, and don't look like they smile often. \n");
  add_sign("/---------------------------------------------\\\n" 
           "|                                             |\n" 
           "|       Sala de Resurrecion del Ninetears      |\n" 
           "|                                             |\n" 
           "|  Pon raise <ghost> para revivir a alguien.  |\n" 
           "|_____________________________________________|\n" 
             "\n\n");


   add_exit("sudoeste","/room/entryroom","door");
   add_exit("noroeste","/room/meeting10","door");
}

void reset()
  {
  if (!helper)
    {
   helper = clone_object("/baseobs/monsters/healer");
    helper->move(this_object());
    }
   helper->set_name("sheedril");
   helper->set_gender(2);
   helper->set_short("sheedril");
   helper->set_long("A tall middle aged woman with dark hair and eye's "
   "of such a dark brown they appear black. She looks a little weird, but "
   "ghosts can't afford to be picky.\n");
	helper->set_max_hp(250);
	helper->set_hp(250);
	helper->load_chat(200,
            ({
              1,":esta triste porque nadie viene a visitarla ya.\n",
              1,"'Desde que pusieron el comando 'resucitar' ya casi nadie viene a verme.\n",
	      1,"'Leviathan es el Creador mas majo de todo Ninetears. Me manda muchos clientes.\n",
	      1,"'Aunque no lo creas, Enialish es un elfo un tanto renegrio.\n",
	      1,"'Se dice por ahi que Shimmer se creo un monumento a si mismo en un lejano lugar. Si pensabas que eras narcisista...\n",
	      1,"'Desde luego, pura envidia es lo que tienen esos que me llaman maruja, en realidad no hablo tanto como parece.\n",
	      1,"'Sabias que fui novia de Tyrael antes de que se reencarnase?\n",
	      1,"'Si algo odio, es lo cotilla que puede llegar a ser la gente!\n",
	      1,":coge Cinturon Prisma de Sala de Resureccion Ninetears.\n",
	      1,"'Huascar, Jerkat y Thalos me han dicho que el mes que viene no me vendra la regla... que querran decir?\n",
	      1,"'Que tiempos aquellos cuando las noches eran Thalack... Magnolia, Lamagam, Tyrael, Barth... erm, bueno, a ese lo considerabamos nuestra mascota y mira donde ha llegado!\n",
	      1,"'Si algun dia ves Khazads por estos reinos, suicidate. No valdra la pena vivir aqui.\n",
	      1,":piensa eroticamente en Jade, al tiempo que se le cae la baba.\n",
	      1,"'La culpa de que todos me querais matar no es que hable por los codos, es que envidiais a la musa del senyor.\n",
	      1,"'Si Xerxes me quisiera, me mostraria las artes de la pilleria y la magia negra, pero prefiere a su bienamado Chapulin, snif...\n",
	      1,":se frota suavemente y dice: echo holy?\n",
	      1,"'Soy el segundo npc mas antiguo del mud. Tenme un respeto, gregario de los dioses!\n",
	      1,"'Pekar o no pekar, dat's da cuestion.\n",
	      1,"'Hace mucho, muucho tiempo, existia en un lugar ya olvidado una gran guerrera que conquisto el corazon de todos los reinos. Yckull, la Experienciada Duelista, que fue, es y sera la reina y alma de los hombres lagartos.\n",
	      1,"'Sabes lo que es estar idle? Preguntale a Leviathan... si es que no esta en idle!\n",	      
            }));

   //helper->add_clone("/w/tyrael/a_espec.c", 1);
   helper->add_clone("/baseobs/weapons/pick.c", 1);
	helper->init_equip();
} /* void reset */ 

int do_raise(string str)
{
	if (str != "me") {
		notify_fail("Solo se permite el comando en la forma raise me.\n");
		return 0;
	}
/*	if (!helper) {
		notify_fail("La cleriga no esta y no puedes ser resucitado.\n");
		return 0;
	}*/
	if (this_player()->query_timed_property("nosanar")) {
		this_player()->remove_timed_property("nosanar");
	}
	return ::do_raise(str);
}

void dest_me()
  {
  if (helper)
    helper->dest_me();
   ::dest_me();
} /* void dest me */
