// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque43.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque45.c", "path");
      add_exit("este", BOSQUE + "bosque170.c", "path");
	
} /* setup */