//Valdor '99
// Intentad ordenar los ficheros para hacerlos mas legibles..y poder ir mas rapido al corregirlos si dan errores.

#include "path.h"

inherit "/std/room.c";

void setup()
{
   set_short("Pasillo del iniciado.\n");

   set_long("Este pasillo fue creado por los altos dioses con el fin de aleccionar a aquellos que quisieron"
		" disfrutar con ellos la maldicion de las maldiciones, la inmortalidad. "
             "El sonido del metal contra metal continua hacia el sur, posiblemente un pobre"
		" iluso que reto con imprudencia a algun noble inmortal.\n"
		"Al lado de la puerta del sur, ves un orificio.\n\n");

   set_light(70);
   
   add_item("orificio","Un pequenyo orifico trabajado en la pared. Dentro hay un boton.\n");
   add_item("boton","minusculo como un grano de arroz, posiblemente abra algo.\n");

   add_sound("metal","Parece que la batalla esta llegando a su fin cuando oyes le grito de una mujer.\n");

   add_exit("oeste",APRENDICES+"pasillo_1","corridor");
   add_exit("norte",APRENDICES+"Armeria","door");
   add_exit("este",APRENDICES+"Sala_del_retorno","door");
   add_exit("sur",APRENDICES+"Sala_de_luchas","door");   

}

void init()
{
  ::init();
  add_action("pulsar","pulsar");
  add_action("trampa",({"go","goback","goto","dest","ed","home"}));
}

int pulsar(string str)
{
 if (str == "boton")
 {
  write("Pulsas el boton y la pared de enfrente se abre descubriendo ante ti unas escaleras hacia abajo.\n");
  say("Ante tus atonitos ojos se abre una brecha en la pared descubriendo unas escaleras.\n");
  add_exit("abajo",APRENDICES+"Gruta_del_descanso","stairs");
  renew_exits();
  return 1;
 }
 notify_fail("Pulsar que??\n");
 return 0;
}
  
int trampa()
{
 write("Nonono, Eso es trampa.\n");
 return 1;
}


