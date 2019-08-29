// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec15.c", "path");
      add_exit("noreste", BOSQUE + "bosquec16.c", "path");
      add_exit("este", BOSQUE + "bosquec18.c", "path");
	
} /* setup */