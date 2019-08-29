// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque148.c", "path");
      add_exit("norte", BOSQUE + "bosque27.c", "path");
      add_exit("sudeste", BOSQUE + "bosque25.c", "path");
	
} /* setup */