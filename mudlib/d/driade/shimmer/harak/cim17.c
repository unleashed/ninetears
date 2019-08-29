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
        ob->add_timed_property("congelado", 1, 5); 
        break;
       default:
        tell_room(ob,"Tu cuerpo no esta preparado para soportar tanto frio, te congelas por momentos y te dan espasmos.\n");
        ob->adjust_hp(-roll(2,6), this_player());
        ob->add_timed_property("congelado", 1, 5);
      }
  }
  
} 


void setup() {

   set_exit_color("white");
   set_zone("cima");
   set_light(40);
   set_short("%^BOLD%^WHITE%^Cima del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^");
   set_long("%^BOLD%^WHITE%^Cima del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^\n\n"
   "Estas en la cima del Harak-Din, a tu alrededor todo esta cubierto "
   "de nive, el frio insoportable te llega a los huesos y tus miembros comienzan "
   "a congelarse poco a poco, mas vale que salgas pronto de la zona o acabaras "
   "formando parte del paisaje bajo la espesa capa de nieve. El viento frio y cargado "
   "de copos te corta la cara constantemente. Miras a tu alrededor y no ves mas que "
   "la inmensidad blanca que lo cubre todo.\n\n");

add_clone(NPCS+"varios_cima_harak.c",0);

add_exit("oeste",   HARAK+"cim14.c","standard");
add_exit("noroeste",HARAK+"cim13.c","standard");
add_exit("norte",   HARAK+"cim18.c","standard");
add_exit("noreste", HARAK+"cim19.c","standard");
add_exit("este",    HARAK+"cim20.c","standard");
add_exit("sudeste", HARAK+"cim21.c","standard");
add_exit("sur",     HARAK+"cim16.c","standard");
add_exit("sudoeste",HARAK+"cim15.c","standard");
}