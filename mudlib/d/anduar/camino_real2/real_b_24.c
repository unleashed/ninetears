// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, el camino traza una gran recta rodeando "
   "una colina situada al este en lo alto de la cual se ve la vegetacion "
   "tipica de Dendara, mientras que al sur se ve un gran sauce lloron.\n");
   add_exit("norte",   REAL2+"real_b_25","road");
   add_exit("sur",     REAL2+"real_b_23","road");
   set_light(65);
   crea_bichos();
}