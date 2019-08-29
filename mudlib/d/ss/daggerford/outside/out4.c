
inherit "/std/outside";

void setup() {
   set_short("South of Daggerford");
   set_light(80);
   set_long("The path which circumnavigates the Daggerford city walls "+
            "continues to the east and west.  Though the sound is "+
            "muffled by the stone walls, you can faintly hear voices "+
            "raised in prayer, just on the other side of the wall.\n\n");
   add_exit("east","/d/ss/daggerford/outside/out5.c","corridor");
   add_exit("west","/d/ss/daggerford/outside/out3.c","corridor");
}
