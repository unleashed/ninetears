// Thalos
// Guardian de Keroon

#include "../../../path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("chulo");
   set_short("chulo");
   set_al(-100);
   set_gender(1);
   set_main_plural("chulos");
   add_alias("chulo");
   add_alias("proxeneta");
   add_plural("chulos");
   add_plural("proxenetas");
   add_alias("duergar");
   set_race_ob("/std/races/duergar");
   set_guild_ob("/d/gremios/guerreros/battleduergar");
   add_move_zone("parque");
   set_move_after(8,10);
   adjust_money(20,"oro");
   set_wimpy(0);
   set_random_stats(10, 18);
   set_cha(10+random(8));
   set_con(10+roll(3,3));   
   set_str(19+random(11)); /* Fuerza extrema de los duergar :) */
                           /* 19 == 18/10 .................. 29 == 19 */
   set_level(15+random(10));
   
   set_long("Es un chulo que se encarga de vigilar a un grupo de prostitutas y quedarse con parte de sus ganacias por su proteccion. Ten cuidado es muy peligroso.\n");         
   
   set_aggressive(0);
   load_chat(50,
         ({
               1, "'No te metas con las chatas o lo lamentaras.",
               1, ":observa todos tus movimientos.",
               1, ":pasa su lengua por el filo de su arma.",
               1, "'Si no vas a usar el genero no lo toques.",
               1, "'Si no quieres nada, no me distraigas a las chatas, que estan trabajando.",
         }));
   load_a_chat(30, ({
        1, "'Has, atacado a una de mis chicas moriras.",
        1, "'Te crees muy valiente atacando a una mujer, verdad?",
        1, "'Hacia tiempo que no me divertia tanto."        
      }));
       
    add_clone(ITEMSPARQUE+"navaja.c",1);
    add_clone(ITEMSPARQUE+"cota.c",1);
    add_clone(ITEMSPARQUE+"punyo.c",1);
    add_clone(ITEMSPARQUE+"anillo.c",1);
    add_clone(ITEMSPARQUE+"botas.c",1);
    add_clone(ITEMSPARQUE+"cadena.c",1);
    add_clone(ITEMSPARQUE+"capa_zorro.c",1);
    add_clone(ITEMSPARQUE+"cinturon.c",1);
    add_clone(ITEMSPARQUE+"guantes.c",1);
    add_clone(ITEMSPARQUE+"pantalones.c",1);
    ::init_equip();
}

/* Si atacas a una puta su chulo la defiende*/ 

void event_enter(object ob, string mess, string mensaje, object donde)
{

if ((int)ob->query_timed_property("chulo"))
   {
      if (ob->query_dead())
      {
         do_command("speak common");
         do_command("'Ya tienes lo que querias?, y la proxima vez tu muerte sera lenta y dolorosa, me he "
                    "quedado con tu cara...");
         ob->remove_timed_property("chulo");
      }
      else
      {
 this_object()->attack_ob(ob); 
         do_command("speak common");
         do_command("say Eh, tu! no quiero lios con mis putas !! Lo pagaras con tu vida  !!!!!!.\n");
      }
   }
   
   ::event_enter(ob, mensaje, donde);

}


void attack_by(object atacante)
{
   atacante->add_timed_property("chulo", 1, 600);
   ::attack_by(atacante);

}          