// Made by Thalos  26/03/02

inherit "/std/underground";
#include "vagoneta.h"

void setup() {

   set_zone("minas");
   set_exit_color("yellow");
   set_light(20);
   set_short("%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^");
   set_long("\n%^BOLD%^YELLOW%^Minas de Keeroon%^RESET%^.\n\n""Te encuentras en un amplio pasillo de la mina, por el cual van y vienen esclavos y mineros fatigados despues de un intenso dia de trabajo dedicado a la extraccion de mineral, asi como los que van a reemplazarlos en su puesto. Ves diversos guardias encargados de mantener el orden y controlar a los esclavos, aunque estos ultimos dificilmente pueden mantenerse de pie despues de una dura jornada de trabajo. Notas una gran humedad en el ambiente proveniente de las paredes del corredor, que poco a poco va penetrandote en los huesos, haciendote comprender la dura vida del minero. Unas railes surcan el suelo para que pasen las vagonetas""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas.\n"); 
add_clone(NPCS+"bixos_minas.c",random(5));
add_exit("oeste",MINAS+"minas_95.c","standard");
add_exit("noreste",MINAS+"minas_85.c","standard");
add_exit("este",MINAS+"minas_97.c","standard");
add_exit("sur",MINAS+"minas_126.c","standard");
add_exit("sudoeste",MINAS+"minas_125.c","standard");
}
