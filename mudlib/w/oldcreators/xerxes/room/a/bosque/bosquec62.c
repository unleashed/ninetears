// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec61.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec63.c", "path");
      add_exit("este", BOSQUE + "bosquec64.c", "path");
	
} /* setup */