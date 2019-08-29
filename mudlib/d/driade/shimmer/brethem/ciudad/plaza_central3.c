/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("white");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^CYAN%^Plaza del Ayuntamiento%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^CYAN%^Plaza del Ayuntamiento%^RESET%^\n\n"
            "Una gran plaza de forma cuadrangular se abre ante ti, en el centro de la misma puedes ver "
            "un gran arbol rodeado de una alta verja de metal, alrededor hay algunos bancos con ciudadanos "
            "que se entretienen charlando. Al norte de la plaza puedes ver un enorme edificio acristalado, "
            "ciudadanos nobles, concejales y chupatintas vienen y van continuamente del edificio, te encuentras "
            "ante el Ayuntamiento de Brethem, en el centro mismo de la ciudad.\n\n");

/*    add_item("arbol", "Un enorme arbol custodia la plaza desde el centro de la misma. Sus ramas son fuertes y "
             "anchas y su corteza esta muy arrugada debido a su edad milenaria. Es uno de los simbolos "
             "mas importantes y queridos de la ciudad, ya que lleva ahi desde el nacimiento de la misma, "
             "creciendo a la par que esta. No creo que te gustase saber lo que le hacen a los que lo maltratan. ");
   */ add_item("verja", "Una alta verja de metal dorado rodea al arbol para que la gente y los animales no puedan "
             "acercarse a este y maltratarlo.");
     
    add_clone(BRETHEM+"items/arbol1.c",1);
    add_clone(BRETHEM+"npcs/guardia.c",1);

 //  crea_npcs_ayuntamiento();

add_exit("este",         BRETHEM + "plaza_central2.c","standard");
add_exit("sur",          BRETHEM + "castros5.c","standard");
add_exit("ayuntamiento", BRETHEM + "ayunta1.c.c","standard");









}
