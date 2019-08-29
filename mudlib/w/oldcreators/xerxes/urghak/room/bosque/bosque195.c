// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque194.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque193.c", "path");
      add_exit("norte", BOSQUE + "bosque196.c", "path");
	
} /* setup */