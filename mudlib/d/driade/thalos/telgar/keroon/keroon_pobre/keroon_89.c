// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de la resurrecion%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle de los resurreccion%^RESET%^.\n\n""Estas en la calle de los resurreccion,en la zona pobre de Keroon, esta calle esta mas limpia y cuidada de lo que resulta habitual por esta zona, esto es debido sin duda al clerigo que vive en ella, a un lado puedes observar a un grupo de duergars haciendo cola para visitar al clerigo.""\n\n");
add_item(({"cola"}),"Ves a varios duergars guardando cola pacientemente turno  a la espera de ser atendidos por el clerigo.\n"); 
add_clone(NPCS+"bixos_keroon_pobre2.c",random(5)); 
add_exit("norte",KEROONPOBRE+"keroon_76.c","standard");
add_exit("sur",KEROONPOBRE+"keroon_110.c","standard");
}
