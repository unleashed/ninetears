/* By Shimmer */

#define CREATOR "shimmer"

#include "money.h"

#include "../../path.h"

//inherit BRETHEM+"cityroom.c";
inherit "std/sacroom.c";


void setup() {

   set_light(80);

   set_exit_color("white");
   set_short("%^BOLD%^CYAN%^Catedral de Brethem%^RESET%^");
   set_long("%^BOLD%^CYAN%^Catedral de Brethem%^RESET%^\n\n"
            "Varias columnas enormes de fino y reluciente marmol blanco soportan una enorme boveda, las paredes de "
            "roca gris estan cubiertas por incontables retales y adornos con motivos de distintas deidades. Puedes "
            "ver como entra la luz por los grandes ventanales de cristal decorado con muchos colores y esta se "
            "refleja en el blanco suelo tambien de marmol produciendo extranyas formas. En gran altar situado en "
            "el centro de la sala soporta algunas estatuillas y libros antiguos..\n\n");

   add_item("altar","Sobre dos bajos pilares de roca, puedes ver una losa grande de marmol adornada con un retal "
            "bordado en varios colores con inscripciones en una lengua que desconoces. Es el altar de sacrificios.\n");
   add_item(({"pared","paredes"}),"Las amplias paredes estan decoradas con telas y frescos que te maravillan la vista, "
       "todos ellos con dibujos de deidades y criaturas.\n");
   add_item("suelo","El suelo esta formado pos grandes losas de marmol blanco.\n");
   add_item("estatuillas","Varias estatuillas de piedra representando algunas deidades.\n");   
   add_item("libros","Algunos libros viejos de oraciones que estan en una lengua que desconoces.\n");  

   add_clone(BRETHEM+"npcs/sacerdote.c",random(2));  
   add_clone(BRETHEM+"npcs/eanur.c",1);  

add_exit("norte",          BRETHEM + "resucitar.c","standard");
add_exit("oeste",          BRETHEM + "catedral2.c","standard");
add_exit("fuera",          BRETHEM + "plaza_catedral.c","standard");



}



