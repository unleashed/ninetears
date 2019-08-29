/*  File upgraded by Grimbrand 2-11-96                                  */

#include "path.h"
inherit "obj/monster";

void init() {
   ::init();
   call_out("first_approach",0,this_player());
}

void setup() {
   set_name("duergar");
   add_alias("Cautivo");
   add_alias("cautivo");
   set_join_fights();
   set_main_plural("cautivos");
   set_short("Duergar cautivo");
   set_long("Como la mayoria, este duergar es de aspecto oscuro y da  "
            "la sensacion de ser muy fuerte.  Tiene el pelo hirsuto, de "
            "color negro azabache,son pelos duros y rectos como agujas. "
            "Se pasea por la habitacion con aire fanfarron, como si el "
            "supiera algo que tu no sabes. Tal vez el tenga algo que "
            "decirte.\n");
   set_race("duergar");
//   add_language("duergar");
//   do_command("speak duergar");
   set_guild("fighter");
   set_level(10);
   set_max_hp(44);
   set_max_gp(30);
   adjust_gp(30);
   set_heart_beat(1);
   set_gender(1);
   set_al(35);
   set_kill_xp(910);
   adjust_money(2,"platino");
   set_random_stats(14,18);
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
   init_equip();
}

void first_approach(object ob) {
   do_command("say humm, asi que crees haber pasado tu pequenya prueba "
              "ya, no?.  Bien veamos como es de bueno realmente este "
              "inocente aprendiz."
              "\n\n");
}
