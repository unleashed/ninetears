inherit "/std/outside.c";

#include "../path.h"

string long = "Acantilado de los Lamentos\n\n"
              "     El angosto camino que bordea el acantilado "
              "se extiende serpenteando alrededor de los numerosos "
              "riscos y cornisas de la pared rocosa. Un paso en falso "
              "podria precipitarte muchos metros en el vacio y seria "
              "fatal. De vez en cuando se observa alguna pequenya "
              "cueva, posiblemente la madriguera de algun que otro "
              "animal.\n     Los lamentos de los Galeb-D'Hures se oyen "
              "a lo lejos. Este acantilado es su hogar, y no te gustaria "
              "tener que toparte con uno de ellos ahora mismo.\n\n";
              
string short = "Acantilado de los Lamentos";

void do_desc(int do_short, int do_long)
{
  add_property("luz_real",80);
  set_dark_long("Acantilado de los Lamentos\n\n     "
                "La noche dificulta enormemente tu camino. Apenas puedes "
                "ver donde pones los pies, y tienes que ir tanteando "
                "el camino ayudandote de las manos. De vez en cuando "
                "se oye pasar un ave nocturna, rompiendo la monotonia "
                "de la noche.\n\n");
  if (do_long)
    set_long(long);
  if (do_short)
    set_short(short);
    
  if (random(100)+1 > 60)
    add_clone(NPC+"galeb-dhur.c",random(2)+1);
    
  set_zone("acantilado_urghak");

} 
