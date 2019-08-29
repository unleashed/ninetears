inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("hermit");
	set_short("Hermit");
  set_race("dwarf");
  set_gender(1);
	set_long("This is an old and dirty hermit.  His frail old "
		"body is covered with thick brown hair.  He looks "
		"tired and hungry."
		"\n\n");

     load_chat(140,
     ({
    1, "'I am so hungry.",
      1, "Hermit looks at you expectantly.",
      1, "Hermit rubs his stomach and grumbles.",
      1, "Hermit searches around the room a bit.",

     }));
  load_a_chat(100,
	({
    1, "You will never learn!",
    1, "You have made a big mistake!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!",
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(8);
  set_wimpy(0);
   clone_object(WEAPON + "drift_wood.c")->move(this_object());
   clone_object(ARMOR + "cloak2.c")->move(this_object());
   command("equip");
}
void init()
{
  add_action("do_give","give");
   ::init();
}
int do_give(string str)
{
   object * olist;
   if(str == "bread to hermit")
   {
      olist = find_match("bread",this_player());
      if(!sizeof(olist))
      {
          write("You don't have any bread for me, stop tormenting me, I'm so hungry.\n");
         return 1;
      }
      else 
      {
         this_player()->add_property("skill_rope_climbing",1);
         write("The old hermit sits down and in gratitude tells you stories "
      "of his younger days spent climbing the mountains round here.\n"
      "You feel that you have learned something of importance, just listening to him.\n");
      olist[0]->dest_me();
      return 1;
      }
   }
      write("The old hermit looks expectant, but his eyes mist over as he sees what you are trying to give him.\n");
      return 1;
}
void do_death(object att)
  {
	tell_object(att, "The hermit grabs the parchment from the floor "
		"and rips it to shreads.  \nJust before he dies, he throws "
		"the pieces into the fire."
		"\n\n");
  ::do_death(att);
}
