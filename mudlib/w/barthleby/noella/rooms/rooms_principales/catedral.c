#include "/w/barthleby/path.h"

inherit "/std/room.c";


void setup()

{
    set_short("%^YELLOW%^Catedral de Noella%^RESET%^");
     set_long("%^YELLOW%^Catedral de Noella%^RESET%^\n\n"+
      "Ante ti se abre una enorme edificaci�n con un altar de ceremonias al fondo. Dos " +
      "gigantescos �rganos est�n en las paredes laterales, colocados sobre unas plataformas de " +
      "madera a las que se accede por unas estrechas escaleras de su base. Las vidrieras de " +
      "las ventanas, altas y delgadas, dejan caer unos haces de luz multicolor que inundan por " +
      "completo la estancia.\n\n");

    set_light(70);

add_item("altar","Es el tipico altar de ceremonias formado por una losa superior asentada sobre " +
        "otras dos a modo de pies cubierto por una tela blanca con encages y bordados.\n");

add_item(({"organo","organos","�rgano","�rganos"}),"Enormes instrumentos musicales erguidos sobre dos plataformas " +
        "de madera, cuyos tubos de viento recorren toda la pared hasta llegar al techo. Son " +
        "realmente impresionantes.\n");

add_item(({"plataforma","plataformas"}),"Estas plataformas son las encargadas de soportar los " +
        "dos imponentes �rganos.\n");

add_item(({"vidrieras","ventanas","ventana","vidriera"}),"Unas " +
        "ventanas de entre dos y tres metros de alto, contienen " +
        "las vidrieras de colores con motivos religiosos. Los haces multicolor que hay por toda " +
        "catedral son el efecto producido por la luz exterior al atravesar esas vidrieras.\n");

add_exit("fuera", PRINCIPALES+"plaza_del_tapal","road");
}
