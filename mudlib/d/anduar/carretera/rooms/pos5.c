//Ampliacion del Hostal de Comellas
//Aokromes Julio'99

inherit "/std/room";
#include "pub.h"
#include "../../path.h"

void setup()
{
   
   set_short("%^YELLOW%^Establos Hostal Comellas%^RESET%^");
   set_long("Estas en los establos del Hostal Comellas. Parece ser que la "
   "limpieza de las monturas es total, ya que no se huele nada desagradable, "
   "cada montura tiene su propio comedero en el cual puede comer despues de "
   "un fatigante viaje para llevar a su amo a su destino, y tiene sitio "
   "suficiente para tumbarse a descansar para quedar refrescado para seguir "
   "su camino.\n");
   add_exit("oeste", COMELLAS+"pos4");
   set_light(60);
   
   add_clone(NPCS+"caballo.c",5);
}