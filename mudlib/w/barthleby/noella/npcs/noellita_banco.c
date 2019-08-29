//Noellita del banco

#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Ciudadano");
   set_short("ciudadano");
   set_al(-100);
   set_gender(1);
   set_main_plural("ciudadanos");
   add_alias("human");
   add_alias("humano");
   add_plural("noellitas");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(12, 16);
   set_cha(12+random(5));
   set_level(3+random(5));
   set_long("Parece un ciudadano normal y corriente, por lo visto va a ingresar"
            " sus beneficios.\n");

   set_aggressive(0);
   load_chat(15,
      ({
            1, "'Mmmmm, tal vez debiera hacerme ladr�n como el banquero.",
            1, "'Esperemos que no se ponga a llover."
       }));

   adjust_money(random(40), "silver");

   add_clone(Arma+"daga",1);
   add_clone(ARMADURA+"manto",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_noella", 1, 300);
   ::attack_by(atacante);
}/*attack_by*/
