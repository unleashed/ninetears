// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, A lo lejos al sur observas como la "
   "gran calzada entra en la gran urbe llamada Anduar, segun las narraciones "
   "de los trobadores la primera ciudad de los humanos");
   add_exit("noroeste"   ,REAL"real32.c","road");
   add_exit("este"     ,REAL"real30.c","road");
   set_light(65);
   crea_bichos();
}