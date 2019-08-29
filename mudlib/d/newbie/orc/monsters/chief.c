//Orc chieftan
//tek

inherit "/obj/monster";
#include "path.h"

#define MONSIES 2
static int i = 0;

void init()
{
 ::init();
    if ((int)this_player()->query_property("LETTER_QUEST")==0)
    {
        call_out("start_quest", 0, this_player());
    }
 add_action("give_crown", "give");
}

void start_quest(object ob)
{
  write("The Orc Chieftain whispers to you:  "
 "One day when you prove worthy you will be able to leave this place. "
   "\n\n");
  tell_room(environment(ob), "Orc chieftan whispers to "+
            ob->query_cap_name()+".\n", ({ob})); 
  ob->add_timed_property("LETTER_QUEST",1,30000);
}


int give_crown(string str)
{
  object it;

 if ((str=="crown to chieftain") ||(str=="crown to chief") ||(str=="crown to orc") || (str=="crown to orc chief") || (str=="crown to chief orc"))
  {
       if(present("crown", this_player()))
       {
write("Orc chieftain puts the crown on his head and gives you "
      "a letter.\n\n\n"
      "Orc Chieftain tells you: Use this letter to leave out the "
      "gate in the town.\n\n");
   clone_object(MISC+"letter.c")->move(this_player());

           tell_room(environment(this_player()), "Orc Chieftain gives a "
"letter to "+this_player()->query_cap_name()+".\n\n", ({this_player()}));

           this_player()->add_property("LETTER_DONE", 1);
           it = find_match("crown", this_player());
           it->dest_me();
           return 1;
       }
   write("Help if you had a crown to give.\n\n");
       return 1;
  }
  return 0;
}

void setup() {
set_name("Orc Chieftain");
add_alias("chieftain");
add_alias("chief");
set_short("orc chieftain");
set_main_plural("chieftains");
  set_long("This is a really large orc, he has scars all over "
      "his face and arms. Looks like it is not easy being chief. "
      "He looks really impressive and strong, you can see why "
   "he is chief.\n\n");
      set_race("orc");
set_gender(1);
 set_guild("fighter");
set_level(18);
      set_wimpy(0);
      set_random_stats(9, 18);
      set_al(-100+random(201));
adjust_money(2+random(8), "silver");

 
load_chat(80,
({
 1,"'Kneel down in respect before me!",
 1,"'Wheres that dang crown? Hasn't anyone found it yet?",
  1,"'If you want some respect from me find the crown of the "
        "last ruler of this place.",
  1,"'If you don't have my crown go away before I crush you!",
  1,"'Go away or my guards will throw you into the dungeon!",
   }));
load_a_chat(100,
({
   1, ":screams: Die Traitor!",
        1, ":tries to hurt you.",
        1, ":tries to kill you",
   }));
new(ARMOR+"chainmail")->move(this_object());
new(WEAPON+"morning_star")->move(this_object());
      this_object()->init_equip();

} /* void setup() */
