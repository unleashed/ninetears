// A large bugbear guard

inherit "/obj/monster";
#include "path.h"

#define MONSIES 2
static int i = 0;

void init()
{
 ::init();
    if ((int)this_player()->query_property("SWORD_QUEST")==0)
    {
        call_out("start_quest", 0, this_player());
    }
 add_action("give_sword", "give");
}

void start_quest(object ob)
{
  write("The bartender G'nash whispers to you:  "
  "If you find my sword you will be rewarded. "
   "\n\n");
  tell_room(environment(ob), "G'nash whispers to "+
            ob->query_cap_name()+".\n", ({ob})); 
  ob->add_property("SWORD_QUEST", 1);
}


int give_sword(string str)
{
  object it;

 if ((str=="sword to g'nash") ||(str=="sawtooth sword to g'nash") || (str=="sword to G'nash") || (str=="sawtooth to g'nash"))
  {
       if(present("sawtooth sword", this_player()))
       {
write("G'nash points to a chainmail on the floor and says "
  "take this armour for finding my sword and use it well.\n"
"\n\n");
   clone_object(ARMOR+"chainmail.c")->move(environment(this_object()));

           tell_room(environment(this_player()), "G'nash gives some "
               "armour to "+this_player()->query_cap_name()+".\n\n", ({this_player()}));

           this_player()->add_property("GNASH_DONE", 1);
           it = find_match("sawtooth sword", this_player());
           it->dest_me();
           return 1;
       }
       write("Help if you had a sword to give.\n\n");
       return 1;
  }
  return 0;
}

void setup() {
set_name("G'nash");
add_alias("g'nash");
set_short("g'nash");
set_main_plural("bar keeps");
	set_long("This is the bartender, G'nash.  G'nash is a strong "
		"Goblin male with dirt and beer covering most of his "
  "body. He is a very famous goblin fighter, who won much fame "
   "in the great Dwarven wars. He seems disturbed about something "
  "though, maybe he will tell you. He has been quite drunk lately, "
  "which most veterans from the war are.\n");
      set_race("goblin");
set_gender(1);
set_level(12);
      set_wimpy(0);
      set_random_stats(9, 18);
      set_al(-100+random(201));
adjust_money(2+random(8), "silver");

 
load_chat(70,
({
1, ":burps.",
  1, ":says: 'Have you seen my sword? I seem to have missplaced it.'",
  1, ":says: 'Me and my buddy went out to drink some ale and I lost him and my sword.'",
        1, ":cleans off the counter with a towel.",
               1,"'What will it be?"
   }));
load_a_chat(100,
({
        1, ":howl with pain.",
        1, ":tries to hurt you.",
        1, ":tries to kill you",
   }));
new(ARMOR+"ringmail")->move(this_object());
new(WEAPON+"club")->move(this_object());
      this_object()->init_equip();

} /* setup() */
