/*  Text alterations and additions by Grimbrand 2-11-96                 */

#include "path.h"
inherit "obj/monster";
object *obs;

void init() {
  ::init();
    call_out("first_approach",0,this_player());
    add_action("do_listen","listen");
}

void setup() {
   set_name("duggan");
   add_alias("master");
   add_alias("duergar");
   set_join_fights();
   set_main_plural("masters");
   set_short("duggan, Master of Apprentices");
   set_long("  \n"
            "   Duggan Bloodaxe is the Master of Apprentices"
            " in Dendall.  Young duergar come to him for advice"
            " on how to gain valuable experience."
            "\n\n");
   set_race("duergar");
   set_guild("fighter");
   set_join_fight_mess("Duggan's eyes shine with anticipation."
                       " Without a word, he attacks!\n");
   set_level(55 + random(10));
   set_thac0(-4);
   set_max_hp(1500);
   set_max_gp(1000);
   adjust_gp(1000);
   set_heart_beat(1);
   set_gender(1);
   set_al(0);
   set_random_stats(20, 28);
        
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/armours/chainmail.c")->move(this_object());
   init_equip();
}

int first_approach(object ob) {
   if( (int)ob->query_level() <=1 )
     {
      do_command("say You need to go the Mine Masters Office.  He will "
                 "train you for your first level here at the Dendall "
                 "academy."
                 "\n\n");
      return 1;
     }

   if( (int)ob->query_level() ==2 )
     {
      do_command("say Go to the Surface Exploration Office, there the "
                 "Master will introduce you to various creature from the "
                 "surface.  Not that any Duergar should ever want to "
                 "go there."
                 "\n\n");
      return 1;
     }

   if( (int)ob->query_level() ==3 )
     {
      do_command("say Goto to the Cavern Masters Office.  He will "
                 "show you the different kinds of creatures that "
                 "roam the underdark.  This will be your third phase of "
                 "training here at the academy.\n");
      return 1;
     }

   if( (int)ob->query_level() ==4 )
     {
      do_command("say This is your final phase of training here at the "
                 "academy.  Go to the Lore Masters Office, there you "
                 "will be instructed on the different races you might "
                 "encounter on your travels.  Good luck."
                 "\n\n");
      return 1;
     }

   if((int)ob->query_level() >=5) 
     {
      do_command("say Leave now.  You have no business here.  So dont make "
                 "it mine to remove you."
                 "\n\n");
      return 1;
     }
}

int do_listen(string STR) {
   if(STR == "duggan") 
     {
      do_command("say Grimbrand help us!  Another hot blooded youngster "
                 "wanting to enter the academy eh?\n\n"
                 "Do you understand the choice that you are making?  By "
                 "entering this school, you are devoting yourself to "
                 "Grimbrand, God of the Duergar.\n\n"
                 "Do you also know that you might not make it through "
                 "in one piece?  Many a young duergar have I seen come "
                 "through here as you do, only to end up dead or maimed "
                 "for life.  The tests here are designed to weed out "
                 "those who do not belong, so beware!\n\n"
                 "If you think that you are up to the task, then may "
                 "Grimbrand be with you!  You'll need everything "
                 "he can bestow upon you to make it through alive."
                 "\n\n");
      do_command("cackle");
      return 1;
     }
return 0;
}
