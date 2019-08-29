
inherit "/obj/monster";
#include "path.h";

#define MONSIES 2
static int i = 0;

void init()
{
 ::init();
    if ((int)this_player()->query_property("GOLDEN_RING")==0)
    {
        call_out("start_quest", 0, this_player());
    }
 add_action("give_ring", "give");
}

int start_quest(object ob)
{
  write("Crookshank whispers to you:  "
   "I am looking for a golden ring, if you find it for me i will "
  "give you the key to the Gate of Life.\n");
  tell_room(environment(ob), "Crookshank whispers to "+
            ob->query_cap_name()+".\n", ({ob})); 
  ob->add_property("GOLDEN_RING", 1);
}


int give_ring(string str)
{
  object it;

   if ((str=="ring to crookshank")||(str=="gold ring to Crookshank"))
  {
       if(present("gold ring", this_player()))
       {
           write("Crookshank grins greedily at you then whispers:  "
   "Long have I sought for this ring, here is the gate key as I "
 "promised. Take it and leave me be.\n\n");
clone_object(MISC+"key.c")->move(this_player());

           tell_room(environment(this_player()), "Crookshank grins greedily "
               "and gives something to "+this_player()->query_cap_name()+".\n\n", ({this_player()}));

           this_player()->add_property("GATEKEY_DONE", 1);
           it = find_match("gold ring", this_player());
           it->dest_me();
           return 1;
       }
       write("Help if you had a ring to give.\n\n");
       return 1;
  }
  return 0;
}

void setup() {
   set_name("crookshank");
   set_short("Crookshank the sly");
set_long("This is Crookshank the sly, he is a very quick and "
   "dexterous goblin. His eyes seem to take in everything. "
   "You probably will not be able to pull anything over on him.\n");
set_race("goblin");
set_gender(1);
set_level(10 + random(6));
      set_wimpy(0);
      set_random_stats(9, 18);
      set_al(-100+random(201));
adjust_money(2+random(8), "silver");
      load_chat(90,
         ({
               1, "' Do you like riddles ?",
               1, "'Do you seek the key?"
          }));
      load_a_chat(80,
         ({
               1, "'YOU'RE GONNA DIE FOR THIS.",
               1, "'I'm going to mess you up $acname$",
               1, "'Ughh!",
               1, "'Don't you dare leave in the middle of my fight!"
          }));
      if(random(2))
	 new("/baseobs/armours/chainmail")->move(this_object());
      else
	 new("/baseobs/armours/ringmail")->move(this_object());
  new(WEAPON+"short_sword.c")->move(this_object());
  new(WEAPON+"short_sword.c")->move(this_object());
      this_object()->init_equip();

} /* setup() */
