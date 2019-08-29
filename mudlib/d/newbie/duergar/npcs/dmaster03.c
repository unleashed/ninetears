#include "path.h"
inherit "obj/monster";

void init() {
  ::init();
    add_action("do_listen","listen");
    call_out("first_approach",0,this_player());
}

void setup() {
   set_name("caradoc");
   add_alias("duergar");
   add_alias("master");
   set_join_fights();
   set_short("caradoc, Cavern Master");
   set_long("   Caradoc Zarokov is the Cavern Master.  Many years has "
	    "he been here imparting his knowledge to young duergar.  "
	    "He is here to teach you of the dangers of the "
	    "underdark.\n"
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
   if( (int)ob->query_level() !=3 )
     {
      do_command("say Get out of here, you have no business being "
		 "in here...and dont come back!\n\n");
      return 1;
     }

   if( (int)ob->query_level() ==3 )
     {
      do_command("say Come in, I have been waiting for you.\n\n");
      return 1;
     }
}

int do_listen(string STR) {
   int lv;
   object me = this_player();
   lv = (int)me ->query_level();

   if(STR == "caradoc") 
     {
      if(lv == 3) 
	{
	 do_command("say So its the tunnels ye want to be hear'n "
		    "about is it?  Well, I must say, you have "
		    "come to the right place.\n"
		    "Lets see now, ah yes.\n\n"
		    "The Underdark, this is all that lies beyond "
		    "the civilized areas of Dendall.  A cruel place "
		    "it is.\n\n"
		    "YET, we share this place with others as well.  "
		    "There are many a dangerous creature just "
		    "waiting for an unsuspecting snack to wander "
		    "by.\n\n"
		    "Now then, beyond the doors to the northeast, "
		    "there are some of the creatures that you will "
		    "find wandering the Underdark.  Granted, most "
		    "of them are not in the same condition as when "
		    "I found them, but at least they will give you "
		    "an idea of what you can expect to find beyond "
		    "Dendall.  Such things as Hook Horrors, Hell "
		    "Hounds, Umber Hulks, and those pesky Drow.  "
		    "Oh, I'm rambling, the Drow are a diffrent "
		    "problem, but you'll learn of that soon "
		    "enough.\n");
	 if(this_player()->query_guild_name() == "Abbathor") 
	   {
	    if((int)this_player()->query_property("CARGOT")!=1)
	      {
	       this_player()->add_property("CARGOT",1);
	       this_player()->adjust_money(1,"platinum");
	       this_player()->adjust_money(5,"gold");
	      }
	   }
	 return 1;
	}
      do_command("say I have no time to waste, LEAVE!\n");
      return 1;
     }
   return 0;
}
