#include "/w/barthleby/path.h"

inherit "/std/outside.c";

void setup()

{
    set_short("%^YELLOW%^Murallas de Noella. Puerta Sur%^RESET%^");
     set_long("%^YELLOW%^Murallas de Noella. Puerta Sur%^RESET%^\n\n"+
      "Sin duda esta es la m�s peque�a de las cuatro puertas de Noella. Te " +
      "resulta extra�o que una entrada destinada al tr�fico de mercanc�as " +
      "posea una anchura tal que un carro un poco grande tenga que dejarse " +
      "media rueda para conseguir traspasarla. Sin embargo este hecho hace " +
      "que resulte realmente dificil que algo o alguien se introduzca en la " +
      "ciudad sin ser visto.\n\n");

    set_light(70);

//add_clone(NPC+"guardia_noella", 3);

add_exit("oeste", MURALLAS_NOELLA+"muralla29","road");
add_exit("norte", CALLE+"calle13","road");
add_exit("este", MURALLAS_NOELLA+"muralla30","road");
add_exit("sur", MURALLAS_NOELLA+"ponte_S1","road");
set_zone("muralla");

}

