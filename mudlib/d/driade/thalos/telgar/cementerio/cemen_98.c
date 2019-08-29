// Made by Thalos  25/03/02

inherit "/std/underground";
#include "../path.h"

void setup() {

   set_zone("cementerio");
   set_exit_color("white");
   set_light(20);
   set_short("%^BOLD%^Cementerio abandonado%^RESET%^");
   set_long("\n%^BOLD%^Cementerio abandonado%^RESET%^.\n\n""Te encuentras en un cementerio abandonado, un escalofrio te recorre toda la columna vertebral, por todos lados ves lapidas rotas y tumbas abiertas, despojadas de cualquier resto que pudieran contener. No cabe la menor duda de que el lugar se halla maldito por algun fuerza desconocida""\n\n");
add_item(({"lapida","lapidas"}),"Puedes ver una lapida de marmol desgastada por el paso del tiempo, pertida en varios trozos, cualquier intento de leer lo que ponia resulta infructuoso\n");
add_item(({"tumba","tumbas"}),"Nos es mas que un simple hueco en la pared de piedra del tamanyo suficiente para que quepa el cuerpo de un duergar, mirando mas de cerca solo ves unos pocos jirones de  ropa\n"); 
add_clone(NPCSCEMENTERIO+"bixos_cementerio.c",random(5));
add_exit("norte",CEMENTERIO+"cemen_90.c","standard");
add_exit("sur",CEMENTERIO+"cemen_113.c","standard");
}
