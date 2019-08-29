inherit "/std/outside";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  North of Shadow Valley");
    add_property("no_undead",1);
    set_light(40);
    set_long("Macedonia:  Entrance to The Cavern of Plantipus\n\n"
      "You stand before an ancient cave.  The cave's stalagtites and stalagmites seem to move "
      "outward in an attempt to chew you up.  The wind continually blows from the other sides of the "
      "of the mountains making a breath sound between the cave's 'Teeth.'  To the West, you "
      "can see some sort of clearing, and to the South West, a path leads into the forest.  "
      "\n\n");
    add_item(({"teeth","stalagmites","stalagtites","cave"}),"The cave looks menacing, and you "
      "have a terrible feeling about what lies in store for you inside.\n");
    add_item(({"mountain","range","mountains","mountain range"}),"The peaks which surround "
      "this valley stand before you.  Few have ever tried to scale them, and fewer still have lived to tell the tale.\n");
    //     * senses *
    add_smell(({"here","room","air","cave","mouth"}),"The air here has a moist, mildew smell "
    "to it, probably from the dank cave nearby.\n");
add_sound(({"room","breathing","area","northeast","north east"}),"The 'Breathing' sounds "
  "very peculiar.  Not like anything you've ever heard, before.\n");
add_feel(({"cave","teeth","stalagtite","stalagmite"}),"The cave's 'Teeth' are deadly cold "
  "to the touch, and seem to threaten to take your hand, if you let it.\n");
add_exit("west",NORTHRMS +"gnomech4.c","path");
add_exit("cave",NORTHRMS +"cavern1.c","path");
add_exit("southwest",NORTHRMS +"gnomech3.c","path");
}
