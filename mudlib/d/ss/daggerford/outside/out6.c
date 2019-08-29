
inherit "/std/outside";

void setup() {
   set_short("East of Daggerford");
   set_light(80);
   set_long("Standing once again outside the city walls of Daggerford, you "+
            "marvel at how it (and they) have stood the test of time.  From "+
            "within the city, you can hear voices raised in passionate "+
            "chanting.\n\n");
   add_exit("north","/d/ss/daggerford/outside/out7.c","corridor");
   add_exit("south","/d/ss/daggerford/outside/out5.c","corridor");
}
