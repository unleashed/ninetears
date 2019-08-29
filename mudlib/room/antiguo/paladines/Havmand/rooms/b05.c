#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsla de Havmand : Playa\n\n"
    "   La fina arena blanca de la playa termina aqui. Mas al sur puedes ver "
    "rocas que sobresalen entre las olas y puedes ver un sendero entre la jungla. "
    "Mientras observas la zona, ves un pequenyo molusco desaparecer en la arena. "
    " Una suave brisa marina te arremolina los cabellos. "
    "\n\n");
    add_item(({"roca","rocas"}),"Cortantes rocas volcanicas, si piensas explorar "
    "por esa zona deberias tener cuidado.\n");
    add_item("molusco","Algun tipo de animal con una concha, desaparece antes de "
    "que puedas examinarle con detalle.\n");
    add_feel("brisa","Una agradable y suave brisa marina.\n");

}
void init()
{
    add_exit("norte",HAVMAND+"b04.c","path");
    add_exit("sur",HAVMAND+"r02.c","path");
    add_exit("oeste",HAVMAND+"j22.c","path");

    ::init();
}
