/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "std/room.c";

void setup() {
   
   set_light(50);
   
   set_exit_color("cyan");
   set_short("%^BOLD%^WHITE%^Colegio de Brethem%^RESET%^");
   set_long("%^BOLD%^WHITE%^Colegio de Brethem%^RESET%^\n\n"
            "Te encuentras en el colegio de la ciudad de Brethem, es un gran edificio de largos "
            "pasillos llenos de ventanas y habitaciones cargadas de mesas y sillas dispuestas en filas. "
            "Numerosos ninos y ninyas corretean de un lado para otro sin parar hacia las clases mientras "
            "algunos profesores charlan entre ellos.\n\n");

   add_item(({"mesa","mesas"}), "Pequenyas mesas de madera dispuestas en filas ocupando gran parte de la habitacion");
   add_item(({"pasillo", "pasillos"}), "Un largo pasillo con numerosas puertas que conducen a las clases.");
   add_item(({"silla", "sillas"}), "Al lado de cada mesa puedes ver una silla de madera.");
   add_item(({"ventana", "ventanas"}), "Varias ventanas por las que entra la claridad y que dan a la Calle del Miedo.");

   add_clone(BRETHEM + "npcs/profesor.c", random(3)-1);
   add_clone(BRETHEM + "npcs/ninyo.c", random(5)-1);
   add_clone(BRETHEM + "npcs/ninya.c", random(5)-1);

   

add_exit("oeste",     BRETHEM + "colegio1.c","standard");
add_exit("sur",       BRETHEM + "colegio3.c","standard");
add_exit("sudoeste",  BRETHEM + "colegio3.c","standard");


}
