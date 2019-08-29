// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque130.c", "path");
      add_exit("sudeste", BOSQUE + "bosque128.c", "path");
	
} /* setup */