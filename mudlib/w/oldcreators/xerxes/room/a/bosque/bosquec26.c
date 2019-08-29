// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque96.c", "path");
      add_exit("norte", BOSQUE + "bosquec27.c", "path");
	
} /* setup */