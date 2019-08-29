// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque58.c", "path");
      add_exit("sudeste", BOSQUE + "bosque56.c", "path");
	
} /* setup */