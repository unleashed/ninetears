// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudeste", BOSQUE + "bosque74.c", "path");
      add_exit("este", BOSQUE + "bosque72.c", "path");
	
} /* setup */