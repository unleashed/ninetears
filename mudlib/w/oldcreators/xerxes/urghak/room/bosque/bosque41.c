// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noroeste", BOSQUE + "bosque42.c", "path");
      add_exit("este", BOSQUE + "bosque40.c", "path");
	
} /* setup */