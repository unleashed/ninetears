#include "/w/barthleby/path.h"

inherit "/std/room.c";

void setup()

{
    set_short("%^BOLD%^%^BLACK%^Iaurgond, hogar de los heruditos de Noella%^RESET%^");
     set_long("%^BOLD%^%^BLACK%^Iaurgond, hogar de los heruditos de Noella%^RESET%^\n\n"+
      "Es uno de los edificios m�s antiguos de toda la ciudad, lleva aqu� desde tiempos " +
      "inmemoriales y hace tiempo fue habilitado como lugar de estudio para los sabios de la " +
      "ciudad y los procedentes de otros lugares. Consta de tres gigantescas habitaciones con " +
      "cientos de estanter�as repletas de libros. De vez en cuando llenan de asientos alguna " +
      "de ellas para utilizarla de escuela. Los m�s jovenes de la ciudad sienten un profundo " +
      "odio y temor hacia este lugar.\n\n");

    set_light(70);

add_item(({"estanter�a","estanter�as","estanteria","estanterias"}),"Grandes y carcomidas estanter�as de madera repletas " +
        "de libros polvorientos est�n presentes por toda la habitaci�n.\n");

add_item(({"libro","libros"}),"Viejos y polvorientos libros aparentemente bien clasificados, " +
        "recogen los conocimientos que vienen a adquirir aqu� los sabios del lugar.\n");

add_exit("oeste", PRINCIPALES+"iaurgond2","road");
add_exit("fuera", CALLE+"calle6","road");
}

