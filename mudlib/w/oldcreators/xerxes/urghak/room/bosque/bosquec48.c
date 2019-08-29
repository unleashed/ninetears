// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosquec46.c", "path");
      add_exit("noreste", BOSQUE + "bosquec49.c", "path");
      add_exit("sur", BOSQUE + "bosquec50.c", "path");
	
} /* setup */