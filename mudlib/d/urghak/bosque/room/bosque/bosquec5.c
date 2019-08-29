// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosquec4.c", "path");
      add_exit("este", BOSQUE + "bosquec6.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec7.c", "path");
	
} /* setup */