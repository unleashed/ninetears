inherit "obj/monster.c";
void setup()
{
set_main_plural("Frogs");
set_name("frog");
set_short("Frog");
set_long("You see before you a small bright green frog that is "
   "native to this part of the Mithril Mountains.  You can hear it "
   "croaking rather loudly, and you can see its throat moving in "
   "time with it's croaks.\n\n");
set_level(2);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The frog pauses in its constant croaking, only to resume almost "
          "immediately.",
   1, "The frog shifts slightly on the limb that it is sitting on.",
}));
}

