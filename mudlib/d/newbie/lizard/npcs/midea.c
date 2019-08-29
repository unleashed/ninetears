inherit "/obj/monster";
#include "path.h";


static int i = 0;

void init()
{
 ::init();
    if ((int)this_player()->query_property("LIZGEM_QUEST")==0)
    {
        call_out("start_quest", 0, this_player());
    }
 add_action("give_gem", "give");
}

void start_quest(object ob)
{
  write("The shop keeper Midea whispers to you:  "
  "If you find my gem you will be rewarded. "
   "\n\n");
  tell_room(environment(ob), "Midea whispers to "+
            ob->query_cap_name()+".\n", ({ob})); 
  ob->add_property("LIZGEM_QUEST", 1);
}


int give_gem(string str)
{
  object it;
   str = lower_case(str);

if ((str=="gemstone to midea") ||(str=="gem to midea"))
  {
       if(present("gemstone", this_player()))
       {
  write("Midea exclaims: Thank you, finally this hierloom has been "
       "returned to my family.\n"
       "Midea says: May the Gods bless you.\n\n"
   "");
   if(!this_player()->query_property("LIZMIDEA_DONE"))
   {
      write("You feel more experienced.\n");
      //this_player()->adjust_xp(2000);
   }


           this_player()->add_property("LIZMIDEA_DONE", 1);
           it = find_match("gemstone", this_player());
           it->dest_me();
           return 1;
       }
    write("Help if you had a gemstone to give.\n\n");
       return 1;
  }
  return 0;
}

void setup()
  {
	set_name("midea");
	add_alias("midea");
	set_short("Midea");
  set_race("lizard-man");
  set_gender(1);
set_long("This old lizard-man looks as though he has been through"
" hell and back. You could kill him with just your tail."
      "\n\n");

  load_a_chat(20,
	({
	1, "'DIE TRAITOR!!!!!",
	1, "'Leave me alone!",
	1, "'Get out of here, NOW!",
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(8);
  set_wimpy(0);
   clone_object(WEAPON+"guisarme_voulge.c")->move(this_object());
    clone_object(ARMOR+"chainmail.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
