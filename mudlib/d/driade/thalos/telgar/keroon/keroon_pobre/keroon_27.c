// Made by Thalos  01/04/02
// Posada

inherit "std/OSO";
inherit "/std/underground";
#include "../../path.h"
object barman
//nombre.tipo.coste.heal.volumen.intox
void setup()
{
   add_menu_item("Corazon de enano", ALCOHOL, 250, 2, 10, 10,
      "bebes todo el vaso de golpe", "se bebe todo el vaso de golpe");
   add_menu_item("Aguardiente duergar", ALCOHOL, 300, 3, 5, 30,
      "bebes un vaso de aguardiente duergar, *buurrrrp*", "se bebe un vaso de licor");
   add_menu_item("Dama Blanca", SOFTDRINK, 450, 4, 5, 50,
     "bebes un vasito de Dama Blanca","se bebe un vasito de licor");
   add_menu_item("Agua", SOFTDRINK, 700, 1, 5, 0,
     "bebes un verdoso vaso de agua","se bebe un verdoso vaso de agua");
   add_menu_item("Mazagran", SOFTDRINK, 400, 4, 5, 50,
     "bebes un chupito de Mazagran","se bebe un chupito de licor");
   add_menu_item("Patatas bravas", FOOD, 1125, 15, 100, 0,
  "comes unas insipidas patatas bravas","se come un plato de patatas bravas");
   add_menu_item("Montadito de lomo", FOOD, 2625, 35, 100, 0,
   "comes un montadito de lomo, Ummm!",
   "se come un montadito de lomo");
   add_menu_item("Anchoas", FOOD, 225, 5, 100, 0,
  "comes anchoas, uffff esto da sed","se come unas anchoas");
  
   add_menu_alias("corazon", "corazon de enano");
   add_menu_alias("aguardiente", "aguardiente duergar");
   add_menu_alias("dama", "dama blanca");
   add_menu_alias("agua", "Agua");
   add_menu_alias("mazagran", "Mazagran");
   add_menu_alias("patatas", "Patatas picantes");
   add_menu_alias("Ensaladilla", "Ensaladilla a la duergar");
   add_menu_alias("asado", "Asado de algo");
   
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^Taberna: El duergar feliz");
   set_long(" Has entrado en una de las tabernas de la zona pobre de keroon."
            " Sientes el inconfundible aroma de los vomitos  y otros efluvios
            " que los borrachos han dejado por todo el local. Rapidamente te
            " fijas en la barra del bar y localizas el menu de la casa.\n");
   add_item("barra",
      " Por esta barra han pasado mas bebidas en un dia que todas "
      " las que has podido beber en tu vida.\n");    

add_exit("este",KEROONPOBRE+"keroon_23.c","standard");
add_exit("fuera",KEROONPOBRE+"keroon_38.c","standard");

set_open_condition("BARMAN");
}

int BARMAN()
{
  object *lista;
  int i;
  if (!barman) return 0;

  lista=barman->query_attacker_list();
  for(i=0;i<sizeof(lista);i++)
   if (environment(lista[i])==this_object()) return 0;
  return 1;
}               
   
 void reset()
{
  ::reset();
  if (!barman)
  {
    barman=new(NPC+"bizuddulin.c");
    barman->move(this_object());
  } 
}

void dest_me()
{
 if (barman) 
    barman->dest_me();
 ::dest_me();
}


