// whimpy kobold

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Kobold");
add_alias("kobold");
set_short("kobold");
set_main_plural("kobolds");
add_plural("kobolds");
set_long("A skinny half-starved kobold, only a problem in large numbers.\n");
      set_race("kobold");
set_level(5 + random(1));
      set_wimpy(20);
      set_random_stats(9, 14);
      set_al(-100+random(10));
add_protect("kobold");
adjust_money(2+random(8), "copper");
      load_chat(90,
         ({
 1, "@spits $hcname$",
               1, "@grunt",
               1, "'Are you trying to provoke me ?",
              1, "'You look plump!!"
          }));
      load_a_chat(80,
         ({
               1, "'YOU'RE GONNA TASTE GOOD.",
 1, "'Let's see who's boss here $hcname$",
               1, "'Ughh!",
                  1, "'Get him guys!!!!"
          }));
      if(random(2))
new(ARMOR+"cloak.c")->move(this_object());
      else
new(ARMOR+"leather.c")->move(this_object());
   new("/d/newbie/goblin/weapons/fork.c")->move(this_object());
      this_object()->init_equip();

} /* setup() */
