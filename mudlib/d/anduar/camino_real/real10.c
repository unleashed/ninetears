// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Al suroeste observas las murallas "
   "de la ciudad de Anduar, con la gran torre de magia de Agband y con un "
   "gigantesco arbol que abarca toda la ciudad, uniendose con los demas "
   "arboles.");
   add_exit("noroeste"   ,REAL"real11.c","road");
   add_exit("sur"        ,REAL"real9.c","road");
   set_light(65);
   crea_bichos();
}