// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosque193.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque191.c", "path");
	
} /* setup */