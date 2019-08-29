// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("este", BOSQUE + "bosquec21.c", "path");
      add_exit("norte", BOSQUE + "bosquec25.c", "path");
      add_exit("oeste", BOSQUE + "bosquec24.c", "path");
	
} /* setup */
