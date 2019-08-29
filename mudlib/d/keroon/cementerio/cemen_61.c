// Made by Thalos  25/03/02

inherit "/std/suboscuridad";
#include "../path.h"

void setup() {

   set_zone("cementerio");
   set_exit_color("white");
   set_light(20);
   set_short("%^BOLD%^Panteon abandonado%^RESET%^");
   set_long("\n%^BOLD%^Panteon abandonado%^RESET%^.\n\n""Estas dentro de lo que antiguamente debio ser el pateon de una importante familia duergar, aun quedan restos de las pinturas y cortinajes que adornaban las paredes aunque eres incapaz de adivinar que representaban, debido a las manchas de humedad, sangre y otros cosas que prefieres no saber que son, el estado en que se encuentra indica que lleva abandonado mucho tiempo.""\n\n");

add_clone(ITEMSCEMENTERIO+"sarcofago1.c");
add_clone(NPCSCEMENTERIO+"nosferatu.c");
add_exit("puerta",CEMENTERIO+"cemen_62.c","standard");

}
void init()
{
 ::init();
 add_action("mover_sarcofago","mover");
}

int mover_sarcofago(string str)
{
  if(str=="sarcofago")
  {
  write("Con un gran esfuerzo mueves el sarcofago y aparecen unas escaleras.\n");
  say(this_player()->query_cap_name()+" mueve el sarcofago.\n");
  add_exit("escaleras","CATACUMBAS+","door");
  renew_exits();
  return(1);
  }
  notify_fail("Mover que?.\n");
  return(0);
}