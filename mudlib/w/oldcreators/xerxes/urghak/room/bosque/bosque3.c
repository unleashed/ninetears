// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(0,1);
      
      set_short("%^BLACK%^BOLD%^Cerca del bosque de %^RESET%^GREEN%^Urghak%^RESET%^");
      
      add_exit("norte", BOSQUE + "bosque4.c", "path");
      add_exit("sudeste"  , BOSQUE + "bosque2.c", "path");
	
} /* setup */