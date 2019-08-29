// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosquec26.c", "path");
      add_exit("oeste", BOSQUE + "bosque95.c", "path");
      add_exit("sudeste", BOSQUE + "bosque97.c", "path");
	
} /* setup */