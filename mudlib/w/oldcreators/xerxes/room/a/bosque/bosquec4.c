// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosquec2.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec5.c", "path");
	
} /* setup */