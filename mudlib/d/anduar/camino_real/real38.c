// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Desde aqui sobre la masa arborea de "
   "Orgoth observas la asombrosa ciudad elfica, construida totalmente sobre "
   "las ramas del mismo, de una amplitud tal que nadie lo ha explorado "
   "totalmente, por lo cual el bosque puede contener mas secretos escondidos, "
   "en espera a ser encontrados, bien por la casualidad, bien por el "
   "desastre.");
   add_exit("norte"   ,REAL"real39.c","road");
   add_exit("southeast"     ,REAL"real37.c","road");
   set_light(65);
   crea_bichos();
}