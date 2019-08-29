/*  Updated and corrected by Grimbrand 2-2-96                             */

#include "path.h"
inherit "obj/monster";

void init() {
    ::init();
    add_action("do_listen","listen");
    call_out("first_approach",0,this_player());
}

void setup() {
    set_name("barog");
    add_alias("duergar");
    add_alias("master");
    set_join_fights();
    set_main_plural("masters");
    set_short("barog, Master of Surface Expeditions");
    set_long("   Barog Blackfist is the Master of the School of "
      "Surface Expeditions.  He teaches second phase Duergar "
      "students about some of the various creature that can be "
      "encountered on the surface.  He himself has encountered "
      "a great many of these evil beasts.\n"
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

void first_approach(object ob) {
    if((int)ob->query_level() !=2) 
    {
        do_command("say Get out of here....I do not have time to waste on "
          "the likes of you.\n"
          "\n");
    }
    if((int)ob->query_level() == 2) 
    {
        do_command("say It's about time that you got here!\n");
    }
}

int do_listen(string STR) {
    int lv;
    object me = this_player();
    lv = (int)me->query_level();

    if(STR == "barog") 
    {
        if(lv == 2) 
        {
            do_command("say Aye, so yer want'n a little know how of "
              "the surface do ya?  Well, I'll give it to ya then.\n"
              "The surface world is an evil and unpredictable place, "
              "it is.  There, every day, a huge orb of blinding light "
              "rises into the sky blinding you and hindering your "
              "every move.  Its a wonder that those who live under it "
              "their entire lives are not consumed by it.\n"
              "Then when the ball of fire is gone, another comes to "
              "replace it, yet it is a false one.  It is never the same "
              "twice.  Always changing that one is ... ");

            do_command("say The land is strange as well, everywhere "
              "you go it is different.  Some places there are great "
              "plants that can only grow with the orb of fire from the "
              "sky, and in some places there is only plains of sand that "
              "burn.  Even worse than that, there is a place where all "
              "you can see is water.  I have found that you can travel "
              "across it, but it only invites death, for it always tries "
              "to swallow you into its depths.\n"
              "Now, as for your lesson, I have just returned from the "
              "surface and brought with me some creature that I captured. " 
              "Go through the Northwest door here and see just how ye "
              "will fair on the surface, if your foolish enough to go "
              "there.");

            if(this_player()->query_guild_name() == "Abbathor")
            {
                if((int)this_player()->query_property("BAROG_GOT")!=1)
                {
                    this_player()->add_property("BAROG_GOT", 1);
                    this_player()->adjust_money(3,"platinum");
                    return 1;
                }
            }
            return 1;
        }
        do_command("say I have no reason to talk with you!\n");
        return 1;
    }
    return 0;
}
