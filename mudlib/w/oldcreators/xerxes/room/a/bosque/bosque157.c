// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque156.c", "path");
      add_exit("oeste", BOSQUE + "bosque158.c", "path");
      add_exit("sudeste", BOSQUE + "bosquec43.c", "path");
	
} /* setup */