inherit "obj/monster.c";
void setup()
{
set_name("bear");
set_short("Bear");
set_long("This is a big, burly, black bear.  This type of bear is "
   "found only in the Mithril Mountains.  As it lumbers towards you, "
   "you can see how strong and muscular it is.  An animal to be "
   "truly wary of.\n\n");
set_level(8);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The bear makes a small, low growl in its throat as it notices "
       "you standing there.",
}));
}

