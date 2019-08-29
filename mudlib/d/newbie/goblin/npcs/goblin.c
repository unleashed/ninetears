// hobgoblin

inherit "/obj/monster";
#include "path.h"

void setup() {
    set_name("Goblin");
    add_alias("goblin");
    set_short("goblin");
    set_main_plural("goblins");
    add_plural("goblins");
    set_long("This is a dull orange goblin with red eyes. Dressed in "
      "dark soiled leather.\n");
    set_race("goblin");
    set_level(3);
    set_wimpy(0);
    set_random_stats(5, 14);
    set_al(-100+random(10));
    adjust_money(2+random(4), "gold");
    load_chat(99,
      ({
	1, "@spits",
	1, "@grunt",
	1, "'Wanna fight?"
      }));
    load_a_chat(99,
      ({
	1, "'I'll show you!!!",
	1, "'Ughh!",
	1, "Goblin tries to hurt you"
      }));
    new(ARMOR+"leather.c")->move(this_object());
    new(WEAPON+"dagger.c")->move(this_object());
    this_object()->init_equip();

} /* setup() */
