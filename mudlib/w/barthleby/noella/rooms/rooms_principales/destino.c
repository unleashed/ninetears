#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^BOLD%^Plaza del Destino%^RESET%^");
     set_long("%^BOLD%^Plaza del Destino%^RESET%^\n\n"+
      "A �ste lugar vienen a ser ahorcados los condenados a muerte de la ciudad. Hay " +
      "una plataforma de madera en el medio de la plaza destinada a tal fin. Las piedras " +
      "del suelo de distintos tama�os, formas y tonalidades est�n clavadas en la tierra " +
      "formando un mosaico que representa la Rosa de los Vientos, que es el principio " +
      "del Paseo de Suleithel.\n\n");

    set_light(70);

add_item("plataforma","Una plataforma de madera de dos metros de alto y cuatro metros " +
        "cuadrados de ancho, se alza en medio de la plaza recordando a delincuentes en " +
        "potencia cual puede llegar a ser su destino en funci�n de sus actos.\n");

add_item(({"piedras","suelo"}),"El mosaico formado por las piedras del suelo representa una " +
        "Rosa de los Vientos de unos cinco o seis metros de diametro.\n");

add_clone(NPC+"crea_ciudadanos", 9);
add_clone(NPC+"guardia_noella", 3);

add_exit("oeste", PARQUES+"carcha2","road");
add_exit("noroeste", PARQUES+"suleithel8","road");
add_exit("norte", PARQUES+"suleithel9","road");
add_exit("dentro", PRINCIPALES+"trono1","road");
set_zone("parques");

}

