// hobgoblin

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Hobgoblin");
add_alias("hobgoblin");
set_short("hobgoblin");
set_main_plural("hogoblins");
add_plural("hobgoblins");
set_long("This is a dark red hobgoblin with yellow eyes. Dressed in bright bloody red and black leather.\n");
      set_race("hobgoblin");
set_level(5);
      set_wimpy(0);
      set_random_stats(5, 17);
      set_al(-100+random(10));
adjust_money(4+random(8), "silver");
      load_chat(99,
         ({
                     1, "'Go away!!",
               1, "@grunt",
        1, "'What do you want?"
          }));
      load_a_chat(99,
         ({
         1, "'I'm going to rip out you tongue!!!",
               1, "'Ughh!",
                  1, "Hobgoblin tries to grab your tongue!!!!"
          }));
new(ARMOR+"studded.c")->move(this_object());
new(MISC+"ring.c")->move(this_object());
new(WEAPON+"morning_star.c")->move(this_object());
      this_object()->init_equip();

} /* setup() */
