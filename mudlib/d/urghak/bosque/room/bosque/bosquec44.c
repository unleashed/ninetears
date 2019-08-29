// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosquec43.c", "path");
      add_exit("sudeste", BOSQUE + "bosquec45.c", "path");
	
} /* setup */