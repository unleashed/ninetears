#include "/w/barthleby/path.h"

inherit "/std/sacroom";


void setup()
{
  set_short("%^BOLD%^%^CYAN%^Templo de Barthleby%^RESET%^");
     set_long("%^BOLD%^%^CYAN%^Templo de Barthleby%^RESET%^\n\n"+
      "La forma de este edificio imita por completo a una pagoda. Consta de tres pisos " +
      "comunicados por una escalera central en espiral. Este piso, al igual que los otro dos, " +
      "carece de decoracion alguna, exceptuando el cuadro de la pared este. En el centro de " +
      "esta habitaci�n se encuentran la estatua dedicada a Barthleby y su altar, ambos " +
      "fundidos en una sola pieza.\n\n");

  set_light(70);

  add_clone(ITEMS+"rodado.c",1);

  set_exit_color("cyan");

add_item("cuadro","Por m�s que lo intentas, no acabas de diferenciar ninguna forma conocida " +
        "que pueda estar pintada sobre este lienzo; tal vez sea por el paso del tiempo o por " +
        "haber sido as� desde un principio.\n");

add_item("escalera","La escalera tiene forma de espiral ascendente hacia la derecha y comunica " +
        "los tres pisos.\n");

   add_exit("abajo", PRINCIPALES+"templo_barthleby2","corridor");

   set_god_here("barthleby");

}


/*void init()
{
  add_action("sacrificio","sacrificar");
  ::init();
}

int sacrificio(string str)
{
  int j;
  object *lista;

  if(str=="rodado")
  {
   lista=all_inventory(TP);
    notify_fail("No tienes ese objeto.\n");
    for (j=0;j<sizeof(lista);j++)  {

        if (lista[j]->query_name("rodado")=="rodado")  {

        if( this_object()->query_timed_property("SACR")==0 ){

	this_object()->add_timed_property("SACR",1,1000);

	modify_item("altar_barthleby","Parece como si el altar hubiese adquirido un brillo extra�o. "
                    "Seguramente se ha realizado un sacrificio recientemente.\n");
	tell_object(this_player(),"Muestras tu sacrificio a la estatua de Barthleby y lo depositas "
                    "sobre su altar.\n");
	tell_room(this_object(),this_player()->query_cap_name()+" muestra su sacrificio "
		  "a la estatua de Barthleby y lo deposita en el altar.\n",this_player());
	tell_room("Una imagen borrosa del propio Barthleby surge de su estatua y alcanzas a distinguir. "
	          "su expresion de satisfaccion al tiempo que la imagen se disipa de nuevo.\n");
	clone_object("/baseobs/misc/gods/barthleby.c")->move(this_object());
	lista[j]->dest_me();

	return(1);
      }

      tell_object(this_player(),"Se ha realizado un sacrificio recientemente. "
                                "Barthleby esta satisfecho.\n");
      return(1);
    }
  }

  notify_fail("Eso no parece ser del agrado de Barthleby.\n");
  return(0);
  }
}*/

