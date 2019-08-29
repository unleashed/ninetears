/*  File upgraded by Grimbrand 2-11-96                                  */

#include "path.h"
inherit "obj/monster";

void init() {
   ::init();
   call_out("first_approach",0,this_player());
}

void setup() {
   set_name("captive");
   add_alias("duergar");
   add_alias("captive");
   set_join_fights();
   set_main_plural("captives");
   set_short("Duergar captive");
   set_long("As with most duergar, this one is of dark complection and "
            "appears to be very strong.  His hair is jet black and flows "
            "right into his beard to the point that you cant tell one "
            "from the other.  He walks around the room witha swager as "
            "if he knows something that you dont.  Maybe he might have "
            "something to say if you listen.\n");
   set_race("duergar");
   add_language("duergar");
   do_command("speak duergar");
   set_guild("fighter");
   set_level(10);
   set_max_hp(44);
   set_max_gp(30);
   adjust_gp(30);
   set_heart_beat(1);
   set_gender(1);
   set_al(35);
   set_kill_xp(910);
   adjust_money(2,"platinum");
   set_random_stats(14,18);
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   init_equip();
}

void first_approach(object ob) {
   do_command("say Ahh, so you think that you have passed yer little "
              "tests do you now.  Well lets just see how good you really "
              "are."
              "\n\n");
}
