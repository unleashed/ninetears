/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

//inherit BRETHEM+"cityroom.c";
inherit "/std/room.c";      /* no me vale la otra por que esta pa outsides */
int j, n;
void setup() {
   

   set_exit_color("white");
   set_short("%^BOLD%^WHITE%^Ayuntamiento de Brethem%^RESET%^");
   set_long("%^BOLD%^WHITE%^Ayuntamiento de Brethem%^RESET%^\n\n"
            "Te encuentras en las dependencias interiores del Ayuntamiento, las paredes estan decoradas con "
            "grandes cuadros y telas maravillosas con bordados de oro. A tu alrededor puedes ver ciudadanos "
            "esperando a ser atendidos en las distintas ventanillas que hay en la sala, en algunas se forman largas "
            "filas. Los concejales vienen y van cargados de documentos y papeles que pasan de unas manos a otras "
            "rapidamente. Aqui todo el mundo parece agobiado, trabajando sin cesar para llevar por buen camino "
            "tanto el trabajo que entra como la propia direccion de la ciudad, de la que se encargan aqui\n\n");

    add_clone(BRETHEM+"npcs/guardia.c",1);

   n=random(6);
   for (j=0; j<n; j++)
   {
      switch (random(8))
      {
         case 0: add_clone(BRETHEM+"npcs/concejal", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/noble", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/concejal", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/noble", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/concejal", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/noble", 1);
                 break;
      }
    }


add_exit("sudeste",     BRETHEM + "ayunta1.c","standard");
add_exit("este",        BRETHEM + "ayunta3.c","standard");
add_exit("dentro",      BRETHEM + "sala_alcalde.c","standard");

}
