//Editado por Oneex 2-10-97
// Quito la room de acceso a los players Aokromes Mayo 2001

inherit "std/OSO";
#include "pub.h"
#include "../path.h"

object barman,globo,tablon;

//nombre.tipo.coste.heal.volumen.intox

void setup()
{
   add_menu_item("Cerveza", ALCOHOL, 100, 2, 10, 10,
      "bebes toda la cerveza", "se bebe una jarra de Cerveza");
  
   add_menu_alias("cerveza", "Cerveza");
   
   set_short("%^GREEN%^Taberna de Anduar%^RESET%^");
   set_long(" Has entrado en la taberna mas afamada de todo Anduar."
            " Sientes el inconfundible aroma de la comida asada que reina por"
            " todo el local. Rapidamente te fijas en la barra del bar y"
            " localizas el menu de la casa. Este bar tiene un cocinero"
            " especialista en asados, si quieres comer en abundancia has"
            " venido al lugar perfecto. Acaba de instalarse un horno donde "
            "por un precio modico puede asarte trozos de carne.\n");
   
   add_exit("out", ANDUAR"ao1007.c");

   set_light(60);
   
}
