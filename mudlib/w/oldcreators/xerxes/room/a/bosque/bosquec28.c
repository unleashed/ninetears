// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sur", BOSQUE + "bosque117.c", "path");
      add_exit("noroeste", BOSQUE + "bosquec29.c", "path");
	
} /* setup */