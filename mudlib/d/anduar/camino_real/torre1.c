// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Torreon de vigilancia del Real Camino de Anduar "
   "a Dendara%^RESET%^");
   set_long("Estas en una torre que se situa por encima del Camino Real, en "
   "la cual los guardias se reunen para recibir ordenes de sus superiores "
   "sobre los trabajos a realizar en el dia.\n");
   add_exit("abajo"   ,REAL"real9.c","road");
   set_light(65);
add_clone("/d/anduar/anduar/ciudad/npcs/guardia_torre",random(3)+1);
}
