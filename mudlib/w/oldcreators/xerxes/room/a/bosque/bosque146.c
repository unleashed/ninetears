// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosque145.c", "path");
      add_exit("sur", BOSQUE + "bosque147.c", "path");
	
} /* setup */