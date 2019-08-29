#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Aqui puedes observar un curioso fenomeno, del suelo fluye agua burbujeante "
    "que tras un corto recorrido desaparece absorvida por la tierra, es como un pequenyo "
    "sifon. En esta zona la vegetacion es realmente agobiante, sin duda debido a tanta humedad,"
    " ves unos enormes helechos."
    "\n\n");
    add_item( ({"sifon","agua"}),"Es como un pequenyo manantial de agua fresca surgiendo del suelo. "
    "El agua discurre senda abajo de forma natural antes de desaparecer en el mullido suelo "
    "al filtrarse en la tierra humeda. "
    "\n");
    add_item( ({"helecho","helechos","fern"}),"Del tamanyo de un hombre, estos helechos "
    "tienen unas largas hojas verdes brillantes y muy frondosas brotando de su tronco marron. "
    "\n");
    add_sound( ({"burbujas","agua","burbuja"}),"El agua gorgotea al ser expulsada por el "
    "sifon haciendo pequenyos ruidos."
    "\n");

}
void init()
{
    add_exit("norte",HAVMAND+"j31.c","path");
    add_exit("sudeste",HAVMAND+"j33.c","path");

    ::init();
}


