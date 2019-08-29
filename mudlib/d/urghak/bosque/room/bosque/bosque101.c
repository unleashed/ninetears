// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosque100.c", "path");
      add_exit("este", BOSQUE + "bosque103.c", "path");
	
} /* setup */