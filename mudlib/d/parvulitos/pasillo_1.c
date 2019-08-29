//Valdor '99
// Intentad ordenar los ficheros para hacerlos mas legibles..y poder ir mas rapido al corregirlos si dan errores.

#include "path.h"

inherit "/std/room.c";

void setup()
{
   set_short("Pasillo del iniciado.\n");

   set_long("Este pasillo fue creado por los altos dioses con el fin de aleccionar a aquellos que quisieron"
		" disfrutar con ellos la maldicion de las maldiciones, la inmortalidad. Al norte puede olerse un"
		" olor agradable. El sonido de metal contra metal puedes oirlo hacia el este, posiblemente un pobre"
		" iluso que reto con imprudencia a algun noble inmortal.\n");

   set_light(70);

   add_smell(({"olor","agradable"})," Parece ser el nectar de la inmortalidad tan bueno que probaste hace poco.\n");
   add_sound("metal","Parece una batalla muy violenta.\n");

   add_exit("este",APRENDICES+"pasillo_2","corridor");
   add_exit("norte",APRENDICES+"Camara_de_los_sentidos","door");
   add_exit("sur",APRENDICES+"Sala_principal","door");   

}

void init()
{
  ::init();
  add_action("trampa",({"go","goback","goto","dest","ed","home"}));
}

int trampa()
{
 write("Nonono, Eso es trampa.\n");
 return 1;
}


