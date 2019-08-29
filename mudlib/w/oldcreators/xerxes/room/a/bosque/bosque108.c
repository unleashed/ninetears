// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque106.c", "path");
      add_exit("sur", BOSQUE + "bosque107.c", "path");
      add_exit("norte", BOSQUE + "bosque109.c", "path");
	
} /* setup */