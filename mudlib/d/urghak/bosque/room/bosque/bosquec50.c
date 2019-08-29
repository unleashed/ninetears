// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec48.c", "path");
      add_exit("este", BOSQUE + "bosquec51.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec52.c", "path");
	
} /* setup */