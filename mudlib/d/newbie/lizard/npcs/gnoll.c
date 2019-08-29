// gnoll

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Gnoll");
add_alias("gnoll");
set_short("gnoll");
set_main_plural("gnolls");
set_long("This creature is humanoid to a degree. It has greenish "
    "gray skin, with a dull yellow mane. Its eyes are dull black "
   "and its nails are amber colored. "
   "\n\n");
      set_race("gnoll");
set_level(3+random(3));
      set_wimpy(0);
      set_random_stats(5, 14);
      set_al(-100+random(10));
adjust_money(4+random(8), "gold");
      load_chat(99,
         ({
                     1, "'You look like an easy victim.",
               1, "@grunt",
        1, "'Wanna fight?"
          }));
      load_a_chat(99,
         ({
         1, "'I'll show you!!!",
               1, "'Ughh!",
                  1, "Gnoll tries to pull your head off"
          }));
new(ARMOR+"leather.c")->move(this_object());
new(WEAPON+"flail.c")->move(this_object());
      this_object()->init_equip();

} /* setup() */
