#include "/w/barthleby/path.h"

inherit "/std/underground.c";


void setup()

{
    set_short("%^BOLD%^%^RED%^Templo de Jakel%^RESET%^");
     set_long("%^BOLD%^%^RED%^Templo de Jakel%^RESET%^\n\n"+
      "Has entrado en el templo del dios de la muerte, el suelo est� cubierto de esqueletos " +
      "y otros restos de cad�veres. Sientes un crujido extra�o mientras caminas, producido " +
      "por la sangre reseca y peque�os huesos al quebrarse. Hay figuras diab�licas y " +
      "obscenas talladas a lo largo de las paredes de piedra. Ves una estatua de Jakel en " +
      "medio de la sala.\n\n");

    set_light(30);

add_item("estatua", "Esta es la estatua del Avatar de Jakel, una reproducci�n fiel del cuerpo " +
        "que utiliz� para vagar por el mundo. A pesar de encontrate ante su estatua, prefieres " +
        "no acercarte demasiado, pues parece como si de vez en cuando, un leve brillo rojizo " +
        "surgiese de sus ojos.\n");

add_item("altar", "Situado justo a los pies de su estatua, se trata de una sola roca " +
        "rectangular sobre la que realizar los tributos a Jakel.\n");

add_item(({"restos","esqueletos","cad�veres","cadaveres"}), "Hay restos humanoides por todo el suelo, " +
        "algunos son ya solo esqueletos o menos, pero observas que otros est�n bastante " +
        "frescos.\n");

add_item(({"pared","paredes","figuras"}), "Figuras diab�licas han sido talladas a lo largo de " +
        "las paredes del recinto, en algunas llegas a distinguir violentos desmenbramientos,  " +
        "violaciones y diferentes formas de tortura.\n");

add_exit("fuera", VARRO+"varro37","road");
}

