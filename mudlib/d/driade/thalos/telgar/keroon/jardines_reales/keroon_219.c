// Made by Thalos  01/04/02
//jardines reales

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("jardines""keroon_rico");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Jardines Reales%^RESET%^");
   set_long("\n%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Jardines Reales%^RESET%^.\n\n""Estas en los jardines reales, en estos bellos jardines los duergars de clase pudientas se dedican a pasear y descansar de sus tribulaciones diarias, mientras sus hijos se dedican a jugar en las amplias avenidas. Puedes ver a varias parejas de novios andando y charlando animadamente mientras una carabina los vigila. puedes ver unas bellas escalinatas que conducen a la zona pobre de la ciudad y al este en el centro de una plazoleta una gran estatua.""\n\n");

add_exit("escaleras",KEROONPOBRE+"keroon_218.c","standard");
add_exit("norte",JARDINES+"keroon_200.c","standard");
add_exit("este",JARDINES+"keroon_220.c","standard");
add_exit("sur",JARDINES+"keroon_235.c","standard");
}
