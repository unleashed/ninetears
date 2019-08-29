#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Las paredes de roca se juntan una a otra en esta zona, y forman "
    "una semicueva estrecha, aqui se concentra el calor y la humedad. "
    "Oyes el sonido de agua salpicando por todas partes, y hay pequenyos "
    "enjambres de mosquitos que se esparcen a tu paso."
    "El suelo esta cubierto de musgo que forma una alfombra blanda y espesa "
    "y al pisar produce un ruido desgradable por la cantidad de agua que "
    "acumula, es como una esponja empapada. "
    "\n\n");
    add_item("musgo","Esta muy crecido y es grueso, desde luego esta humedo, "
    "es de color verde oscuro, al menos al ser tan espeso no es resbaladadizo "
    "ya que al pisarlo el pie se hunde unos centimetros. "
    "\n");
    add_sound("agua","Pling ..... pling ..... pling ...... "
    "(you moved) "
    "\n");
    add_feel("musgo","Buegh , es frio humedo... asqueroso!\n");
    add_item("mosquito","Tan diminutos que casi no se ven, pero muy molestos.\n");
//    add_taste(({"gnat","gnats"}),"Gritty, definately gritty, otherwise "
//    "tasteless.\n");
}
void init()
{
    add_exit("oeste",HAVMAND+"j37.c","path");
    add_exit("sudeste",HAVMAND+"j35.c","path");

    ::init();
}


