inherit "/std/room.c";
#include config.h
#include path.h
void setup() { 
set_short(HERRERIATITLE);

  set_long(HERRERIATITLE+"\n"
	"     Aqui va la cutredescripcion de la herreria. \n");

   set_light(0);
   add_exit("norte",ROOMS+"herreria.c","door");
return(0);
}
