#include "path.h"

inherit "/std/underground.c";

void setup()
{
   set_short("%^BLACK%^BOLD%^Gruta del descanso%^RESET%^");

   set_long("Acabas de entrar en la gruta secreta de la zona. Muy bien por tu parte si lo has descubierto sin hacer"
		" ningun more. En esta sala no hay nada resenyable. Solo esta para ensenyarte a hacer habitaciones secretas"
		" y como encontrarlas. Intenta salir de aqui con logica.\n");

   set_light(10);

   add_exit("arriba",APRENDICES+"pasillo_2","hidden");   

}

void init()
{
 ::init();
 add_action("trampa",({"go","goback","goto","dest","home","ed"}));
}

int trampa()
{
 write("Tramposillo tramposillo...que te he pillao.....\n");
 return 1;
}


