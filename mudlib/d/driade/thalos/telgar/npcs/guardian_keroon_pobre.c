// Thalos
// Guardian de Keroon

#include "../path.h"

inherit "/obj/monster";

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("guardias_keroon"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Eso te pasa por ser un delincuente.");
         ob->remove_timed_property("guardias_keroon");
      }
      else
      {
 this_object()->attack_ob(ob); 
         do_command("say Eh, tu! Bastardo! Fuera de aqui!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}

void setup()
{
   object objeto;
   set_name("guardian");
   set_short("guardian");
   set_al(-100);
   set_gender(1);
   set_main_plural("guardianes");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_plural("guardianes");
   add_alias("duergar");
   set_race_ob("/std/races/duergar");
   set_guild_ob("/d/gremios/guerreros/battleduergar");
   add_move_zone("keroon_pobre");
   set_wimpy(0);
   set_random_stats(10, 18);
   set_cha(10+random(8));
   set_con(10+roll(3,3));   
   set_str(19+random(11)); /* Fuerza extrema de los duergar :) */
                           /* 19 == 18/10 .................. 29 == 19 */
   set_level(15+random(10));
   
   set_long("Es un guardian de la ciudad de Keroon. Parece fuerte, "
            "osea que no pienses mucho en atacarle. Va fijandose sin"
            " mucho entusiasmo en la gente que ronda por estas calles.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Oye, tu! Mas vale que respetes la ley!",
            1, ":se fija en ti.",
            1, ":te ensenya el filo de su hacha.",
            1, "'Oye, tu no te metas en ningun lio",
            
       }));
       
    add_clone("/d/driade/thalos/telgar/npcs/equipo/hacha_guardia",2);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/cota_guardia.c",1);
    add_clone("/d/driade/thalos/telgar/npcs/equipo/yelmo_patrulla.c",1);	
    
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keroon", 1, 600);
   ::attack_by(atacante);
}
