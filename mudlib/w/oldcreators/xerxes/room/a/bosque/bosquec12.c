// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosquec11.c", "path");
      add_exit("este", BOSQUE + "bosquec13.c", "path");
      add_exit("sur", BOSQUE + "bosquec14.c", "path");
	
} /* setup */