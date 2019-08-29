// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosquec32.c", "path");
      add_exit("norte", BOSQUE + "bosquec31.c", "path");
      add_exit("sur", BOSQUE + "bosquec29.c", "path");
	
} /* setup */