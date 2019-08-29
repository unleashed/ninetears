inherit "obj/monster.c";
void setup()
{
set_name("owl");
set_short("Owl");
set_long("This is a very large, wise looking owl.  It is mostly grey "
    "in color, and it is staring at you with wicked yellow eyes.  You "
   "notice that its talons are sunk deep into the branch that "
   "it is currently sitting on.\n\n");
set_level(4);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The owl gives a small 'hoot' as it twists its head "
        "around, searching the area.",
   1, "The owl moves further down the branch, shredding the bark "
        "of the branch as it does so.",
}));
}

