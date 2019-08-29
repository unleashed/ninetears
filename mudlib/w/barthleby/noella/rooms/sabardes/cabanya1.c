#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^BOLD%^%^RED%^Caba�as gemelas%^RESET%^");
     set_long("%^BOLD%^%^RED%^Caba�as gemelas%^RESET%^\n\n"+
      "Una de las dos �nicas construcciones del lugar que se mantiene todav�a en pie. " +
      "Ambas son propiedad de Maniaur, un viejo elfo que ha encontrado aqu� paz y " +
      "tranquilidad, as� como un gran lugar desde el que contemplar el hermoso " +
      "bosque. Puedes ver una chimenea encendida en el centro de la pared, unas " +
      "viejas estanter�as y una mesa redonda en el centro de la habitaci�n.\n\n");

    set_light(60);

add_item("chimenea","Est� situada justo en medio de la pared de forma que consigue " +
        "mantener calientes ambas caba�as. En ella es donde Maniaur prepara sus " +
        "comidas. Dirias que no hay nada que est� produciendo las llamas, pero debido " +
        "a su intensidad no puedes verlo con claridad.\n");

add_item(({"estanteria", "estanterias", "estanter�a", "estanter�as"}),"Son unas estanter�as mas bien endebles pero " +
        "soportan el peso de infinidad vasijas, jarras y otros tipos de recipientes " +
        "que desprenden un olor terrible, y de los que no te atreves a siquiera " +
        "imaginar el contenido.\n");

add_item("mesa","Vieja y carcomida, apenas llegas a comprender como puede mantenerse " +
        "de una pieza. Sobre ella alcanzas a distinguir unos finos cordelitos entre " +
        "la espesa capa de polvo que la cubre. Trata de no acercarte mucho a ella, " +
        "no vaya a ser que se rompa.\n");

add_exit("fuera",  SABARDES+"sabardes2","road");
add_exit("sudeste",  SABARDES+"cabanya2","hidden");
}
