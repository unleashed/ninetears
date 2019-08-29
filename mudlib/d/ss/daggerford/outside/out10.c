
inherit "/std/outside";

void setup() {
   set_short("North of Daggerford");
   set_light(80);
   set_long("You now stand to the north of the city walls.  The sounds "+
            "which you fondly associate with drinking brew (laughing, "+
            "belching, passing gas) flow over the wall from the south.\n\n");
   add_exit("east","/d/ss/dukedom/link.c","road");
   add_exit("west","/d/ss/daggerford/outside/out11.c","corridor");
}

