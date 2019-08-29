// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosque137.c", "path");
      add_exit("noreste", BOSQUE + "bosque159.c", "path");
      add_exit("sudeste", BOSQUE + "bosque135.c", "path");
	
} /* setup */