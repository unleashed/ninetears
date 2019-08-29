// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque110.c", "path");
      add_exit("noreste", BOSQUE + "bosque191.c", "path");
      add_exit("sudeste", BOSQUE + "bosque112.c", "path");
	
} /* setup */