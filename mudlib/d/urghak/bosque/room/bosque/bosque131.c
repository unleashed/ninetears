// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque125.c", "path");
      add_exit("norte", BOSQUE + "bosque130.c", "path");
	
} /* setup */