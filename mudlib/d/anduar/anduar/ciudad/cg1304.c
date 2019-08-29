// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: calle de Kheleb-dum%^RESET%^");
   set_long("Estas en la calle de Kheleb-dum en Anduar, se decidio llamar asi "
   "a esta calle por que una de sus salidas se dirige a la gran ciudad de los "
   "enanos, atravesando un gran camino. Hay un murmullo constante de la gente "
   "que pasea por las calles.\n");
   add_exit("oeste"   ,ANDUAR"cg1303.c","road");
   add_exit("este"    ,ANDUAR"cg1305.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}