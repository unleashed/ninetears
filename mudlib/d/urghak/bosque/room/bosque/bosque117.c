// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec28.c", "path");
      add_exit("oeste", BOSQUE + "bosque116.c", "path");
      add_exit("sudeste", BOSQUE + "bosque118.c", "path");
	
} /* setup */