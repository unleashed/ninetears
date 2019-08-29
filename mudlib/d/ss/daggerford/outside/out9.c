
inherit "/std/outside";

void setup() {
   set_short("North of Daggerford, Sort Of");
   set_light(80);
   set_long("Here in the hills to the northeast of Daggerford, you feel at "+
            "peace with the world.  The low hum of voices singing in prayer "+
            "only adds to the tranquility of the Nature which surrounds you.\n\n");
   add_exit("east","/d/ss/daggerford/outside/out8.c","corridor");
   add_exit("west","/d/ss/dukedom/link.c","road");
}
