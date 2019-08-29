
inherit "/std/outside";

void setup() {
   set_short("South of Daggerford");
   set_light(80);
   set_long("You are following a small trail around the outside of "+
            "Daggerford's city walls.  You can smell blood and hear "+
            "pitiful screams echoing over the wall to your north.  You "+
            "shudder to think what must be happening inside the city.\n\n");
   add_exit("east","/d/ss/daggerford/outside/out3.c","corridor");
   add_exit("west","/d/ss/daggerford/outside/out1.c","corridor");
}
