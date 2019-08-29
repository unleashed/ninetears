// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosquec3.c", "path");
      add_exit("noreste", BOSQUE + "bosquec1.c", "path");
      add_exit("sudeste", BOSQUE + "bosquec4.c", "path");
	
} /* setup */