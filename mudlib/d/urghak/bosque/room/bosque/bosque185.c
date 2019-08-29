// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque184.c", "path");
      add_exit("sudeste", BOSQUE + "bosque186.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec40.c", "path");
	
} /* setup */