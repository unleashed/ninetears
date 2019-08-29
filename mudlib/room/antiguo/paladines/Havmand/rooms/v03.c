# include "path.h"
inherit "/std/room";
void setup()
{
    add_property("no_undead",1);
    set_short("Isla de Havmand: Vivienda.");
    set_light(60);
   set_long("\nIsla de Havmand : Vivienda\n\n"
    "Esta miserable casita, construida junto al muro del castillo como el resto, "
    "parece estar abandonada y en desuso desde hace muchisimo tiempo "
    "Hay una pequenya mesa con unas cuantas sillas al lado de una pared, "
    "Y un gran cajon en la otra pared. El resto esta vacio, cualquier otra cosa que hubiera "
    "en la casa habra sido trasladado o tal vez hayan saqueado el lugar. "
    "\n\n");
    add_item("mesa","Una pequenya mesa cubierta de polvo, una de sus patas parece "
    "rota.\n");
    add_item(({"silla","sillas"}),"Dos sillas de madera, estan cubiertas de polvo "
    "y necesitan algunos arreglos, sus respaldos estan desencajados.\n");
    add_item("cajon","Un gran cajon de madera ocupa todo el largo de una pared. Parece "
    "disenyado para poder usarlo de camastro, aunque no hay rastro de sabanas ni nada "
    "parecido.\n");
   add_item("pata","La mesa solo tiene tres patas, la cuarta no se ve por ningun lado, "
      "aunque de todas formas la mesa se mantiene de pie, no obstante no puede ser muy "
      "estable desde luego.\n");

    add_exit("este",HAVMAND+"t05.c","path");
}
