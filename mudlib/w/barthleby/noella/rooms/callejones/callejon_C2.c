#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^ORANGE%^Calle de L'Lele%^RESET%^");
     set_long("%^ORANGE%^Calle de L'Lele%^RESET%^\n\n"+
      "Se trata de una estrecha calle con el suelo adoquinado que ha tomado su nombre de uno " +
      "los lugares m�s emblem�ticos de la ciudad; La Taberna L'Lele. La aficci�n de esta " +
      "ciudad al vino tal vez sea una de las razones por las que sus habitantes resultan ser " +
      "tan hospitalarios y carentes de prejuicios raciales. Puedes sentir el olor del vino " +
      "barato desde aqu�.\n\n");

    set_light(30);

add_item(({"casa", "casas"}), "Casas de piedra y adobe se encuentran a ambos lados de " +
        "la calle. Todas sus puertas y ventanas parecen estar cerradas.\n");

add_item("suelo", "Un suelo adoquinado y no muy uniforme cuyas partes m�s profundas suelen " +
        "llenarse con agua y formar charcas en los d�as de lluvia.\n");

add_smell("vino", "Un penetrante olor a vino barato parece venir de la taberna cercana.\n");

add_exit("oeste", CALLEJONES+"callejon_G4","road");
add_exit("noreste", CALLEJONES+"callejon_C3","road");
add_exit("sudoeste", CALLEJONES+"callejon_C1","road");
set_zone("noella");

}

