// Valar Febrero 2003
// Guardias del Castillo

#include "../../../path.h"

inherit "/obj/civil.c";

void event_enter(object ob, string mess, object from) 
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
::event_enter(ob, mess, from);
}

void setup()
{

   set_name("guardia");
   set_short("guardia");
   set_gender(1);
   set_main_plural("guardias");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_plural("guardianes");
   add_alias("duergar");
   set_race("/std/races/duergar");
   set_guild("/rol/gremios/khurgar");
   add_move_zone("palacio");
   set_wimpy(0);
   set_random_stats(17, 19);
   set_cha(12+random(6));
   set_con(10+roll(3,3));   
   set_str(19+random(11)); /* Fuerza extrema de los duergar :) */
                           /* 19 == 18/10 .................. 29 == 19 */
   set_level(25+random(10));

   set_ciudadania("Keroon");
      
   set_long("Es el guardia del castillo de Keroon. Solo la elite de keroon, "
            "puede llegar a un puesto tan prestigioso como este.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Tu cara me suena de algo. No seras un criminal?!",
            1, ":se fija en ti.",
            1, ":te ensenya el filo de su hacha.",
            1, "'Ni se te ocurra armar jaleo en este castillo.",
            
       }));
       
add_clone(ITEMSKEROONPOBRE +"hacha_guardia",2);
add_clone(ITEMSKEROONPOBRE+ "cota_guardia.c",1);
add_clone(ITEMSKEROONPOBRE+ "yelmo_patrulla.c",1);

  add_known_command("cabezazo");
  add_known_command("furia");
      
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
   do_command("protect rey");
   atacante->add_timed_property("guardias_keroon", 1, 12000);
   ::attack_by(atacante);
}

void init()
{
 ::init();
 add_attack_spell(55,"cabezazo",({"/comandos/khurgar/cabezazo.c","cabezazo",0}));
 add_attack_spell(70,"furia",({"/comandos/khurgar/furia.c","furia",1}));
}

