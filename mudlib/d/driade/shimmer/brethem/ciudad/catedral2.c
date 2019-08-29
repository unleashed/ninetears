/* By Shimmer */

#define CREATOR "shimmer"

#include "money.h"

#include "../../path.h"

//inherit BRETHEM+"cityroom.c";
inherit "std/sacroom.c";


void setup() {

   set_light(80);

   set_exit_color("white");
   set_short("%^BOLD%^CYAN%^Catedral de Brethem : Sala de Oracion%^RESET%^");
   set_long("%^BOLD%^CYAN%^Catedral de Brethem : Sala de Oracion%^RESET%^\n\n"
            "Esta es la sala en la que los sacerdotes se reunen para rezar y orar, es una sala amplia y bastante "
            "acogedora, una gran alfombra cubre el suelo en el que los sacerdotes se arrodillan para rezar. Aqui "
            "todos guardan silencio y no puedes escuchar mas que el murmullo de algunos sacerdotes rezando cerca de ti.\n\n");

   add_item("alfombra","Es una gran alfombra de varios colores colocada a lo largo de toda la sala.\n");
   add_item(({"pared","paredes"}),"Las amplias paredes estan decoradas con telas y frescos que te maravillan la vista, "
       "todos ellos con dibujos de deidades y criaturas.\n");
   add_item("suelo","El suelo esta cubierto por una gran alfombra.\n");
   


   add_clone(BRETHEM+"npcs/sacerdote.c",random(6)+2);  

add_exit("este",          BRETHEM + "catedral1.c","standard");



}



