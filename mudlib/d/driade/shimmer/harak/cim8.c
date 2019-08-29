/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void event_enter(object ob, string mensaje, object donde)
{
  if (interactive(ob) && !(int)ob->query_timed_property("congelado"))
  {
       switch(ob->query_race_ob())
      {
       case("orco"):case("drow"):case("enano"):
        tell_room(ob,"Notas que se te congela la sangre y el frio te hace sentir mal.\n");
        ob->adjust_hp(-roll(1,6), this_player());
        ob->add_timed_property("congelado", 1, 25); 
        break;
       default:
        tell_room(ob,"Tu cuerpo no esta preparado para soportar tanto frio, te congelas por momentos y te dan espasmos.\n");
        ob->adjust_hp(-roll(2,6), this_player());
        ob->add_timed_property("congelado", 1, 25);
      }
  }
  
} 

void setup() {

   set_exit_color("white");
   set_zone("cima");
   set_light(40);
   set_short("%^BOLD%^WHITE%^Cerca de la Cima del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^");
   set_long("%^BOLD%^WHITE%^Cerca de la Cima del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^\n\n"
   "Estas acercandote a la cima del Harak-Din, a tu alrededor todo esta cubierto "
   "de nive, el frio es insoportable y tus miembros comienzan a congelarse poco a poco, "
   "mas vale que salgas pronto de la zona o acabaras formando parte del paisaje bajo "
   "la espesa capa de nieve. El viento frio y cargado de copos te corta la cara "
   "constantemente.\n\n");

add_clone(NPCS+"varios_cima_harak.c",2);

add_exit("sudeste",HARAK+"cim9.c","standard");
add_exit("oeste",  HARAK+"cim7.c","standard");
}