// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosque17.c", "path");
      add_exit("sudoeste"  , BOSQUE + "bosque15.c", "path");
	
} /* setup */