// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosquec5.c", "path");
      add_exit("oeste", BOSQUE + "bosquec9.c", "path");
      add_exit("sur", BOSQUE + "bosquec8.c", "path");
	
} /* setup */