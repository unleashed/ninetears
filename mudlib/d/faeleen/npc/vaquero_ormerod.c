inherit "/obj/monster";
#include "../path.h"
#define TIEMPO 100

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("vaqueros_ormerod"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Eso te pasa por matar animales.");
         ob->remove_timed_property("vaqueros_ormerod");
      }
      else
      {
 this_object()->attack_ob(ob); /* viendo los abusos contra los tenderos, meto de nuevo que ataquen, en caso de que ataquen a nobles y/o tenderos */
         do_command("say Eh, tu! Deja a los animales!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}


void setup() {
set_name("Vaquero");
set_short("vaquero");
add_alias("vaquero");
add_plural("vaqueros");
set_gender(1);
set_main_plural("vaqueros");
set_str(20);
set_con(40);
set_dex(18);
set_int(18);
set_wis(18);
set_cha(18);
set_long("Este es uno de los vaqueros que controlan los pastos. \n");
add_clone("/baseobs/armaduras/cuero_endurecido.c",1);
add_clone("/baseobs/armas/baston.c",1);
add_clone("/baseobs/armaduras/manto.c",1);
add_clone("/baseobs/armaduras/brazaletes.c",1);
add_clone("/d/faeleen/obj/camisa_ormerod.c",1);
add_clone("/d/faeleen/obj/pantalon_ormerod.c",1);
init_equip();
add_move_zone("pastos_ormerod");
set_move_after(13,5);
set_level(25+random(10));
set_heart_beat(2);
set_thac0(-50);
set_aggressive(0);
}

void attack_by(object atacante)
{
   atacante->add_timed_property("vaqueros_ormerod", 1, TIEMPO);
   ::attack_by(atacante);
}