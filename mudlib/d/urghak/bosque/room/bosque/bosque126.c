// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudeste", BOSQUE + "bosque10.c", "path");
      add_exit("noroeste", BOSQUE + "bosque125.c", "path");
	
} /* setup */