// whimpy kobold

inherit "/obj/monster";
#include "path.h"

void setup() {
set_name("Bentneck");
add_alias("bentneck");
set_short("Bentneck");
set_long("A skinny half-starved kobold, he is covered in dirt and grime, only a problem in large numbers.\n");
      set_race("kobold");
set_level(7 + random(1));
 set_gender(1);
      set_wimpy(0);
      set_random_stats(9, 14);
      set_al(-100+random(10));
adjust_money(25+random(8), "copper");
      load_chat(90,
         ({
               1, "'The key!! The key!! The key!!!!!",
               1, "@grunt",
          1, "' Are you looking for the key?",
              1,"'You must follow the water to find you passage to manhood!!!"
          }));
      load_a_chat(80,
         ({
               1, "'YOU'RE GONNA TASTE GOOD.",
               1, "'Let's see who's boss here $acname$",
               1, "'Ughh!",
                 1, "'I was wrong to help you!!!!!!"
          }));
      if(random(2))
new(ARMOR+"cloak.c")->move(this_object());
      else
new(ARMOR+"leather.c")->move(this_object());
   new("/d/newbie/goblin/weapons/fork.c")->move(this_object());
      this_object()->init_equip();

} /* setup() */
