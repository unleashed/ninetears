// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque171.c", "path");
      add_exit("este", BOSQUE + "bosque173.c", "path");
      add_exit("sudoeste", BOSQUE + "bosque174.c", "path");
	
} /* setup */