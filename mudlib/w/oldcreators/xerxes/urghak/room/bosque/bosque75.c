// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque76.c", "path");
      add_exit("norte", BOSQUE + "bosque74.c", "path");
	
} /* setup */