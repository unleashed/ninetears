// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque36.c", "path");
      add_exit("noreste", BOSQUE + "bosque34.c", "path");
	
} /* setup */