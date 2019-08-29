/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"


inherit BRETHEM+"pub";

#include "pub.h"

object barman;

mixed top_list, top_deaths;
void add_to_list(object ob);

object barman;





void setup() {
   set_light(80);
   set_exit_color("cyan");
   set_short("%^BOLD%^RED%^Taberna de Peph de Noella%^RESET%^");
   set_long("%^BOLD%^RED%^Taberna de Peph de Noella%^RESET%^\n\n"
            "Te encuentras en una taberna pequenya y estrecha, unas cuantas mesas con sillas "
            "alrededor forman el lugar ideal para tomarse un descanso y recuperar fuerzas. A la "
            "derecha, tras la barra, puedes ver a Peph de Noella, el tabernero, ocupado en sus "
            "labores atendiendo a los clientes y limpiando las mesas sin dejar de moverse.\n\n");  


   add_item("barra",
      " Por esta barra han pasado mas bebidas en un dia que todas "
      " las que has podido beber en tu vida.\n");   



   add_menu_item("Cerveza de Noella", ALCOHOL, 20, 2, 10, 10,
      "te bebes tu cerveza de un trago", "se bebe la cerveza de un trago y sin pestanyear");

   add_menu_item("Jarabe de la Casa", ALCOHOL, 100, 3, 50, 50,
      "bebes una jarra de jarabe hecho en la propia taberna", "se bebe una jarra de jarabe de la casa");

   add_menu_item("Whisky de Malta", ALCOHOL, 300, 6, 100, 100,
      "sientes un escalofrio mientras te bajas la copa de whisky", "bebe una copa de whisky" );

   add_menu_item("Aguardiente de Enanos", ALCOHOL, 900, 15, 350, 350,
      "te estremeces de arriba abajo al tragar un chupito de este"+
	" aguardiente tan fuerte, te arde la garganta", 
      "se bebe un chupito de aguardiente y su rostro se vuelve palido y "+
	"comienza a echar humo");

   add_menu_item("Vino Elfico", ALCOHOL, 900,15,350,345,"bebes"+
	" un trago de la jarra de vino", "se bebe un trago de la jarra de vino");

   add_menu_item("Alas de Murcielago", FOOD, 50, 1, 20, 0,
      "te comes unas crujientes alas de murcielago", "se come unas alas de murcielago");

   add_menu_item("Tostadas de Musgo", FOOD, 100, 2, 40, 0,
      "te comes una deliciosa tostada de musgo", "se come una tostada.");

   add_menu_item("Patatas Braseadas", FOOD, 200, 4, 100, 0,
      "te comes unas cuantas patatas a la brasa", "se come unas cuantas patatas a la brasa");



   add_menu_alias("cerveza", "Cerveza de Noella");
   add_menu_alias("noella", "Cerveza de Noella");
   add_menu_alias("cerveza de noella", "Cerveza de Noella");

   add_menu_alias("jarabe", "Jarabe de la Casa");
   add_menu_alias("jarabe de la casa", "Jarabe de la Casa");

   add_menu_alias("aguardiente de enanos", "Aguardiente de Enanos");
   add_menu_alias("aguardiente", "Aguardiente de Enanos");

   add_menu_alias("whisky", "Whisky de Malta");
   add_menu_alias("malta", "Whisky de Malta");
   add_menu_alias("whisky de malta", "Whisky de Malta");

   add_menu_alias("vino", "Vino Elfico");
   add_menu_alias("vino elfico", "Vino Elfico");

   add_menu_alias("alas", "Alas de Murcielago");
   add_menu_alias("alas de murcielago", "Alas de Murcielago");

   add_menu_alias("tostadas", "Tostadas de Musgo");
   add_menu_alias("tostadas de musgo", "Tostadas de Musgo");

   add_menu_alias("patatas", "Patatas Braseadas");
   add_menu_alias("patatas braseadas", "Patatas Braseadas");


   set_co_ord( ({ -3, -4, 0 }) );

   set_open_condition("PANADERO");



   add_clone(BRETHEM+"npcs/ciudadano",random(3));
   add_clone(BRETHEM+"npcs/noble",random(2));
   

add_exit("fuera",    BRETHEM + "castros3.c","standard");


}


void init() {
  ::init();
  add_action("buy", "comer");
  add_action("buy", "tomar");
  add_action("buy", "jalar");
  add_action("buy", "comprar");
  add_action("do_read","read");
}






void reset()
{
   ::reset();
   if (!barman)
   {
      barman=new(BRETHEM+"npcs/peph");
      barman->move(this_object());
   }
}

void dest_me()
{
   if (barman) barman->dest_me();
   ::dest_me();
}

int PANADERO()
{  
   object *Pelea;
   int i;
   if(!barman) return 0; 
   else{ 
         Pelea=barman->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(barman))
          return 0;
   } 
   return 1;
}

