#include "../path.h"
 inherit "/obj/monster";
 
 void setup() 
{
       set_name("agricultora");
       set_race("human");
       set_short("agricultora de Grandhum");
       set_main_plural("agricultoras");
       add_plural("agricultoras");
       set_level(2+random(5));
       set_wimpy(0);
       set_random_stats(9, 15);
       set_str(15);
       set_gender(2);
set_long(
          "Agricultora de Grandhum\n"
    "\n\n Ves a una senyorita de raza humana trabajando en el campo,"
    " por la cara le notas disgustada por la vida que le esta tocando pasar"
     ". Ella esta sucia y despeinada\n\n");
       
       adjust_money(random(5),"plata");
       load_chat(30,
          ({
           1,"'Estoy harta de trabajar en el campo, cuando ire a telar ?.\n",
           1,"@resopla.\n",
         }));

    add_clone(OBJ+"rastrillo.c",1);
       init_equip();
 
 } 