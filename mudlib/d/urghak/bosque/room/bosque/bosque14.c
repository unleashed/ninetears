// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque15.c", "path");
      add_exit("oeste"  , BOSQUE + "bosque13.c", "path");
	
} /* setup */