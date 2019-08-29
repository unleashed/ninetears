inherit "/std/outside";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  North of Shadow Valley");
    add_property("no_undead",1);
    set_light(40);
    set_long("Macedonia:  North of Shadow Valley\n\n"
      "You have come to a barren area where the rocks of the mountains meet the fertile soil of "
      "Shadow Valley.  There are few trees and no grass in this clearing due to the difficult "
      "conditions.  To your South lies the Shadow Valley.  To your East, you can hear....breathing?  "
      "You can also just manage to see an entrance to a cave to the East from your vantage point, as well.  "
      "\n\n");
    add_item(({"forest","trees","grass","soil","ground","area","rocks"}),"This area is very "
      "barren due to the rocky soil.  The vegetation here is sparse or non-existant.\n");
    add_item(({"mountain","range","mountain range","mountains"}),"Far above you, "
      "you can see the ancient mountains which enclose Shadow Valley from the rest of the world.  "
      "They appear to be far too steep to climb.\n");
    //     * senses *
    add_smell(({"room","forest","air"}),"The smell here is fresh and pure, with a small hint of pollen to it.\n");
    add_sound(({"room","breathing","area","east"}),"The breathing (?) sounds are "
      "very peculiar.  Not like anything you've ever heard, before.\n");
    add_feel(({"rocks","ground","area"}),"The rocks are rough, volcanic rocks.  The ground "
      "is littered with them, making the soil very rough.\n");

    add_clone(NPC+"deer.c",1);
    add_exit("south",NORTHRMS +"gnomech3.c","path");
    add_exit("east",NORTHRMS +"gnomech5.c","path");
}
