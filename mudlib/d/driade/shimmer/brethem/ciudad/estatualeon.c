/* By Shimmer */

#define CREATOR "shimmer";

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   add_smell("jardin", "Un olor fresco y humedo de flores te imprenga cuando te paras a respirar profundamente.\n");
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Estatua del %^YELLOW%^Leon%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Estatua del %^YELLOW%^Leon%^RESET%^\n\n"
       "Te escuentras una gran plaza totalmente adoquinada, a tu alrededor puedes ver unos pequenyos jardines "
       "y en el centro, alta e imponente se alza una gran estatua de un leon apoyado sobre sus patas "
       "traseras y elevando amenazantemente su pata delantera derecha mostrando sus afiladas garras. "
       "Al mirar alrededor puedes ver como varias calles confluyen en la plaza, al oeste la que llega del centro "
       "ciudad, al sur la que se dirige hacia el puerto y al este dos que salen de la ciudad en direcciones opuestas.\n\n");

   add_item(({"estatua", "leon"}) , "Estatua del Leon.\n\nUna gran estatua dorada de un enorme leon, esta estatua fue construida hace "
            "cientos de anyos por los primeros habitantes de Brethem, y su funcion era la de atemorizar a los "
            "posibles seres y alimanyas que se pudieran acercar a la ciudad, con el paso del tiempo la "
            "ciudad crecio y la estatua paso a decorar la gran plaza en la que te encuentras.\n");
   add_item(({"adoquin", "adoquines", "suelo", "plaza"}), "La plaza se encuentra totalmente adoquinada, su suelo lo forman miles de "
            "pequenyas piedras engarzadas unas con otras formando vistosos dibujos.\n");
   add_item(({"jardin", "jardines"}), "Varios pequenyos jardines rodean la estatua decorando la plaza.\n");

   crea_npcs();
   add_clone(BRETHEM+"npcs/guardia",1);

add_exit("oeste",    BRETHEM + "gen1.c","standard");
add_exit("sur",      BRETHEM + "mar0.c","standard");
add_exit("noreste",  BRETHEM + "av_harak1.c","standard");
add_exit("sudeste",  BRETHEM + "av_este1.c","standard");

}
