// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosque141.c", "path");
      add_exit("sur", BOSQUE + "bosque143.c", "path");
	
} /* setup */