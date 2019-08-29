// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque44.c", "path");
      add_exit("noreste", BOSQUE + "bosque42.c", "path");
	
} /* setup */