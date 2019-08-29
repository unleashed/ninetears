#include "/w/barthleby/path.h"

inherit BASE"OSO.c";

object barman;

mixed top_list, top_deaths;
void add_to_list(object ob);

object barman;
void setup()

{



    set_short("%^YELLOW%^Tasca T�pica%^RESET%^");
     set_long("%^YELLOW%^Tasca T�pica%^RESET%^\n\n"+
      "La taberna m�s antigua de Noella. Sus muros de casi dos metros de espesor hacen pensar " +
      "que fue construida sobre los restos de un antiguo torre�n. Todos sus muebles son de " +
      "madera, algunos realmente antiguos y desgastados. Por toda la pared descansan colgadas " +
      "multitud de armas, escudos, armaduras y estandartes que los propietarios de la taberna " +
      "han ido depositando a lo largo de varias generaciones.\n\n");

    set_light(50);

add_item(({"muro","muros"}), "Son unos muros de unos dos metros y medio de espesor formados por " +
        "gigantescas rocas.\n");

add_item(({"mueble","muebles"}), "De madera y extremadamente viejos y desgastados aun logran " +
        "cumplir airosamente la funci�n para la que fueron constru�dos.\n");

add_item(({"armas","armaduras","escudos","estandartes"}), "A lo largo de toda la parte interior " +
        "de los muros hay colgada una gran colecci�n de material b�lico perteneciente a los " +
        "due�os que ha tenido la taberna a lo largo de los a�os.\n");

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

   add_menu_alias("cerveza", "Cerveza de Noella");
   add_menu_alias("aguardiente", "Aguardiente de Enanos");
   add_menu_alias("vino", "Vino �lfico");
   add_menu_alias("agua", "Agua de Manantial");
   add_menu_alias("alas", "Alas de Murci�lago");
   add_menu_alias("tostadas", "Tostadas de Musgo");
   add_menu_alias("patatas", "Patatas Braseadas");
   add_menu_alias("costillas", "Costillas de Cordero");
   add_menu_alias("pollo", "Asado de Pollo");
   add_menu_alias("ciervo", "Asado de Ciervo");
   add_menu_alias("jabal�", "Asado de Jabal�");
   add_menu_alias("jabali", "Asado de Jabal�");

   set_open_condition("abierto");


add_exit("fuera",CALLE+"calle10","road");

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
      barman=new(NPC+"gerrard");
      barman->move(this_object());
   }
}

void dest_me()
{
   if (barman) barman->dest_me();
   ::dest_me();
}

