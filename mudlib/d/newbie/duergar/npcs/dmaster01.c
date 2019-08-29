/*   Text upgrade by Grimbrand 2-1-96                              */

#include "path.h"
inherit "obj/monster";

void init() {
    ::init();
    add_action("do_listen","listen");
    call_out("first_approach",0,this_player());
}

void setup() {
    set_name("helden");
    add_alias("duergar");
    add_alias("master");
    set_join_fights();
    set_main_plural("masters");
    set_short("Helden, Master of the Mines");
    set_long("\n     Helden Hewen is the Master of The School of Mining.  "
      "He is the one that all new Duergar come to see for their "
      "initial training.\n"
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
    adjust_money(3,"platinum");
    clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
    clone_object("/baseobs/armours/chainmail.c")->move(this_object());
    init_equip();
}

void first_approach(object ob) {
    if((int)ob->query_level() > 1) {
        do_command("say You have long since completed your training here, "
          "so leave and dont look back.\n");
    }
    if((int)ob->query_level() == 1) {
        do_command("say Ahh, a new recruit.  Please come in, we must start your "
          "training right away.\n");
    }
    if((int)ob->query_level() == 0) {
        do_command("say Alas my young fellow, you need to go to the guild and "
          "advance before I can begin your training.\n");
    }
}

int do_listen(string STR) {
    int lv;
    object me = this_player();
    lv = (int)me->query_level();

    if(STR == "helden")
    {
        if(lv == 1)
        {
            do_command("say Well now, where should I begin?  I guess YOU would "
              "like it best if I made my little lesson short and sweet, "
              "WOULDN'T you?\n\n"
              "   Well, you're in luck. I really don't feel like bothering "
              "with any students right now, so here is what you are going "
              "to need to do.  Take this pick, and go through the door "
              "behind me.  Past that door you will find 5, errrrrr, 4 "
              "rooms with rocks in them.  I need you to pick those rock's "
              "into useable blocks.\n\n"
              "   Now, you are free to leave at any time that you feel "
              "that your progress is to your satisfaction, OR you break "
              "my pick!  If you do indeed break the pick, you may as well "
              "leave.  As far as I am concerned any Duergar that can't "
              "keep their own gear in working condition doesn't need to "
              "be here!\n\n"
              "WELL?  Be off with ye .....\n"
            );
            if(!this_player()->query_property("got_pick"))
                clone_object(ITEMS+"pick")->move(this_player());

            if(this_player()->query_guild_name() == "Abbathor")
            {
                if((int)this_player()->query_property("got_pick")!=1)
                {
                    this_player()->adjust_money(4,"platinum");
                    this_player()->add_property("got_pick", 1);
                    return 1;
                }
            }
            else
            {
                if((int)this_player()->query_property("got_pick")!=1)
                {
                    this_player()->adjust_money(2,"platinum");
                    this_player()->add_property("got_pick", 1);
                    return 1;
                }
            }
            return 1;
        }
        do_command("say I haven't the time to waste upon the likes of you!\n");
        return 1;
    }
    return 0;
}
