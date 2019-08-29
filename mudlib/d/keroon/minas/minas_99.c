// Made by Thalos  26/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual van y vienen esclavos y mineros fatigados despues de un intenso dia de trabajo dedicado a la extraccion de mineral, asi como los que van a reemplazarlos en su puesto. Ves diversos guardias encargados de mantener el orden y controlar a los esclavos, aunque estos ultimos dificilmente pueden mantenerse de pie despues de una dura jornada de trabajo. Notas una gran humedad en el ambiente proveniente de las paredes del corredor, que poco a poco va penetrandote en los huesos, haciendote comprender la dura vida del minero.""\n\n");
add_clone(NPCSMINAS+"bixos_minas.c",random(5));
add_exit("oeste",MINAS+"minas_98.c","standard");
add_exit("este",MINAS+"minas_100.c","standard");
add_exit("sur",MINAS+"minas_129.c","standard");
}
