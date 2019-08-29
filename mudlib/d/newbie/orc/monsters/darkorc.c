//Dark orc
//tek

inherit "/obj/monster";
#include "path.h"

#define MONSIES 2
static int i = 0;

void init()
{
 ::init();
    if ((int)this_player()->query_property("DEMON_QUEST")==0)
    {
        call_out("start_quest", 0, this_player());
    }
 add_action("give_head", "give");
}

void start_quest(object ob)
{
  write("The Dark Orc whispers to you:  "
   "If you find me a demon's head for my experiments, you will "
  "be rewarded.\n\n"
   "\n\n");
  tell_room(environment(ob), "The Dark Orc whispers to "+
            ob->query_cap_name()+".\n", ({ob})); 
  ob->add_timed_property("DEMON_QUEST",1,30000);
}


int give_head(string str)
{
  object it;

 if ((str=="demon head to dark orc") ||(str=="head to orc") ||(str=="head to dark orc"))
  {
       if(present("demon's head", this_player()))
       {

  if (this_player()->query_property("HEAD_DONE")==0)
{
   write("The Dark orc takes the head from you and makes an "
     "evil laugh.\n The Dark Orc says: Here take this sword in "
    "payment for your service to me.\n\n"
    "You feel more experienced.\n\n"
"\n");
   clone_object(WEAPON+"orc_sword.c")->move(this_player());
// Taniwha NO XP stuff.
  //this_player()->adjust_xp(3000);

           tell_room(environment(this_player()), "The Dark Orc gives a "
"sword to "+this_player()->query_cap_name()+".\n\n", ({this_player()}));

           this_player()->add_timed_property("HEAD_DONE", 1,30000);
           it = find_match("demon's head", this_player());
           it->dest_me();
           return 1;
 }
   write("Hmmmmm, I don't need another Demon's head.\n\n");
   return 1;
       }
   write("Help if you had a demon head to give.\n\n");
       return 1;
  }
  return 0;
}

void setup() {
set_name("Dark Orc");
add_alias("orc");
add_alias("dark orc");
set_short("A Dark Orc");
set_main_plural("dark orcs");
  set_long("This orc is really dark and foreboding, you can feel "
     "the evil coming from him. He's wearing a dark hooded "
   "robe, which shrouds his face. When you happen to get a glance "
   "under his hood at his eyes it sends chills down your spine.\n");
      set_race("orc");
set_gender(1);
 set_guild("fighter");
set_level(18);
      set_wimpy(0);
      set_random_stats(13, 18);
      set_al(100+random(201));
adjust_money(2+random(8), "silver");

 
load_chat(80,
({
 1,"'Blood, give me some blood!",
  1,"'You haven't seen a demon have you?",
   1,"'A demon's head, thats what i need, you haven't got one do you?",
  1,"'Go away before I eat your heart!",
   }));
load_a_chat(100,
({
   1, ":screams: Die Weakling!",
        1, ":tries to hurt you.",
   }));
new(ARMOR+"chainmail")->move(this_object());
new(WEAPON+"morning_star")->move(this_object());
      this_object()->init_equip();

} /* void setup() */
