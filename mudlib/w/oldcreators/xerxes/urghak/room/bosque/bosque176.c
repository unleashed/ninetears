// Xerxes '02

#include "../../path.h"

inherit BOSQUE+"bosque_main.c";

void setup()
{
      do_desc(1,1);
      
      add_exit("sudoeste", BOSQUE + "bosque178.c", "path");
      // La room 177 no existe por error en mapeado a mano xD
      add_exit("norte", BOSQUE + "bosque175.c", "path");
	
} /* setup */