#include "path.h"
inherit HAVMAND+"pirate.c";

void setup()
{
    
   set_light(LIGHT);
    set_short("Isla de Havmand: Campamento Pirata.\n");
    set_long("\nIsla de Havmand: Campamento Pirata.\n"
    "   En esta zona acampan varios piratas. Tienen su barco averiado desde hace "
    "un tiempo, y sobreviven a base de pescado y lo que cazan en la selva. "
    "Desafortunadamente suelen merodear por la aldea a menudo, buscando "
    "cualquier cosa interesante, y generalmente son un fastidio. \n"
    "Una hamaca cuelga entre dos arboles, a su alrededor, por el suelo, hay varias "
    "botellas vacias. Tambien hay unas pocas vainas tiradas por el suelo, "
    "aunque no ves ningun arma al que puedieran pertenecer. "
    "\n\n");
    add_item("hamaca","Es una hamaca donde duerme uno de los piratas. Aparenta ser "
    "muy comoda y esta estrategicamente colocada algo apartarda.\n");
    add_item("botellas","Botellas vacias por todas partes, parece que estos piratas "
    "son unos grandes bebedores.\n");
    add_item(({"vaina","vainas"}),"Son las vainas donde se enfundan las armas, parecen muy "
    "sucias y oxidadas, como si llevaran mucho tiempo aqui tiradas. No hay ningun arma no obstante.\n");
add_item("arboles","Los arboles aqui son mas escasos, talados por los piratas para su campamento.\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"j16.c","path");
    add_exit("este",HAVMAND+"p03.c","path");
    add_exit("norte",HAVMAND+"j19.c","path");
    add_exit("sur",HAVMAND+"j18.c","path");
    add_exit("sudeste",HAVMAND+"p04.c","path");

    ::init();
}

