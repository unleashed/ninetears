// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec54.c", "path");
      add_exit("este", BOSQUE + "bosquec57.c", "path");
      add_exit("sur", BOSQUE + "bosquec56.c", "path");
	
} /* setup */