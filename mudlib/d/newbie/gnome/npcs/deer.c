inherit "obj/monster.c";
void setup()
{
set_name("deer");
set_short("Deer");
set_long("You see before you a graceful, long legged deer.  As you "
   "approach it looks up to peer at you intently.  It is a reddish "
   "brown color, and as it looks at you, you see its ears twitch "
   "nervously.\n\n");
set_level(5);
set_al(0);
set_gender(random(2)+1);
load_chat(40,({
   1, "The deer slowly lowers its head and gets another mouthful of "
         "grass.",
}));
}

