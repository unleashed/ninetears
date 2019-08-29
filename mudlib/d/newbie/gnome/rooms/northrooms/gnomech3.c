inherit "/std/outside";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  North of Shadow Valley");
    add_property("no_undead",1);
    set_light(40);
    set_long("Macedonia:  North of Shadow Valley\n\n"
      "You are North of the Shadow valley and great mountains have begun to loom over you "
      "from every direction except to the South.  To your North, there appears to be a small clearing "
      "where the trees are not as dense.  Other than a small path leading to the North East, the only "
      "other route that seems possible is to the South.  As you are investigating the area, you "
      "also note an odd, breathing sound coming from the North East."
      "\n\n");
    add_item(({"forest","woods","trees"}),"The forest is thin here, but you still cannot see very far "
      "in any direction because of the trees.\n");
    add_item(({"mountain","range","mountain range","mountains"}),"Far to the "
      "distance you can see the Mithril Mountains.  The "
      "base of the mountains in pretty clear but the peaks "
      "are somewhat covered by the clouds.\n");
    //     * senses *
    add_smell(({"room","forest","air"}),"The smell here is fresh and pure, with a small hint of pollen to it.\n");
    add_sound(({"room","breathing","area","northeast","north east"}),"The 'Breathing' sounds "
      "very peculiar.  Not like anything you've ever heard, before.\n");
    add_feel(({"forest","trees","bark"}),"The trees are rough to the touch (Wow!  What else did you expect!\n");
    add_clone(NPC+"deer.c",2);
    add_exit("south",NORTHRMS +"gnomech2.c","path");
    add_exit("north",NORTHRMS +"gnomech4.c","path");
    add_exit("northeast",NORTHRMS +"gnomech5.c","path");
}
