// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("oeste", BOSQUE + "bosque181.c", "path");
      add_exit("este", BOSQUE + "bosque179.c", "path");
	
} /* setup */