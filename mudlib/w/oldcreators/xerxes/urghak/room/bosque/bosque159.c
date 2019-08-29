// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque136.c", "path");
      add_exit("noreste", BOSQUE + "bosque158.c", "path");
	
} /* setup */