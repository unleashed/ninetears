#include "/w/barthleby/path.h"

inherit BASE"OSO.c";




object barman;

mixed top_list, top_deaths;
void add_to_list(object ob);

object barman;
void setup()

{


    set_short("%^RED%^Taberna L'Trabuk%^RESET%^");
     set_long("%^RED%^Taberna L'Trabuk%^RESET%^\n\n"+
      "Es la taberna m�s cercana a la catedral, por lo que no es extranyo ver alg�n que otro " +
      "clerigo por aqu�. Con unas bebidas de precio accesible no sorprende que sea el punto de " +
      "reuni�n de bardos y trobadores, un grupo de estos �ltimos parecen vivir aqu� y pasan el " +
      "d�a cantando, tocando y bebiendo, cosa que atrae o repele a los clientes dependiendo " +
      "de la cantidad de alcohol que los trobadores lleven encima.\n\n");

    set_light(50);

add_item("barra", "Una larga barra de madera bastante sucia y mojada con restos de bebidas.\n");

   add_menu_item("Cerveza de Noella", ALCOHOL, 20, 2, 10, 10,
      "te bebes tu cerveza de un trago",
        "se bebe la cerveza de un trago y sin pesta�ear");
   add_menu_item("Aguardiente de Enanos", ALCOHOL, 900, 15, 350, 350,
      "te estremeces de arriba abajo al tragar un chupito de este aguardiente tan fuerte, te arde la garganta",
        "se bebe un chupito de aguardiente y su rostro se vuelve p�lido y comienza a echar humo");
   add_menu_item("Vino �lfico", ALCOHOL, 900,15,350,345,
      "bebes un trago de la jarra de vino",
	"se bebe un trago de la jarra de vino");
   add_menu_item("Agua de Manantial", SOFTDRINK, 75, 3, 5, 0,
      "bebes refrescante agua pura",
        "se bebe un vaso de agua");

   add_menu_alias("cerveza", "Cerveza de Noella");
   add_menu_alias("aguardiente", "Aguardiente de Enanos");
   add_menu_alias("vino", "Vino �lfico");
   add_menu_alias("agua", "Agua de Manantial");

   set_open_condition("abierto");


add_exit("fuera",PRINCIPALES+"plaza_del_tapal","road");

}

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
      barman=new(NPC+"popi");
      barman->move(this_object());
   }
}

void dest_me()
{
   if (barman) barman->dest_me();
   ::dest_me();
}

