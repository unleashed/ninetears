#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsla de Havmand : Playa\n\n"
    "   La playa de arena blanca se extiende a norte y sur, parece infinita. "
    "El profundo mar azul parece frio y refrescante, cuando miras fijamente "
    "mar adentro crees distinguir un bote en la lejania.  Hay una densa jungla "
    "hacia el oeste, aunque no encuentras ninguna forma de internarte en ella."
    "\n\n");
    add_item("bote","Esta demasiado lejos para verla con claridad, asumes "
    "que es una nave de algun pescador.\n");
    add_item("jungla","Profunda, impenetrables arboles llegan justo hasta el "
    "pie de la playa. Los troncos entrelazados unos con otros hacen "
    "imposible entrar.\n");

}
void init()
{
    add_exit("norte",HAVMAND+"b02.c","path");
    add_exit("sur",HAVMAND+"b04.c","path");

    ::init();
}

