// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque44.c", "path");
      add_exit("sudeste", BOSQUE + "bosque171.c", "path");
	
} /* setup */