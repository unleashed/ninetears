#include "/w/barthleby/path.h"

inherit "/std/outside.c";



void setup()

{
    set_short("%^YELLOW%^Taberna L'Lele%^RESET%^");
     set_long("%^YELLOW%^Taberna L'Lele%^RESET%^\n\n"+
      "La mitad de esta parte de la taberna no tiene techo alguno, cosa que se agradece en d�as " +
      "de calor, pero que no tiene tanto �xito cuando llueve. A tu alredeor puedes ver los " +
      "toneles que contienen los vinos de todas las a�adas y colores que se sirven en la " +
      "taberna. A pesar de la gran variedad de que se dispone, no tiene ninguna importancia " +
      "la elecci�n en si, pues con el tiempo te dar�s cuenta de que todos saben igual. En un " +
      "rinc�n puedes ver un cuartucho que podr�a ser un aseo.\n\n");

    set_light(70);

add_item(({"aseo","aseos","rinc�n","rincon"}),"Tan solo ves una profunda oscuridad en ese peque�o " +
        "cuarto. Lo que s� aprecias con claridad, es el tremendo olor como a bacalao podrido " +
        "que desprende. Podr�a ser que alquien se este pudriendo dentro, pero no posees el " +
        "valor suficiente como para entrar y averiguarlo.\n");

add_item("techo","El techo cubre solo la mitad de esta parte de la taberna. Aunque no solo " +
        "puedes mojarte en la que esta al aire libre, pues el resto del local tiene numerosas goteras.\n");

add_item(({"tonel","toneles"}),"Enormes toneles y barriles apliados en las paredes sirven de " +
        "contenedores para los vinos del local.\n"); 

add_exit("sudeste", PRINCIPALES+"lele1","road");
}
