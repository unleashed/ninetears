// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosquec15.c", "path");
      add_exit("noreste", BOSQUE + "bosquec19.c", "path");
      add_exit("sur", BOSQUE + "bosquec18.c", "path");
      add_exit("sudoeste", BOSQUE + "bosquec17.c", "path");
	
} /* setup */