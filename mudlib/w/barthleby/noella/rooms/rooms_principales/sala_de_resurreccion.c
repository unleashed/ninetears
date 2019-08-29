// Eso mismo :)
#include "/w/barthleby/path.h"

inherit "/std/raiseroom";

object ayudante;

void setup()
{
   set_short("%^BOLD%^Sala de resurrecci�n%^RESET%^");
   set_save_file(NOELLA+"raise");
   set_helper_name("Picon");
   set_long("%^BOLD%^Sala de resurrecci�n%^RESET%^\n\n"+
      "Una diminuta sala donde prometen subsanar p�rdidas irreparables, eso si, a cambio de " +
      "algunas monedas. Hay un peque�o altar en el centro de la habitaci�n.\n\n");
            "Un cartel cuelga de la pared.\n");
    set_percentage(100);
    set_light(60);
    add_item("altar","Una gran piedra rectangular de marmol blanco veteado es usado aqu� a modo de " +
        "altar.\n");

    add_sign("Es un cartel met�lico puesto en una de las paredes.\n",
            "/---------------------------------------------\\\n" +
            "|                                             |\n" +
            "|  Servicio de levantamiento de muertos de    |\n" +
            "|  Noella.                                    |\n" +
            "|  Necesitas una cuenta aqu� para que te      |\n" +
            "|  podamos cobrar.                            |\n" +
            "|                                             |\n" +
            "|  Pon 'crear' para abrir una cuenta.         |\n" +
            "|  'ingresar' para ingresar dinero.           |\n" +
            "|  'balance' para ver cuanto dinero te queda. |\n" +
            "|  'raise me' cuando necesites resucitar.     |\n" +
            "|  'raise <fantasma>' cuando uses tu cuenta   |\n" +
            "|  para resucitar a otra persona.             |\n" +
            "|                                             |\n" +
            "|  Un levantamiento cuesta 1 moneda de        |\n" +
            "|  platino por cada nivel.                    |\n" +
            "|                                             |\n" +
            "| NOTA: Si tu nivel es superior a 9 perderas  |\n" +
            "| un punto de 'con' para siempre. Busca a un  |\n" +
            "| clerigo con 'resurrect'.                    |\n" +
            "|                                             |\n" +
            "\\---------------------------------------------/\n" );

   add_exit("fuera", CAMINO_SUDESTE+"camino_sudeste5","road");
   add_clone(NPC+"resucitaor",1);
}

