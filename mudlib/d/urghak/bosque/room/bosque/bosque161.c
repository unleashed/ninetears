// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosque163.c", "path");
      add_exit("este", BOSQUE + "bosque162.c", "path");
      add_exit("sur", BOSQUE + "bosque160.c", "path");
	
} /* setup */