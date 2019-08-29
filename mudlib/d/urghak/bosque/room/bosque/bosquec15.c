// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosquec13.c", "path");
      add_exit("este", BOSQUE + "bosquec16.c", "path");
      add_exit("sur", BOSQUE + "bosquec17.c", "path");
      add_exit("sudeste", BOSQUE + "bosquec18.c", "path");
	
} /* setup */