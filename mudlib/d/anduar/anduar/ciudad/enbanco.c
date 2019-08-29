// Aokromes
#include "../path.h"
inherit "/std/room";

object segurata;

void setup()
{
   set_short("Hall del banco");
   set_long("Unas hermosas columnas jalonan la entrada del banco, por "
        "todos lados, maderas y piedras nobles, estrategicamente colocadas "
        "para hacer mas comoda la espera de los clientes, y colgando del "
        "techo una inmensa lampara de aranya, la cual tiene aspecto de ser "
        "muy cara, da la impresion de que el que la romperia tendria que "
        "estar pagandola el resto de su vida.\n");
  add_exit("noreste"   ,ANDUAR"banco.c","road");
   add_exit("oeste"     ,ANDUAR"cruce1619.c","road");
set_light(50);
   set_zone("anduar");
}

void reset()
{
   if(!segurata)
   {
       segurata=clone_object(ANDUAR+"npcs/segurata",1);
       segurata->move(this_object());
   }
}
