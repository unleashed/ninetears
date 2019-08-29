inherit "obj/monster.c";
void setup()
{
set_name("bandit");
set_short("Bandit");
set_long("This is a menacing looking bandit who appears to be quite "
   "mean.  The bandit's stance is one that tries to intimidate you, and it "
   "seems to be growling under it's breath.  This bandit looks as if it might "
   "like to fight with you if you give it the smallest reason to.\n\n");
set_level(random(4)+2);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
    1, "The bandit looks at you as if he is sizing you up for a fight.",
}));
clone_object("/d/newbie/gnome/weapons/dirk.c")->move(this_object());
clone_object("/d/newbie/gnome/armour/coat.c")->move(this_object());
command("equip");
}

