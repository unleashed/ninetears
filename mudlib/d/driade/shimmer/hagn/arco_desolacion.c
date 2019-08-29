/* By Shimmer */

#include "../path.h"

inherit "/std/outside";



void setup() {
   set_zone("murallahagn");
   set_exit_color("white");
   set_light(50);
   set_short("%^BOLD%^%^WHITE%^Arco de la %^BOLD%^%^BLACK%^Desolacion%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Arco de la %^BOLD%^%^BLACK%^Desolacion%^RESET%^ : Entrada al Reino de %^BOLD%^%^CYAN%^Hagn%^RESET%^.\n\n"
   "Ahora que estas ante la gran muralla, puedes ver como se abre delante "
   "tuya lo que en su tiempo fue una inmensa puerta, entrada principal al Reino de Hagn, "
   "ahora en ruinas. Al alzar la vista te asombras ante lo que parecen los restos "
   "derruidos de un enorme portico que se alza a ambos lados de la muralla, la parte superior "
   "destruida anyos atras en una de las incontables batallas que se sucedieron en esta zona "
   "se encuentra amontonada a uno de los lados, entre los escombros puedes ver los restos "
   "de armaduras y espadas oxidadas por el paso del tiempo. Detras del Portico logras ver "
   "que el camino se bifurca entre una colina tomando direcciones opuestas, y tras la colina, "
   "a lo lejos y sobre una espesa niebla puedes divisar dos torres que se alzan majestuosas "
   "en el horizonte.\n\nGrabado sobre la roca\n\n");

add_item("arco","Son los restos del Arco de la Desolacion, puerta de entrada del Reino de Hagn, se encuentra en ruinas "
   "debido a que fue zona de ataques constantes.");

add_item("grabado","Es una especie de inscripcion grabada sobre una roca del Arco, dice lo siguiente: \n\n"
   "              Bienvenidos al Reino Olvidado de Hagn,\n"
   "     a aquel que entre en las tierras malditas, estara maldito,\n"
   "    a aquel que ose despertar a los espiritus, se le #%@�~#|@...\n"
   " ...no puedes leer el resto del mensaje ya que se encuentra rascado y es ilegible\n\n");

add_clone(NPCS+"guardian_hagn.c",2);

add_exit("noreste",HAGN+"mur2.c","standard");
add_exit("noroeste",HAGN+"mur77.c","standard");
add_exit("sur",CAMHAGN+"cam1.c","standard");

}
