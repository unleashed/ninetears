// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"colina_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosquec39.c", "path");
      add_exit("este", BOSQUE + "bosquec38.c", "path");
      add_exit("sudeste", BOSQUE + "bosquec35.c", "path");
	
} /* setup */