// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque124.c", "path");
      add_exit("sudeste", BOSQUE + "bosque126.c", "path");
      add_exit("norte", BOSQUE + "bosque132.c", "path");
      add_exit("noreste", BOSQUE + "bosque131.c", "path");
	
} /* setup */