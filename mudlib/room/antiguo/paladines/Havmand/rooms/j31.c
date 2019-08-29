#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Segun vas bajando por este sendero el suelo se hace mas mullido y "
    "tambien mas empinado. Sigue habiendo cantidad de arboles a tu alrededor, "
    "y ves algun que otro interesante hongo de brillantes colores creciendo en la base "
    "de algun arbol. El sonido del agua es mas fuerte. "
    "\n\n");
    add_item("hongo","De aspecto letal estos hongos parecen crecer bien "
    "en esta zona de la jungla donde se nota mas humedad. "
    "\n");
    add_sound("agua","Suena como si hubiera una cascada en algun lugar "
    "cerca de aqui. "
    "\n");

}
void init()
{
    add_exit("noreste",HAVMAND+"j30.c","path");
    add_exit("sur",HAVMAND+"j32.c","path");

    ::init();
}


