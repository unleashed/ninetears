// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque101.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque102.c", "path");
      add_exit("noreste", BOSQUE + "bosque104.c", "path");
	
} /* setup */