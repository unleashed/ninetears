
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("marius");
set_short("Marius");
set_main_plural("mariuses");
add_plural("mariuses");
 set_long("Marius is a plump elderly halfling.  He has about "
   "him a kind of friendly look, and you know that if you sit here "
   "long enough he will happily chat with you.  "
   "He has short curly brown hair that is swept back from his face, "
   "and his eyes are a soft brown color.  He looks as if he has "
   "a story to tell.\n\n");
 
 set_race_ob("/std/races/halfling.c");
set_random_stats(9,15);
set_level(24);
set_gender(1);
set_guild("fighter");
adjust_money(10+random(10), "silver");
 add_clone("/baseobs/weapons/short_sword.c",1);
 add_clone("/baseobs/armours/braided.c",1);
 this_object()->init_equip();
 load_chat(110, ({
1,({
"'Greetings, $lcname$, what can I get for ya?",
}),
1,"'How goes the life of a brave adventurer?",
1,({
"'Blast it all...  I wish I could remember....",
":rubs his eyes.",
"'Listen here, $lcname$.  If you find some equipment laying around out there, take it.",
"'It'll probably be my sword and armour.  I really don't need them, and you could probably use 'em.",
 "'I know I left them near a big rock.  Then I went to sleep and...",
":shrugs.",
"'Sorry, don't remember what happened after that.",
"'Good luck on finding it, though."}),
1,"'I'd stay away from the North.  Creatures up there are a lot tougher than around here.",
}),
);
}
