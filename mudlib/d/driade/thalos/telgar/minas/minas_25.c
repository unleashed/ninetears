// Made by Thalos  26/03/02

inherit "/std/underground";
#include "vagoneta.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual discurren unos railes destinados a la circulacion de las vagonetas que trasportan los minerales y piedras preciosas extraidos del interior de las minas. Observas como en este punto de la galeria hay un tope y finalizan los railes, puesto que la estructura del corredor no permite su continuacion, al menos por el momento, puesto que observas diversos railes sueltos apoyados en la pared. Una vagoneta permanece aqui parada mientras diversos esclavos y mineros duergars acarrean el mineral extraido en el fondo de la galeria y lo tiran al interior de la vagoneta.""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas.\n"); 
add_exit("oeste",MINAS+"minas_24.c","standard");
add_exit("sudeste",MINAS+"minas_34.c","standard");
}
