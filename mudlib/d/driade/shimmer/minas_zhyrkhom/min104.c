/* By Shimmer */

#include "../path.h"
inherit "/std/underground";

void setup() {

   set_exit_color("yellow");
   set_zone("mina");
   set_light(30);
   set_short("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^\n\n"
   "Te encuentras en uno de los tuneles de las Minas Zhyrhom, el tunel es amplio "
   "y esta bien iluminado, hay antorchas en la pared de toda la mina. Puedes ver "
   "como las paredes fueron excavadas en la roca para obtener algun tipo de material, "
   "hay numerosas vigas de madera por todos lados soportando el techo para que no se venga abajo "
   "y un grupo de tablas apiladas en una de las esquinas de la pared norte del tunel.\n\n");


add_item("tablas","Un grupo de tablas de madera de unos metros de largo apiladas contra la pared, "
                 "con un poco de esfuerzo podrias apartarlas.\n\n");

add_clone(NPCS+"varios_mina_zhyrkhom.c",random(2));
add_clone(NPCS+"minero_mina_zhyrkhom.c",random(2));

add_exit("sudoeste",ZHYRKHOM+"min105.c","standard");
add_exit("sur",ZHYRKHOM+"min103.c","standard");

}

void init()
{
   ::init();
   add_action("apartar", "aparta*r");  
   add_action("apartar", "separa*r");
   add_action("apartar", "quita*r");
   add_action("apartar", "mover");
}

void apartar(string tablas)
{
   if (!tablas || tablas!="tablas")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }

   write("\nComienzas a apartar con cuidado las tablas con la mala suerte de que "
   "una de ellas se te escurre y golpea una de las vigas que soportaban el techo, "
   "esta cae y golpea el suelo, todo comienza a temblar...\n\n"
   "El suelo se deshace a tus pies y caes unos metros cayendo en una especie de pasadizo.\n\n");

   say(this_player()->query_cap_name()+" intenta mover una tabla pero se le cae, todo comienza a temblar y " 
   "desaparece de tu vista entre tanto polvo dejandote asombrado.");
  
   call_out("bajar",3);
}
void bajar()
{
   
   this_player()->move(SUBT+"pas39.c");
   this_player()->look_me();

   write("\nTe golpeas fuertemente la cabeza al caer desde lo alto del tunel.\n\n");
   this_player()->adjust_hp(- 15);
}   