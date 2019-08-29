// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sur", BOSQUE + "bosquec33.c", "path");
      add_exit("este", BOSQUE + "bosquec36.c", "path");
      add_exit("noroeste", BOSQUE + "bosquec37.c", "path");
	
} /* setup */