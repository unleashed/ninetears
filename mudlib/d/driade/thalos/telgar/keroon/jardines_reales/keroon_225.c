// Made by Thalos  01/04/02
//jardines reales

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("jardines""keroon_rico");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Jardines Reales%^RESET%^");
   set_long("\n%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Jardines Reales%^RESET%^.\n\n""Estas en los jardines reales, en estos bellos jardines los duergars de clase pudientas se dedican a pasear y descansar de sus tribulaciones diarias, mientras sus hijos se dedican a jugar en las amplias avenidas. Puedes ver a varias parejas de novios andando y charlando animadamente mientras una carabina los vigila. Hacia el este ves las grandes puertas que conducen al palacio de Gredfor III y al oeste en el centro de una plazoleta una gran estatua.""\n\n");
   
add_exit("oeste",JARDINES+"keroon_224.c","standard");
add_exit("norte",JARDINES+"keroon_206.c","standard");
add_exit("este",JARDINES+"keroon_226.c","standard");
add_exit("sur",JARDINES+"keroon_241.c","standard");
}
