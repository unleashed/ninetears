// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("este", BOSQUE + "bosque167.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec59.c", "path");
	
} /* setup */