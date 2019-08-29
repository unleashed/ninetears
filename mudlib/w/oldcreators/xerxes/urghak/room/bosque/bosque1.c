// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(0,1);
      
      set_short("%^BLACK%^BOLD%^Cerca del bosque de %^RESET%^GREEN%^Urghak%^RESET%^");
      
      add_exit("oeste", BOSQUE + "bosque2.c", "path");
      // Esta salida es cosa de Jade, ella sabra donde lleva
      add_exit("sur"  , BOSQUE + "bosque1.c", "path");
	
} /* setup */