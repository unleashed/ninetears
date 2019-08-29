// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudeste", BOSQUE + "bosquec28.c", "path");
      add_exit("norte", BOSQUE + "bosquec30.c", "path");
	
} /* setup */