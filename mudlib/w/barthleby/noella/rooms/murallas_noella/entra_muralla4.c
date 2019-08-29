#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^YELLOW%^Murallas de Noella. Puerta Este%^RESET%^");
     set_long("%^YELLOW%^Murallas de Noella. Puerta Este%^RESET%^\n\n"+
      "Este es el m�s reciente de los accesos a la ciudad. Ante ti " +
      "permanecen abiertas dos gigantescas puertas que dan paso a una " +
      "tremenda abertura en las murallas, dividida en dos por un descomunal " +
      "pilar de una sola pieza, de un mineral completamente negro que no " +
      "has visto en ninguna otra parte y que esta sorprendentemente liso y " +
      "brillante, como si estuviese fuera del alcance del tiempo y los " +
      "elementos.\n\n");

    set_light(70);

add_item("pilar","Sin dudarlo te aproximas al negro pilar para poder " +
        "observarlo m�s de cerca. Te das cuenta de que la extrema pulcritud " +
        "del pilar permite que su superficie refleje todo cuanto hay a su " +
        "alrededor pero..... �C�mo es posible! �Tu reflejo no est�!\n");

add_item(({"puerta","puertas"}),"Dos gigantescas puertas de madera se abren a ambos lados de la " +
        "entrada. Al ser tan grandes y pesadas es l�gico que haga falta la fuerza de unos seis " +
        "hombres para abrirlas y cerrarlas.\n");

//add_clone(NPC+"guardia_noella", 3);

add_exit("norte", MURALLAS_NOELLA+"muralla38","road");
add_exit("sudeste", MURALLAS_NOELLA+"ponte_E1","road");
add_exit("sudoeste", MURALLAS_NOELLA+"muralla37","road");
set_zone("muralla");

}

/*Falta que al tocar el pilar salga: Al tocar el pilar sientes una ligera
descarga que hace que retires tu mano al instante*/
/*Puede que funcione pero aun esta sin probar   CAMBIAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
void init()
{
   ::init();
   add_action("tocar_pilar","tocar");
}

int tocar_pilar(string que)
{
	if (!que || que!="pilar") {
		notify_fail("Tocar que?");
		return 0;
	}
    tell_room(TO,TP->query_cap_name()+" toca el pilar y retira su mano con cara de sorpresa.\n",TP);

    tell_object(TP,"Al tocar el pilar sientes una ligera descarga que hace que retires tu mano al instante.\n");
		return 1;
}
