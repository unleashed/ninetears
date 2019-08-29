// Made by Thalos  01/04/02
// Posada

inherit "std/pub";
#include "pub.h"
#include "../../path.h"

object globo, tablon, barman;


//nombre.tipo.coste.heal.volumen.intox
void setup(){
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^Taberna: El enano desmembrado");
   set_long(" Has entrado en una de las tabernas de la zona pobre de keroon."
            " Sientes el inconfundible aroma de los vomitos  y otros efluvios"
            " que los borrachos han dejado por todo el local. Rapidamente te"
            " fijas en la barra del bar y localizas el menu de la casa.\n");
   add_item("barra",
      " Por esta barra han pasado mas bebidas en un dia que todas "
      " las que has podido beber en tu vida.\n");    
   
   add_menu_item("Cerveza", ALCOHOL, 1067, 2, 10, 20,
      "bebes toda la cerveza", "se bebe una jarra de Cerveza");
   add_menu_item("Aguardiente duergar", ALCOHOL, 2135, 3, 5, 50,
      "bebes un vaso de aguardiente duergar, *buurrrrp*", "se bebe un vaso de licor");
   add_menu_item("Muerte instantanea", ALCOHOL, 1602, 4, 5, 90,
     "bebes un vasito de Muerte instantanea","se bebe un vasito de licor");
   add_menu_item("Agua", SOFTDRINK, 5338, 1, 5, 0,
     "bebes un verdoso vaso de agua","se bebe un verdoso vaso de agua");
   add_menu_item("Patatas picantes", FOOD, 2669, 15, 100, 0,
  "comes unas insipidas patatas picantes","se come un plato de patatas picantes");
   add_menu_item("Ensaladilla a la duergar", FOOD, 4004, 35, 100, 0,
   "comes una en saladilla a la duergar, Ummm!",
   "se come una ensaladilla a la duergar");
   add_menu_item("Asado de algo", FOOD, 1335, 5, 100, 0,
  "comes un asado de algun tipo de carne","se come un asado de algo");
  
   add_menu_alias("cerveza", "Cerveza");
      
   add_menu_alias("aguardiente", "Aguardiente duergar");
   add_menu_alias("aguardiente duergar", "Aguardiente duergar");
   
   add_menu_alias("muerte", "Muerte instantanea");
   add_menu_alias("muerte instantanea", "Muerte instantanea");
   
   add_menu_alias("agua", "Agua");
   
   add_menu_alias("patatas", "Patatas picantes");
   add_menu_alias("patatas picantes", "Patatas picantes");
   
   add_menu_alias("ensaladilla", "Ensaladilla a la duergar");
   add_menu_alias("ensaladillaa la duergar", "Ensaladilla a la duergar");
   
   add_menu_alias("asado", "Asado de algo");
   add_menu_alias("asadode algo", "Asado de algo");
   
add_exit("este",KEROONPOBRE+"keroon_23.c","standard");
add_exit("fuera",KEROONPOBRE+"keroon_38.c","standard");

}

void reset()
{
  if (!barman)
  {
   barman= clone_object("NPCS+"tremdor.c");
   barman->move(this_object());
  } 
}
