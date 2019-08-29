inherit "obj/monster.c";
void setup()
{
set_name("npc");
set_short("NPC");
set_long("This is a little newbie/gnome inventor.  Most inventors are "
   "quite content with just inventing, but this inventor has a "
   "mad look in his eye as if he has gone off the deep end.  He "
   "even looks a little on the mean side.\n\n");
set_max_hp(0);
set_dex(10);
set_str(10);
set_con(10);
set_wis(20);
set_int(20);
set_cha(10);
set_level(3);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The Inventor exclaims: I have to find more metal to make my "
        "inventions! I must!",
   1, "The inventor scratches his head in confusion as he searches "
        "around for small pieces of metal to melt down and use.",
}));
}

