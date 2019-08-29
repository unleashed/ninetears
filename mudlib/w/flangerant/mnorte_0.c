//Ciudad de Faeleen

inherit "/std/outside.c";
#include "/../../path.h"

void setup() {

   set_light(50);
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla norte");
   set_long("%^YELLOW%^Faeleen%^RESET%^: Muralla norte \n\n"
            "Esta �s la parte norte del interior de la muralla de Faeleen."
            " Desde aqui divisas las tierras del norte, con los poblados de "
            "Grandhum y Ormerod, y al oeste el inmenso oceano. Mirando atras"
            " ves la majestuosa ciudad comercial, llena de colorido y diversidad.\n");
add_item("ciudad","La ciudad de Faeleen te queda al sur, la capital del comercio.\n");
add_item("poblados","Ves al noreste el poblado de Omerod y al noroeste el de Grandhum.\n");
add_item("grandhum","Un pequenyo poblado de agricultores donde se cultiva la preciosa Preytus.\n"
add_item("omerod","Un poblado ganadero que subministra la carne a la capitan.\n");
add_exit("este","CIUDAD+"/mnorte_1.c","standard");
add_exit("sur","CIUDAD+"/mnorte_8.c","standard");
}
