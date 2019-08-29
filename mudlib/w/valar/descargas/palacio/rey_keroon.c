// Valar Febrero 2003
// Guardias del Castillo

#include "../../../path.h"

inherit "/obj/guardian.c";

void event_enter(object ob, string mess, object from) 
{
   if ((int)ob->query_timed_property("guardias_keroon"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Pensabas que podrias conmigo?.");
         ob->remove_timed_property("guardias_keroon");
      }
      else
      {
 this_object()->attack_ob(ob); 
         do_command("say A mi la guardia!!!!!!.\n");
      }
   }
::event_enter(ob, mess, from);
}

void setup()
{

   set_name("Rey Gredford VIII");
   set_short("Rey Gregford VIII");
   set_gender(1);
   set_main_plural("reyes");
   add_alias("rey");
   add_alias("gredford");
   add_plural("reyes");
   add_alias("duergar");
   set_race_ob("/std/races/duergar");
   set_guild_ob("/rol/gremios/khurgar");
   add_move_zone("palacio");
   set_wimpy(0);
   set_random_stats(17, 20);
   set_cha(12+random(6));
   set_con(17+random(3));   
   set_str(19+random(11)); /* Fuerza extrema de los duergar :) */
                           /* 19 == 18/10 .................. 29 == 19 */
   set_level(30+random(10));

   set_ciudadania("Keroon");
      
   set_long("Estas ante el rey Gredfor VIII, el comandante y rey del Reino de Keroon. "
            "Es admirado y temido por todos en el reino.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Que es lo que deseas?",
            1, ":pone la mano en su arma.",
            1, ":hace un gesto a sus guardias.",
            1, "'Guardia, acerquese!!.",
            
       }));
       
add_clone(ITEMSPALACIO +"hacha_del_caos",1);
add_clone(ITEMSPALACIO+ "coraza_negra",1);
add_clone(ITEMSPALACIO+ "yelmo_negro.c",1);
this_object()->init_equip();

  add_known_command("cabezazo");
  add_known_command("furia");
      
}/*setup*/

void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keroon", 1, 12000);
   ::attack_by(atacante);
}

void init()
{
 ::init();
 add_attack_spell(55,"cabezazo",({"/comandos/khurgar/cabezazo.c","cabezazo",0}));
 add_attack_spell(70,"furia",({"/comandos/khurgar/furia.c","furia",1}));
}
