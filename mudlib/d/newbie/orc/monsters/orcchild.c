// child

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Orc child");
add_alias("child");
set_short("child");
set_main_plural("children");
add_plural("children");
set_long("You see a small orc runt kicking defenseless puppies and kittens.\n");
      set_race("orc");
set_level(1 + random(1));
      set_wimpy(0);
      set_random_stats(5, 12);
      set_al(-100+random(10));
adjust_money(4+random(8), "copper");
new(WEAPON+"knife.c")->move(this_object());
new(ARMOR+"cloak.c")->move(this_object());
command("equip");
      load_chat(99,
         ({
                     1, "'Give or else!!",
               1, "@grunt",
       1, "'Daddy says we got to earn our keep so give us your money!",
        1, "'Please sir money for the poor."
          }));
      load_a_chat(99,
         ({
         1, "'My daddy is gonna get you!!!",
        1, "'Help daddy!! $lcname$ is trying to hurt me!!!",
               1, "'Ughh!",
                  1, "'Your a big bully!!!!"
          }));

} /* void setup() */
