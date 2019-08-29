#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }
void setup()
{
  set_name("leader");
  add_alias("elf");
  add_alias("Captive");
  set_short("Captive Leader");
  set_long("   The leader of the captives stands before you, her delicate "
           "elfin features hardening as she stares at you with hate and "
           "distrust.  Her armour and clothes are in excellent shape, "
           "although they are slightly too big for her slight frame; the "
           "poor fool she killed for them in this maze of a prison has "
           "no need for them now.  She crosses her arms in front of her "
           "chest, awaiting your next move.\n");
  set_main_plural("Captives");
  set_gender(2);
  set_race("elf");
  set_guild("fighter");
  set_random_stats(10,15);
  set_aggressive(0);
  set_level(8);
  set_max_hp(40);
  set_wimpy(0);
  set_align(-1500);
  set_ethics(-1000);
  adjust_money(random(30),"silver");
  clone_object(WEAPON+"scimitar.c")->move(this_object());
  this_object()->init_equip();
clone_object(ARMOUR+"chainmail.c")->move(this_object());
  this_object()->init_equip();
    clone_object(ITEM+"shackles.c")->move(this_object());
 
   add_language("elf");
   do_command("speak elf");
  load_chat(30,({
     1, ":scoffs.",
     1, "' The drow will need to do much more than this to break my spirit.",
     1, ":sneers at you with utter disgust.",
     1, "'We shall escape.  We prefer to do it without killing you, "
        "but that is your option.\n",
     1, "'Your people shan't be safe here for long.\n",
     1, "'I have freed most of the captives.  They are gathering "
        "reinforcements for an attack.",
     1, "'You are hardly even a challenge for me."
  }));
 
  load_a_chat(25, ({
     1, ":points at you, and then at the exit.",
     1, ":draws blood.",
     1, ":gracefully dodges your clumsy attacks.",
     1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
     1, ":spits at your feet.",
     1,":taunts you, confident in her strength.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
