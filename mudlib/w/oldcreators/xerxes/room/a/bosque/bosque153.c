// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque154.c", "path");
      add_exit("este", BOSQUE + "bosque152.c", "path");
      add_exit("noroeste", BOSQUE + "bosque160.c", "path");
	
} /* setup */