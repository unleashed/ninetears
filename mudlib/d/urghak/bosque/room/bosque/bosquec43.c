// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosque157.c", "path");
      add_exit("este", BOSQUE + "bosquec44.c", "path");
	
} /* setup */