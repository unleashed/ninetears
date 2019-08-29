// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sur", BOSQUE + "bosque108.c", "path");
      add_exit("este", BOSQUE + "bosque110.c", "path");
	
} /* setup */