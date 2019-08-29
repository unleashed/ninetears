// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudeste", BOSQUE + "bosque122.c", "path");
      add_exit("oeste", BOSQUE + "bosquec34.c", "path");
      add_exit("norte", BOSQUE + "bosquec35.c", "path");
	
} /* setup */