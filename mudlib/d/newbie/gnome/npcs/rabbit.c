inherit "obj/monster.c";
void setup()
{
set_name("rabbit");
set_short("Rabbit");
set_long("This is a small brown rabbit.  It seems to have found "
    "itself a nice bed of clover to munch on, and appears to be "
    "quite content.\n\n");
set_level(2);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The rabbit raises its head and you watch its nose twitch as "
         "it sniffs the air.",
   1, "The rabbit hops a bit away in search of more clover blooms.",
}));
}

