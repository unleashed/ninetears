// Aokromes
#include "../path.h"
inherit ANDUAR+"rica.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Kheleb-Dum%^RESET%^");
   set_long("Estas en la calle de Kheleb-dum en Anduar, se decidio llamar asi "
   "a esta calle por que una de sus salidas se dirige a la gran ciudad de los "
   "enanos, atravesando un gran camino. Hay un murmullo constante de la gente "
   "que pasea por las calles.\n");
   add_exit("oeste"   ,ANDUAR"cg1315.c","road");
   add_exit("este"    ,ANDUAR"cg1317.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
