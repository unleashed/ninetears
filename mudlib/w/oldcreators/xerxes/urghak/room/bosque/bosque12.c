// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("norte", BOSQUE + "bosque127.c", "path");
      add_exit("sudoeste"  , BOSQUE + "bosque11.c", "path");
      add_exit("este"  , BOSQUE + "bosque13.c", "path");
	
} /* setup */