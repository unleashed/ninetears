inherit "obj/monster.c";
void setup()
{
set_name("hermit");
set_short("Hermit");
set_long("This is an old dirty hermit.  His clothes are nothing "
   "but rags, and they hang on his thin frame.  He has a long, gnarled "
   "and tangled beard that hangs down to his knees.\n\n");
set_max_hp(0);
set_dex(8);
set_str(8);
set_con(8);
set_wis(8);
set_int(8);
set_cha(4);
set_level(2);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "Hermit says: Do you have some food? I wish I had some food.  "
       "I am so hungry.",
   1, "The hermit's stomach growls loudly.",
   1, "The hermit searches the room for some food, and not finding "
       "any, he sighs sadly.",
}));
}

