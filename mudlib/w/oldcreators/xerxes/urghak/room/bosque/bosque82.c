// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudeste", BOSQUE + "bosque83.c", "path");
      add_exit("noreste", BOSQUE + "bosque81.c", "path");
	
} /* setup */