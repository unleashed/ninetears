// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Plaza del patibulo%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Plaza del patibulo%^RESET%^.\n\n""Estas en una plaza de la zona pobre de Keroon, la plaza del patibulo es una de la mas famosas debido a que es la unica que proporciona un poco de diversion y entretenimiento a la poblacion. Es una plaza mas o menos cuadrada donde caben unos mil duergars, con varias gradas de piedra y  un entarimado en el centro donde se puede apreciar un patibulo y varios cepos donde se poen a los criminales dependiendo del castigo que vayan a padecer.""\n\n");
add_item(({"patibulo"}),"Es un patibulo construido de piedra y con varias sogas dispuestas para colgar a varios criminales al mismo tiempo, a un lado suyo ves la palanca que acciona la trampilla del suelo permitendo que la muerte por asfixia de los condenados.\n"); 
add_item(({"palanca"}),"Es la palanca que acciona el verdugo, a la orden del rey para abrir la trampilla del patibulo.\n"); 
add_item(({"grada","gradas"}),"Son unas gradas de piedras donde los nobles y el rey con su sequito pueden sentarse mientras ven las ejecuciones.\n"); 
add_item(({"cepo","cepos"}),"Son un cepo que aprisiona la cabeza del criminal y sus manos impidiendole cualquier movimiento, la gente aprovecha esto para lanzarles cosas.\n"); 
add_clone(NPCSKEROONPOBRE+"bixos_keroon_pobre2.c",random(5)); 
add_exit("sudoeste",KEROONPOBRE+"keroon_449.c","standard");
}
