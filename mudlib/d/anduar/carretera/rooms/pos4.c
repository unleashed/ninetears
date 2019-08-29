//Ampliacion del Hostal de Comellas
//Aokromes Julio'99

inherit "/std/outside";
#include "pub.h"
#include "../../path.h"

void setup()
{
   
   set_short("%^YELLOW%^Patio del Hostal Comellas%^RESET%^");
   set_long("Estas en el patio del Hostal Comellas. Hacia el sur se entra en "
   "la posada mientras que hacia el este estan las caballerizas, una gran "
   "puerta asegura la salida hacia el norte evitando que nadie entre en la "
   "posada si el duenyo no quiere y un mozo se encarga de limpiarlo para que "
   "ningun huesped pise nada que no sea de su agrado.\n");
   add_exit("sur", COMELLAS+"pos");
   add_exit("este", COMELLAS+"pos5");
   add_exit("fuera", REAL+"real8");
   set_light(60);
   
   add_clone(NPCS+"mozo.c",1);
}