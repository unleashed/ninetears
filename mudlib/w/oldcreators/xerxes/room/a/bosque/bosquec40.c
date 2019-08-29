// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque185.c", "path");
      add_exit("oeste", BOSQUE + "bosquec41.c", "path");
      add_exit("sur", BOSQUE + "bosquec42.c", "path");
	
} /* setup */