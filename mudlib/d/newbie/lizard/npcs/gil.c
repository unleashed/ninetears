inherit "/obj/monster";
#include "path.h"
void setup(){
   set_short("Gilreath");
   set_name("gilreath");
   set_long("Gilreath is the head of the guild here in Sisthih.  He"
            " is a very wize old lizard, for he has seen the outside"
            " world.  Word has it that he has much to teach a young"
            " lizard man.\n");
   set_level(30);
   set_wis(18);
   set_str(18);
   set_con(18);

   load_chat(60,({
     1, "Gilreath says: Welcome to our village!",
     1, "Gilreath says: I wish someone would defeat that swamp"
         " monster.  He has been terrorizing our village for years.",
     1, "Gilreath looks at his list of current guild members.",
     1, "Gilreath says: I hope to see you real soon.",
     1, "Gilreath says: Have you done well trying to advance you skills?",
     1, "Gilreath says: Be careful out in the swamp!",
   }));
}


void init()
{
 ::init();
 add_action("give_head", "give");
}


int give_head(string str)
{
  object it;
object ob;

if ((str=="alligator head to gilreath") ||(str=="head to gilreath"))
  {
       if(present("head", this_player()))
       {

   if(this_player()->query_property("skill_swimming"))
     {
      init_command("'Wow! You found another one.\n");
      return 1;
      }
   init_command("'You have done our village a great deed"
         " by killing that alligator!  He has been terrorizing"
         " us for years.  You are indeed a mighty warrior.  As"
         " a token of my gratitude, I am going to give you this"
         " Amulet of K'Laktaar.  This amulet has mighty powers. "
         " Take care of it.\n");
       ob = clone_object(MISC+"amulet.c")->move(this_player());
           this_player()->add_property("skill_swimming", 1);
           it = find_match("head", this_player());
           it->dest_me();
           return 1;
       }
       write("Help if you had proof to give.\n\n");
       return 1;
  }
  return 0;
}

