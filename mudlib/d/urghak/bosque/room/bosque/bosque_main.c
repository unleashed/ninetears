/* 
Bosque de Urghak
----------------
Xerxes, 2002
*/

inherit "/std/bosque.c";
#include "../../path.h"

string long = "%^BLACK%^BOLD%^Bosque de %^RESET%^GREEN%^Urghak%^RESET%^\n\n"
	"     Te preguntas como es posible que un bosque sea tan silencioso, "
	"pues hasta el mas lugubre de los bosques podria tener mas vida "
	"que este. Es el bosque de Urghak, una gran mancha negra en las "
	"tierras de Urghak: hectareas de arboles calcinados que, sin que "
	"nadie sepa por que, siguen hurgando el suelo con sus morbidas "
	"raices. Todo esta vivo, y a la vez, muerto.\n     Anyos atras, "
	"en este mismo bosque se libro una escaramuza que resulto con "
	"la muerte de cientos de seres vivos, cuyas almas, deduces, "
	"es posible que sigan vagando la zona. La monotonia del bosque se "
	"rompe con algun cadaver descompuesto, victima de los misteriosos "
	"seres que se ocultan tras los arboles de onice, y cuya carne es "
	"viciosamente picoteada por algun que otro cuervo que ronda por "
	"el lugar.\n";
	
string short = "%^BLACK%^BOLD%^Bosque de %^RESET%^GREEN%^Urghak%^RESET%^";

void do_desc(int do_short, int do_long)
{
  
  set_night_long("%^BLACK%^BOLD%^Bosque de %^RESET%^GREEN%^Urghak%^RESET%^\n\n"
	"     Si de dia puede resultar tenebroso, ahora lo es el doble."
	"Temerosamente tanteas con tus manos el inmenso vacio del bosque, "
	"algo totalmente diferente a la espesura y la densidad vegetal que "
	"habia de dia. Te preguntas si los arboles juegan contigo, puesto que "
	"ademas de apartarse de tu vago camino, te parece oir sus malevolas risas. "
	"Quien sabe que es lo que traman.%^RESET%^\n\n");
  
  if (random(100)+1 > 40) {
    long += "     Esta parte del bosque esta algo mas despejada que el resto. Los "
	      "arboles parecen pelearse por apartarse del camino: realmente es "
	      "un espectaculo tetrico.\n\n";
    } else if (random(100)+1 > 50) {
      long += "     Un gran tronco caido yace delante de ti. Por la gran cantidad "
		  "de musgo que lo cubre deduces que lleva asi muchos, muchos "
		  "anyos. 'No parece un buen lugar para venir a talar' te dices "
		  "a ti mismo. Quien sabe si el que provoco la caida de este "
		  "arbol no buscaba talar madera, sino decapitar un enemigo.\n\n";
      add_item(({"tronco"}), "El tronco grisaceo parece haber sido cortado "
		                 "brutalmente. Esta cubierto de musgo.\n");
    } else {
      long += "     El entramado de caminos en el bosque comienza a ser "
		  "desconcertante. Por un momento te preguntas si no te estas "
		  "perdiendo...\n\n";
    }
  if (do_long)
    set_long(long);
  if (do_short)
    set_short(short);

  add_property("luz_real",80);

  add_item(({"suelo", "hojas", "hoja"}),"Las hojas, muertas, yacen en el suelo, "
      "completamente inertes: estaticas por la falta de viento que las meza.\n");

  add_item(({"arbol", "arboles"}), "Los arboles, que parecen esperar "
	"el momento mas oportuno para dar cuenta de la poca vida que poseen, "
	"estiran sus ramas hacia el cielo. Seguramente les gusta estar aqui "
	"tan poco como a ti.\n");

  add_item(({"cielo", "nubes", "sol"}), "Como suponias, el poco cielo que ves "
	"esta cubierto por un denso manto de nubes grises.\n");
  if (random(100)+1 > 60) {
    day_clone("/d/urghak/bosque/npc/cuervo.c",random(2));
    night_clone("/d/urghak/bosque/npc/buho.c",random(2));
  }
  if (random(100)+1 > 40)
    add_clone("/d/urghak/bosque/npc/serpiente.c",random(2)+1);
  if (random(100)+1 > 50)  
    add_clone("/d/urghak/bosque/npc/lobo.c",random(1)+1);
    
  set_zone("bosque_urghak");

} /* do_desc */
