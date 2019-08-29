// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("este", BOSQUE + "bosque140.c", "path");
      add_exit("noroeste", BOSQUE + "bosque187.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque198.c", "path");
      add_exit("sudeste", BOSQUE + "bosque142.c", "path");
	
} /* setup */