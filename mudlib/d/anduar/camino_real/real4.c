// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, la calzada parece seguir "
   "dirigiendose al norte, la vegetacion aqui parece alejarse de la calzada "
   "y el camino se eleva sobre un pronunciado desnivel que los encargados de "
   "construir el camino parecen haber solucionado de forma muy habil.\n");
   add_exit("norte"   ,REAL+"real5.c","road");
   add_exit("southwest"   ,REAL+"real3.c","road");
   set_light(65);
   crea_bichos();
}