// Noble del banco

#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("noble");
   set_short("noble");
   set_al(-100);
   set_gender(random(2));
   set_main_plural("nobles");
   add_alias("human");
   add_alias("humano");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(10, 14);
   set_level(2+random(3));   
   set_long("Es un noble. Por su vestimenta deduces que es una persona rica. "
            "Est� en la cola esperando su turno como todos.\n");

   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Cuanto habr� obtenido de intereses hoy?",
            1, ":se frota las manos.",
       }));

   adjust_money(random(5), "platinum");
   add_clone(ARMADURA+"capa",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_noella", 1, 300);
   ::attack_by(atacante);
}/*attack_by*/
