#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }
void setup()
{
  set_name("leader");
  add_alias("elf");
  add_alias("Captive");
  add_alias("captive");
  add_alias("Elf");
  set_short("captive Leader");
  set_gender(random(2)+1);
  set_long("   The leader of the captives stands before you, "
           +this_object()->query_possessive()+" delicate elfin "
           "features hardening as "
           +this_object()->query_pronoun()+" stares at you with hate "
           "and distrust.  "
           +capitalize(this_object()->query_possessive())+" armour and "
           "clothes "
           "are in excellent shape, although they are slightly too big "
           "for "
           +this_object()->query_possessive()+" slight frame;  the "
           "poor fool "
           +this_object()->query_pronoun()+" killed for them in this "
           "maze of a prison has no need for them now.  "
           +capitalize(this_object()->query_pronoun())+" crosses "
           +this_object()->query_possessive()+" arms in front of "
           +this_object()->query_possessive()+" chest, awaiting your "
           "next move."
           "\n\n");
  set_main_plural("Captive Leaders");
  set_race("elf");
  set_guild("fighter");
  set_random_stats(10,15);
  set_aggressive(0);
  set_level(6+random(3));
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
     1,":taunts you, confident in "+this_object()->query_possessive()+" strength.",
     1,"'I have not endured this prison to be killed by you.",
 
  }));
}
