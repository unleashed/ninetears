// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque100.c", "path");
      add_exit("norte", BOSQUE + "bosquec21.c", "path");
	
} /* setup */