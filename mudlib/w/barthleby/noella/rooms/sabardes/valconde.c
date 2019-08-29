#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^BOLD%^Fuente de D'Val-Cond%^RESET%^");
     set_long("%^BOLD%^Fuente de D'Val-Cond%^RESET%^\n\n"+
      "Te encuentras en un lugar frecuentemente visitado por los habitantes de la " +
      "zona, que vienen aqu� en busca del agua m�s fresca y cristalina de la regi�n. " +
      "El viento hace que algunas gotas, producidas por el agua de la fuente al caer " +
      "al estanque, te salpiquen la cara. Tambi�n oyes el silvido de los �rboles que " +
      "te rodean, fruto del jugueteo del aire con sus ramas.\n\n");

    set_light(50);

add_item("fuente","De entre un grupo de tres grandes piedras, surge un agua helada y " +
        "cristalina que abastece el peque�o estanque.\n");

add_item("estanque","Unas cuantas rocas forman una figura ovalada que retiene el " +
        "agua procediente de la fuente. Una gran losa inclinada hacia el agua es " +
        "utilizada por algunos campesinos del lugar para frotar sus ropas cuando " +
        "vienen a lavar aqu�.\n");

add_item(({"arbol", "arboles", "�rbol", "�rboles"}),"Unos altos �rboles de espeso follaje rodean la zona, " +
        "a la vez que danzan azotados por el fuerte viento de poniente que sopla " +
        "con especial fuerza en este lugar.\n");

add_sound("silvido","Te detienes un instante a escuchar el sonido que produce el viento al balancear " +
        "las ramas de los �rboles cercanos.\n");

add_exit("noroeste",  COUTO+"couto11","road");
add_exit("norte",  BREIX+"breix3","road");
add_exit("noreste",  BREIX+"breix4","road");
add_exit("sudoeste",  BREIX+"breix5","road");
}
