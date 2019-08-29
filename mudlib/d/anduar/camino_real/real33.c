// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En esta zona la calzada se eleva "
   "sobre unos pilares habilmente dispuestos para evitar una cienaga que "
   "parece poder tragar cualquier cosa.");
   add_item("cienaga","Es una cienaga que aparenta ser muy profunda, "
   "cualquier resbalon puede resultar fatal");
   add_exit("noroeste"   ,REAL"real34.c","road");
   add_exit("southeast"     ,REAL"real32.c","road");
   set_light(65);
   crea_bichos();
}