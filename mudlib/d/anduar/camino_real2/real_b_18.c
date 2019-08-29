// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino se dirige al norte bordeando "
   "una gran roca de material granitico, hay una desgastada figura en los "
   "bordes de la calzada, por su aspecto llevara muchisimo tiempo hay, "
   "olvidada.\n");
   add_exit("norte",   REAL2+"real_b_19","road");
   add_exit("sur",     REAL2+"real_b_17","road");
   set_light(65);
   add_item("figura","Una desgastada figura de Oskuro supremo dios del mal "     
   "parece mirar al sur, a una torre que apenas se divisa en las coligas de "
   "Ostigurth.");
   crea_bichos();
}
