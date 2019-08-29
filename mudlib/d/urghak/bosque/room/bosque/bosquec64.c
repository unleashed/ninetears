// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosquec62.c", "path");
      add_exit("sur", BOSQUE + "bosquec66.c", "path");
      add_exit("este", BOSQUE + "bosquec65.c", "path");
	
} /* setup */