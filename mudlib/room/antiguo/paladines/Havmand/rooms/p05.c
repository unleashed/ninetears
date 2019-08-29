#include "path.h"
inherit HAVMAND+"pirate.c";
void setup()
{
    
   set_light(LIGHT);
    set_short("Isla de Havmand: Campamento Pirata.\n");
    set_long("\nIsla de Havmand: Campamento Pirata.\n"
    "   Esta zona del campamento esta justo al lado de la playa y parece estar mas "
    "limpia que el resto. Varias conchas han sido recojidas de la playa y colocadas "
    "por aqui sin otro motivo obvio que el de adornar. Hay otra hamaca colgando entre "
    "dos arboles, y parece como si alguien se hubiera tomado la molestia de mantener "
    "esta zona del campamento razonablemente limpia y en orden. "
    "\n\n");
    add_item("conchas","Grandes y coloridas conchas de mar, colocadas haciendo bonitas "
    "formas.\n");
    add_item("hamaca","Una hamaca que parece estar hecha a base de lianas cortadas en "
    "la densa jungla.\n");
    add_item("liana","Largas lianas encadenadas entre si cuelgan de alguno de los arboles "
    "como si fueran cuerdas. Si puedieras cortar una seguramente te seria util en algun momento.\n");
    add_item("arboles","Son los arboles de la jungla, crecen muy juntos entre si, y dos de ellos "
    "hacen de soporte a la hamaca.\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"p04.c","path");
    add_exit("este",HAVMAND+"b04.c","path");
    add_exit("noroeste",HAVMAND+"p03.c","path");

    ::init();
}
