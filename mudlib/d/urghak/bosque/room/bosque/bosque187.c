// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosque186.c", "path");
      add_exit("sudeste", BOSQUE + "bosque141.c", "path");
	
} /* setup */