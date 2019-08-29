// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sur", BOSQUE + "bosque84.c", "path");
      add_exit("noroeste", BOSQUE + "bosque82.c", "path");
	
} /* setup */