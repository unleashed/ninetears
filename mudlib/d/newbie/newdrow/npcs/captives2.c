#include "path.h"
inherit "obj/monster";
 
void setup()
{
  set_name("captive");
  add_alias("dwarf");
  add_alias("Captive");
  set_short("Dwarf Captive");
  set_long("   Thin wrinkles of worry and fear line the small dwarf's "
           "face as he warily eyes you over and awaits further insult.  "
           "Torn rags, tied together, form some semblance of a garment. "
           "The bedraggled beard and hopeless eyes bespeak that the "
           "time this dwarf has spent here has worn him down greatly.\n");
  set_main_plural("Captives");
  set_gender(1);      
  set_race("dwarf");
  set_guild("fighter");
  set_random_stats(10,13);
  set_aggressive(0);
  set_level(4);
  set_max_hp(15);
  set_wimpy(0);
  set_al(0);
  //set_kill_xp(400);
  set_align(-500);
  set_ethics(-1000);
  clone_object(OBJ+"dagger.c")->move(this_object());
  this_object()->init_equip();
    clone_object(ITEM+"shackles.c")->move(this_object());
 
   add_language("dwarf");
   do_command("speak dwarf");
  load_chat(30,({
     1, ":shudders in horror.",
     1, ":stares blankly at your feet.",
     1, ":faints from fatigue and lack of food.",
     1, ":stands unsteadily, leaning on the walls for support.",
     1, ":looks around with eyes void of hope.",
     1, "'Kill me -- I have no power to live or fight any longer.",
     1, ":trembles from all he has endured.",
     1,":sighs with a broken spirit and heavy heart."
  }));
 
  load_a_chat(25, ({
     1, "'If this is the future of the drow race, the surface "
        "can rest easily.",
     1, ":breathes raspily, gasping for air.",
     1, ":screams in pain and clutches his heart.",
     1, "'My god, does the terror never end?",
     1, "'I have no spirit with which to fight you.",
     1,"'Leave me be.  I pose you no threat."
     
  }));
}
