// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosquec58.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec60.c", "path");
	
} /* setup */