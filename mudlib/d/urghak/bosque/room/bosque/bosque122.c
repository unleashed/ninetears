// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque121.c", "path");
      add_exit("sudeste", BOSQUE + "bosque123.c", "path");
      add_exit("noroeste", BOSQUE + "bosquec33.c", "path");
	
} /* setup */