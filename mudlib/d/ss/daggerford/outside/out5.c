
inherit "/std/outside";

void setup() {
   set_short("Southeast of Daggerford");
   set_light(80);
   set_long("The pathway makes a sharp turn here at the southeastern tower "+
            "of Daggerford, following the city walls.  "+
            "From a distance, you hear swords ringing on shields and an "+
            "occasional tremendous belch.\n\n");
   add_item(({"tower","city tower","southeastern tower"}),
            "This tower, although relatively unremarkable, has been part "+
            "of the framework of the city defenses since the city was "+
            "first founded.\n\n");
   add_exit("north","/d/ss/daggerford/outside/out6.c","corridor");
   add_exit("west","/d/ss/daggerford/outside/out4.c","corridor");
}
