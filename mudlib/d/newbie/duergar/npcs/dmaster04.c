#include "path.h"
inherit "obj/monster";

void init() {
   ::init();
   add_action("do_listen","listen");
   call_out("first_approach",0,this_player());
}

void setup() {
   set_name("girthwer");
   add_alias("duergar");
   add_alias("master");
   set_join_fights();
   set_main_plural("masters");
   set_short("girthwer, Master of Lore");
   set_long("   Girthwer Nolen is the Master of the school of Realms "
	    "Lore.  He teaches the final phase for all young Duergar "
	    "students.  He will teach you about all the various "
	    "races of the realms and how to deal with them.\n"
	    "\n");
   set_race("duergar");
   set_guild("fighter");
   set_level(35 + random(10));
   set_thac0(6);
   set_max_hp(600);
   set_max_gp(1000);
   adjust_gp(1000);
   set_heart_beat(1);
   set_gender(1);
   set_al(35);
   set_random_stats(20, 28);
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/armours/chainmail.c")->move(this_object());
   init_equip();
}

int first_approach(object ob) {
   if((int)ob->query_level() != 4) 
     {
      do_command("say You have not earned the right to enter here yet, "
		 "so leave!\n");
      return 1;
     }

   if((int)ob->query_level() == 4) 
     {
      do_command("say So, you have made it this far have you?  "
		 "Well, then come in.  But know this, you may "
		 "not leave alive.\n");
      return 1;
     }
}

int do_listen(string STR) {
   int lv;
   object me = this_player();
   lv = (int)me->query_level();
   
   if(STR == "girthwer") 
     {
      if(lv==4) 
	{
	 do_command("say This is your final test for what "
		    "lies ahead.  Now I'm not going to blow some "
		    "infernal sunshine up your nose as some would "
		    "say.  I'm here to tell you like it is.\n\n"
		    "There are people out there that are going to "
		    "want to kill you.  Why?  Some will say cause "
		    "you're a mage, or a fighter.  But there is "
		    "another reason, CAUSE YOU'RE DUERGAR!\n\n"
		    "Now, these people come from a wide variety of "
		    "races, Orc's, foul humans, ugly elves, even "
		    "our own evil kin, the dwarves.\n\n"
		    "Behind me is a door, and beyond that are "
		    "prisoners that we have captured for your last "
		    "test here at the academy.  One of each race "
		    "is represented.  So, I want you to go in there "
		    "and show them what we think of their stink'n "
		    "hides.  I want you to go in there and show them "
		    "that the duergar are going to rise from the "
		    "depths and smash them under our booted feet.\n");
	 do_command("grin evil");
	 do_command("say By the way, here is a little gift.  It's a "
		    "key, to unlock the path before you.\n");
	    if((random(30) == 21) && (!this_player()->query_property("key")))
	      {
	       clone_object(ITEMS+"qkey5")->move(this_player());
	       this_player()->add_property("key",1);
	      } 
	    else 
	      {
	       if(!this_player()->query_property("key"))
		 {
		  clone_object(ITEMS+"newkey")->move(this_player());
		  this_player()->add_property("key",1);
		 }
	      }
	    return 1;     
	}
      do_command("say Bah!  Leave me be, and go waste someone "
		 "elses time!\n\n");
      return 1;
     }
   return 0;
}
