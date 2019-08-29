// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosque178.c", "path");
      add_exit("sur", BOSQUE + "bosquec55.c", "path");
	
} /* setup */