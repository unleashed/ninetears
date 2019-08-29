//Modified by Ljen okt -96
//Joram

#include "path.h"
inherit "/std/room";
void setup(){

        set_short("Castle Of The Green Sun: Library");
        set_long("The library of the castle is a room where there are" 
                 " a unique type of furniture. You can see racks and"
                 " comfortable armchairs in each of the corners."
                 " The spider lamp from the ceiling provides a very"
                 " good illumination to the room"
                 " making the reading an easy thing to do.  No place for"
                 " any other decoration is avaliable and if there were it"
                 " would surely be occupied by more books.\n");

        add_item(({"book","books"}), "The books in here covers every theme "
                                     "you can think of, even sex.\n");

        add_item(({"lamp","spider lamp"}), "A big lamp with eight foot.  At the "
                                           "final of each one there is a candle.\n");
        add_item(({"armchair","armchairs"}), "Big wooden armchair with cushions made "
                                             "with duck feathers\n");
        add_item(({"rack","racks"}), "Simply wooden shelven furniture\n");
        set_light(60);

        add_exit("south",  CAST+"b4.c",   "door");

}

