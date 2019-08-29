// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("este", BOSQUE + "bosque155.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque157.c", "path");
	
} /* setup */