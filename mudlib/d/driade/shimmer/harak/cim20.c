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
   "la inmensidad blanca de la nieve que lo cubre todo, pero hay algo raro cerca de aqui.\n\n");

add_item("nieve","Miras a tu alrededor rebuscando sobre la nieve y descubres lo que parecen unas "
                 "pisadas que van hacia una de las paredes de la roca, las sigues y descubres una "
                 "pequenya puerta en la pared cubierta por la nieve, no sabes como podrias abrirla, "
                 "pero algo se te ocurrira.\n\n");

add_item("puerta","Es una vieja puerta de madera que debe llevar a alguna caverna en la roca de la cima, "
                 "parece congelada e igual podrias tratar de forzarla para abrirla.\n\n");

add_clone(NPCS+"varios_cima_harak.c",0);

add_exit("norte",   HARAK+"cim19.c","standard");
add_exit("noroeste",HARAK+"cim10.c","standard");
add_exit("oeste",   HARAK+"cim17.c","standard");
add_exit("sudoeste",HARAK+"cim16.c","standard");
add_exit("sur",     HARAK+"cim21.c","standard");
}


void init()
{
   ::init();
   add_action("forzar", "forzar");  /* si en la room pones forzar/romper/empujar puerta, esta se rompe y puedes pasar */
   add_action("forzar", "empujar");
   add_action("forzar", "romper");
   add_action("forzar", "golpear");
}

void forzar(string puerta)
{
   if (!puerta || puerta!="puerta")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }
   write("\nGolpeas la puerta congelada con todas tus fuerzas y esta estalla y se rompe en mil pedazos que saltan por "
   "todos lados, ante ti se abre lo que parece una caverna excavada sobre la roca. Sin pensartelo pasas hacia dentro.\n");
   say(this_player()->query_cap_name()+" golpea algo con todas sus fuerzas y desaparece entre la nieve ante tu asombro.\n");
   this_player()->move(HARAK+"caverna1.c");
   this_player()->look_me();
   return 1;
}