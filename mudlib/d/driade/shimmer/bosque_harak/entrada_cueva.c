/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_zone("bosque");
   set_light(50);
   set_short("%^GREEN%^Bosque de %^BOLD%^%^GREEN%^Harak%^RESET%^");
   set_long("%^GREEN%^Bosque de %^BOLD%^%^GREEN%^Harak%^RESET%^\n\n"
   "Te encuentras en una especie de pequenyo valle rodeado de arboles altisimos por todos "
   "lados que te cierran el paso, solo ves una salida, al noroeste, pero un gran monticulo "
   "de ramas situado al lado de unas rocas llama tu atencion.\n\n");

add_item("ramas","Son un gran monticulo de ramas amontonadas en una esquina al lado de unas grandes rocas, "
                 "estan colocadas a tropel como si alguien quisiera tapar algo debajo o fueran dispuestas asi "
                 "para esconder alguna cosa.\n\n");

add_clone(NPCS+"varios_bosque_harak.c",random(5));

add_exit("noroeste",BOSQUEHARAK+"bos86.c","standard");


}

void init()
{
   ::init();
   add_action("apartar", "aparta*r");  
   add_action("apartar", "separa*r");
}

void apartar(string ramas)
{
   if (!ramas || ramas!="ramas")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }

   write("\nComienzas a apartar con cuidado las ramas que formaban el monticulo, "
   "hasta que delante de ti surge lo que parece la entrada a un pasadizo subterraneo. "
   "Sin pensartelo, bajas con cuidado apoyandote en algunas de las ramas.");
   say(this_player()->query_cap_name()+" comienza a mover y separar las ramas con cuidado y "
   "desaparece de tu vista entre ellas dejandote perplejo.\n");
   call_out("bajar",2);
}
void bajar()
{
   this_player()->move(SUBT+"pas1.c");
   this_player()->look_me();
}
   