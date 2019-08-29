// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosquec50.c", "path");
      add_exit("este", BOSQUE + "bosquec53.c", "path");
	
} /* setup */