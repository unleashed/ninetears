/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

//inherit BRETHEM+"cityroom.c";
inherit "/std/room.c";      /* no me vale la otra por que esta pa outsides */
int j, n;
void setup() {
   

   set_exit_color("white");
   set_short("%^BOLD%^WHITE%^Ayuntamiento de Brethem : %^BOLD%^YELLOW%^Despacho del Alcalde%^RESET%^");
   set_long("%^BOLD%^WHITE%^Ayuntamiento de Brethem : %^BOLD%^YELLOW%^Despacho del Alcalde%^RESET%^\n\n"
            "Este es el despacho principal del Alcade de Brethem, una mesa grande y redonda ocupa el "
            "centro de la sala, en las paredes puedes ver colgados numerosos retratos de nobles y reyes, "
            "posiblemente antiguos gobernantes y alcaldes de la ciudad. Una enorme silla antigua de "
            "madera con ribetes de oro preside la gran mesa, detras puedes ver algunos concejales charlando y "
            "al fondo de todo varios estandartes con escudos de casas nobles bordados en su tela. Es un lugar "
            "bastante acogedor e importante, ya que aqui se toman la mayoria de decisiones que afectan a la ciudad.\n\n");


    add_clone(BRETHEM+"npcs/guardia.c",1);
    add_clone(BRETHEM+"npcs/alcalde_theod.c",1);
    add_clone(BRETHEM+"npcs/concejal.c",random(3));
   

add_exit("fuera",     BRETHEM + "ayunta4.c","standard");


}
