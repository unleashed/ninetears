// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosquec45.c", "path");
      add_exit("norte", BOSQUE + "bosquec47.c", "path");
      add_exit("este", BOSQUE + "bosquec48.c", "path");
	
} /* setup */