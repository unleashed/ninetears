// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque62.c", "path");
      add_exit("sudeste", BOSQUE + "bosquec12.c", "path");
	
} /* setup */