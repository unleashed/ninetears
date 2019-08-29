inherit "obj/monster.c";
void setup()
{
set_name("rat");
set_short("Rat");
set_long("This is a nasty, dirty rat.  It has short dark brown "
    "fur and a long dirty tail.  It scurries around looking "
    "to find some garbage for its food.\n\n");
set_level(2);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
  1, "The rat squeaks noisily as it scurries about in its search for "
         "food.",
  1, "The rat looks up at you inquisitively with beedy red eyes.",
}));
}

