#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Torreta de Vigilancia%^RESET%^");
   set_long("   Te encuentras en una de las torretas de vigilancia recien "
   "construidas por los nobles que habitan en Anduar, ya que ultimamente "
   "esta ciudad esta muy concurrida por todo tipo de razas, y la seguridad "
   "ha decaido bastante.\n "
   "Regentada cada una por un par de Guardias, hace que la misma ciudad este "
   "un poco mas protegida de cualquier tipo de ataque. "
   "La torreta tiene un techo hecho de piedra, y unas endiduras en la pared "
   "que sirven para que los guardias puedan observar a la gente sin temor a "
   "ser atacados.\n");
   
   add_item("techo","Es un techo redondo, y la piedra es mas dura que la "
   "cabeza de un enano!");
   add_item("ventana","Bueno, si se le puede decir ventana, es la pared en "
   "si, que tiene un agujero de un palmo de ancho para poder ver a los "
   "transeuntes");
   add_exit("abajo"   ,ANDUAR"cruce2501","road");
set_light(50);
   add_clone("/d/anduar/anduar/ciudad/npcs/guardia_torre.c",2);
   }
