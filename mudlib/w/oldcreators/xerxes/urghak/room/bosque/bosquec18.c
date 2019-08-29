// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec16.c", "path");
      add_exit("noroeste", BOSQUE + "bosquec15.c", "path");
      add_exit("oeste", BOSQUE + "bosquec17.c", "path");
	
} /* setup */