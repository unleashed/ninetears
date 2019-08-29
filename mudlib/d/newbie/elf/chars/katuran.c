#include "library.h"
inherit "/obj/monster";
 
void setup() {
 
  //add_attack("hands", 0, 50, 200, 0, 0, "blunt-hands");
  //add_attack("feet", 0, 50, 200, 0, 0, "blunt-feet");
  set_name("katuran");
  add_alias("elf");
  add_alias("darktreader");
  set_main_plural("elves");
  set_short("Katuran");
  add_property("determinate", "");
  set_long(
		"This is Katuran the cafe owner.  Although he may "
		"appear to be a mild mannered elf, he was once one "
		"of the finest elf warriors in the realms.  It would "
		"not be a good idea to start a fight in his cafe.\n");
  set_race("elf");
  set_gender(1);
  set_guild("fighter");
  set_level(30);
  set_wimpy(0); 
  set_random_stats(6,28);
  call_out("remove_attack",0,"standard");
  //set_join_fights("Katuran shouts: STOP THAT FIGHT!\n");
  set_throw_out(30,70,"$mcname$ chucks you bodily out of the room.\n",
                  "$mcname$ chucks $ocname$ out of the room.\n");
  load_chat(1,({
    1, ":eyes you over.",
    1, "'No trouble please.",
    1, ":clenches his fist.",
    1, "'Let's have no fights in here."
  }));
  load_a_chat(30,({
    1, "'Stop that fight.",
    1, "'Next one to break a chair gets it.",
    1, "'You're going to be billed for this."
  }));
  /* Addind a weapon.. so that hw is doing any damage.. 
   * Baldrick. */
 clone_object("/baseobs/weapons/club.c")->move(this_object());
 command("equip");
}

int heart_beat() {
  string s1, s2;
  object *atts;

  atts = query_attacker_list();
  switch(sizeof(atts)) {
    case 1:
      s1 = (string)atts[0]->query_name();
      if (s1 == "virien" || s1 == "garth") {
        stop_fight(atts[0]);
        atts[0]->stop_fight(this_object());
      }
      break;
    case 2:
      s1 = (string)atts[0]->query_name();
      s2 = (string)atts[1]->query_name();
      if((s1=="delimbiyr" || s1 == "virien") && (s2=="delimbiyr" 
        || s2=="virienn"))
      {
        stop_fight(atts[0]);
        atts[0]->stop_fight(this_object());
        stop_fight(atts[1]);
        atts[1]->stop_fight(this_object());
      }
      break;
  }
  ::heart_beat();
}

int second_life() {
  int loop;
  object *atts;

  atts = query_attacker_list();
  return 0;
}

void event_death(object dier) {
  call_out("get_from_corpse", 0);
}

void get_from_corpse() {
  command("'Ahhh!  These will make good trophies for the cafe.");
  command("get all from corpses");
}
