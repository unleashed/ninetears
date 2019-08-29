#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^YELLOW%^Puente en construcci�n%^RESET%^");
     set_long("%^YELLOW%^Puente en construcci�n%^RESET%^\n\n"+
      "Est�s en la parte sur del futuro puente ideado para descongestionar el tr�fico del " +
      "Puente de Traba. Por su reducida anchura deduces que este ser� un paso destinado " +
      "a transportes ligeros.\n\n");

    set_light(70);

add_item(({"puente", "Puente"}),"Tal y como se esta construyendo esta parte del puente, no " +
            "te da la impresi�n de que sea lo suficientemente robusto como para soportar las " +
            "arroyadoras aguas que lleva el r�o en �poca de lluvias. \n");

add_item(({"rio", "r�o", "Trabasir"}),"El Trabasir, un no muy ancho pero si hermoso r�o " +
        "con abundante pesca, en el que algunos j�venes ba�istas se dejan ver " +
        "durante los d�as m�s calientes del a�o. \n");

add_exit("sudeste", COUTO+"couto14","road");
set_zone("sendas");

}


