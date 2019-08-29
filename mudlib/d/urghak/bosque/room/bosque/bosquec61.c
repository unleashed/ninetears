// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("este", BOSQUE + "bosquec60.c", "path");
      add_exit("sur", BOSQUE + "bosquec62.c", "path");
	
} /* setup */