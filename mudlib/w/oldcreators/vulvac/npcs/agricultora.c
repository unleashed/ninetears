
#include "path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Agricultora");
   set_short("agricultora");
   add_alias("agricultora");
   set_al(0);
   set_gender(random(2)+1);
   set_main_plural("agricultoras");
   add_plural("agricultoras");
   set_race_ob("/std/races/duergar");
   set_random_stats(10, 14);
   set_cha(10+random(4));
   set_level(6+random(4));     
   set_long("Este es uno de los agricultores de la zona. Es un fuerte y fornido duergar. Estos agricultores se dedican a recolectar los hongos y liquenes de la zona.\n\n\n");                                                                                                                                                      
   adjust_money(random(15), "silver");
   
            
   set_aggressive(0);
   load_chat(10,
      ({
            1, "'Has visto a unos ninyos por aqui??",
            1, "'Tenemos que trabajar duro para poder dar de comer a nuestros hijos.",
       }));
       
   objeto=new("/w/vulvac/armas/daga_curva.c");
   objeto->move(this_object());
   objeto=new("/w/vulvac/armaduras/capa.c");
   objeto->move(this_object());
   this_object()->init_equip();
}/*setup*/
