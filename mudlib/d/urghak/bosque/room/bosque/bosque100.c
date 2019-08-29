// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque99.c", "path");
      add_exit("noreste", BOSQUE + "bosquec20.c", "path");
      add_exit("sudeste", BOSQUE + "bosque101.c", "path");
	
} /* setup */