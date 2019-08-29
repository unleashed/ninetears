// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque105.c", "path");
      add_exit("este", BOSQUE + "bosque108.c", "path");
      add_exit("sudeste", BOSQUE + "bosque107.c", "path");
	
} /* setup */