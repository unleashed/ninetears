// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("noreste", BOSQUE + "bosque50.c", "path");
      add_exit("oeste", BOSQUE + "bosque52.c", "path");
      add_exit("sur", BOSQUE + "bosquec1.c", "path");
	
} /* setup */