// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sur", BOSQUE + "bosquec20.c", "path");
      add_exit("noreste", BOSQUE + "bosquec22.c", "path");
      add_exit("oeste", BOSQUE + "bosquec23.c", "path");
	
} /* setup */