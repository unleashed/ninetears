inherit "/std/outside";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  North of Shadow Valley");
    add_property("no_undead",1);
    set_light(40);
    set_long("Macedonia:  North of Shadow Valley\n\n"
      "     You are on a small path to the North of Shadow valley.  From here, you can just see "
      "the Lake Chicanocomico to the South.  A small stream runs parallel to this path, and a "
      "thick, unpenetrable forest is off to the East.  To your North are small hills that run "
      "along the steep mountains of this valley.  "
      "\n\n");
    add_item(({"river","gnude river","gnude"}),"You are looking closely "
      "at the gently flowing Gnude River as it flows into Lake "
      "Chicamocomico.  The water is fresh and clear, but you "
      "are too afraid to take a dip. It looks very "
      "refreshing however.\n");
    add_item(({"lake","lake chicamocomico","chicamocomico"}),"Lake "
      "Chicamocomico is to the South, you can just barely see the glistening waters in the distance.\n");
    add_item(({"forest","woods"}),"From here, you can see the edge of "
      "the forest.  Due to its density, you can not see far "
      "into it.\n");
    add_item(({"mountain","range","mountain range","mountains"}),"Far to the "
      "distance you can see the Mithril Mountains.  The "
      "base of the mountains in pretty clear but the peaks "
      "are somewhat covered by the clouds.\n");
    add_clone(NPC+"frog.c",1);
add_exit("south",VALLEY +"gnome01.c","path");
    add_exit("north",NORTHRMS +"gnomech2.c","path");
}
void init()
{
    add_action("do_drink","drink");
    ::init();
}
int do_drink(string str)
{
    write("You take a refreshing drink from the pure waters of the river.\n");
    say(this_player()->query_cap_name()+" has a drink of water.\n",
      this_player() );
    return 1;
}

