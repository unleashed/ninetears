#include "/w/barthleby/path.h"

inherit BASE"OSO.c";



mixed top_list, top_deaths;
void add_to_list(object ob);

object barman, *clientela;
int init=0, clientes=0;

void setup()

{


    set_short("%^YELLOW%^Taberna L'Lele%^RESET%^");
     set_long("%^YELLOW%^Taberna L'Lele%^RESET%^\n\n"+
      "Bienvenido a la taberna L'Lele, un lugar de esparcimiento al que hay que hacer una " +
      "menci�n especial debido a la popularidad que ha llegado a adquirir dentro y fuera de " +
      "la ciudad. Un lugar que hasta los m�s ancianos recuerdan medio derruido y con goteras " +
      "desde siempre. Algunos dicen que desde su apertura, la taberna no ha sufrido ninguna " +
      "reforma interior o exterior. A primera vista siempre resulta un lugar repugnante, pero " +
      "solo es cuestion de acostumbrarse. Los precios de sus vinos son su mejor baza, tiene " +
      "blancos, tintos, rosados, jovenes... pero entre todos ellos no alcanzan el precio de " +
      "uno solo de los servidos en otros lugares.\n\n");

    set_light(70);

add_item("barra", "Una larga barra de madera bastante sucia y mojada con restos de bebidas.\n");

   add_menu_item("TumbaDios", ALCOHOL, 1, 0, 100, 1000,
      "sientes ganas de vomitar mientras te bajas un TumbaDios",
        "casi vomita el TumbaDios que se acaba de beber" );
   add_menu_item("Pseudo-Cerveza de Noella", ALCOHOL, 10, 2, 10, 10,
      "te bebes tu cerveza de un trago",
        "se bebe la cerveza de un trago y sin pesta�ear");
   add_menu_item("Pseudo-Aguardiente de Enanos", ALCOHOL, 450, 15, 350, 350,
      "te estremeces de arriba abajo al tragar un chupito de este aguardiente tan fuerte, te arde la garganta",
        "se bebe un chupito de aguardiente y su rostro se vuelve p�lido y comienza a echar humo");
   add_menu_item("Pseudo-Vino �lfico", ALCOHOL, 450,15,350,345,
      "bebes un trago de la jarra de vino",
	"se bebe un trago de la jarra de vino");
   add_menu_item("Alas de Murci�lago", FOOD, 25, 2, 20, 0,
      "te comes unas crujientes alas de murci�lago",
        "se come unas alas de murci�lago");
   add_menu_item("Patatas Braseadas", FOOD, 100, 4, 100, 0,
      "te comes unas cuantas patatas a la brasa",
        "se come unas cuantas patatas a la brasa");
   add_menu_item("Costillas de Cordero", FOOD, 225, 10, 100, 0,
      "comes unsa jugosas costillas",
        "se come unas costillas de cordero");
   add_menu_item("Asado de Pollo", FOOD, 1025, 20, 100, 0,
      "comes un delicioso pollo asado",
        "se come un muslo de pollo");
   add_menu_item("Asado de Ciervo", FOOD, 1600, 25, 100, 0,
      "comes un trozo asado de ciervo",
        "se come un trozo asado de ciervo");
   add_menu_item("Asado de Jabal�", FOOD, 2225, 40, 100, 0,
      "comes una sabrosa pata de jabal� asada, Ummm!",
        "se come las costillas asadas de jabal�");

   add_menu_alias("tumba", "TumbaDios");
   add_menu_alias("Tumba", "TumbaDios");
   add_menu_alias("tumbadios", "TumbaDios");
   add_menu_alias("Tumbadios", "TumbaDios");

   add_menu_alias("cerveza", "Pseudo-Cerveza de Noella");
   add_menu_alias("pseudo-cerveza", "Pseudo-Cerveza de Noella");
   add_menu_alias("Pseudo-Cerveza", "Pseudo-Cerveza de Noella");

   add_menu_alias("aguardiente", "Pseudo-Aguardiente de Enanos");
   add_menu_alias("pseudo-aguardiente", "Pseudo-Aguardiente de Enanos");
   add_menu_alias("Pseudo-Aguardiente", "Pseudo-Aguardiente de Enanos");

   add_menu_alias("vino", "Pseudo-Vino �lfico");
   add_menu_alias("pseudo-vino", "Pseudo-Vino �lfico");
   add_menu_alias("Pseudo-Vino", "Pseudo-Vino �lfico");

   add_menu_alias("alas", "Alas de Murci�lago");
   add_menu_alias("tostadas", "Tostadas de Musgo");
   add_menu_alias("patatas", "Patatas Braseadas");
   add_menu_alias("costillas", "Costillas de Cordero");
   add_menu_alias("pollo", "Asado de Pollo");
   add_menu_alias("ciervo", "Asado de Ciervo");
   add_menu_alias("jabal�", "Asado de Jabal�");
   add_menu_alias("jabali", "Asado de Jabal�");

   set_open_condition("abierto");
   set_heart_beat(1);

add_exit("noroeste", PRINCIPALES+"lele2","road");
add_exit("fuera", CALLEJONES+"callejon_C4","road");


int abierto()
{
  object *lista;
  int i;
  if (!barman) return 0;
  else
  {
      lista=barman->query_attacker_list();
      for(i=0;i<sizeof(lista);i++)
      {
        if (environment(lista[i])==this_object()) return 0;
      }
      if ((int)ob->query_timed_property("guardias_noella"))
      {
      notify_fail("Nadie quiere atenderte... parece que tu presencia no es del agrado del local.\n");
      return 0;
      }
  }
  return 1;
}


void reset()
{
   ::reset();
   if (!barman)
   {
      barman=new(NPC+"viejo_lele");
      barman->move(this_object());
   }
   if (!init)
   {
      clientela=allocate(11);
      init=1;
   }
}

void dest_me()
{
 int i;

   if (barman) barman->dest_me();

   for (i=0; i<=10; i++)
   {
      if (clientela[i]) clientela->dest_me();
   }
   ::dest_me();
}


void heart_beat()
{
   int i, tipo;

   if (random(20)<4)
   {
      if (random(2))
      {
         if (clientes>0)
         {
            if (clientela[0])
            {
               tell_room(this_object(), clientela[0]->query_cap_name()+
               " paga al Viejo Lele y se va haciendo eses.\n");
               clientela[0]->dest_me();
            }
            for (i=0; i<clientes-1; i++)
            {
               clientela[i]=clientela[i+1];
            }
            clientes--;
         }
      }
      else
      {
         if (clientes<10)
         {
            tipo=random(3);
            switch(tipo)
            {
               case 0: clientela[clientes]=new(NPC+"borracho.c");
                       clientela[clientes]->move(this_object()); break;
               case 1: clientela[clientes]=new(NPC+"crea_ciudadanos.c");
                       clientela[clientes]->move(this_object()); break;
               case 2: clientela[clientes]=new(NPC+"guardian.c");
                       clientela[clientes]->move(this_object()); break;
            }
            tell_room(this_object(), clientela[clientes]->query_cap_name()+
            " entra en L'Lele y pide un TumbaDios.\n");
            clientes++;
         }
      }
   }
   return 1;
}
