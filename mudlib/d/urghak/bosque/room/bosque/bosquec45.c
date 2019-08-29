// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosquec44.c", "path");
      add_exit("noreste", BOSQUE + "bosquec46.c", "path");
	
} /* setup */