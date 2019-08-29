// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque51.c", "path");
      add_exit("este", BOSQUE + "bosque49.c", "path");
	
} /* setup */