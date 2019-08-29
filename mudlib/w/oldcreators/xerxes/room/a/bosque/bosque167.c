// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sur", BOSQUE + "bosque165.c", "path");
      add_exit("oeste", BOSQUE + "bosquec58.c", "path");
      add_exit("norte", BOSQUE + "bosque168.c", "path");
	
} /* setup */