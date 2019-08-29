//Joram

#include "path.h"
inherit "/std/newbieguild";
void setup(){

        set_short("Castle Of The Green Sun - Room Of Erudition, Guildroom");
        set_long("This second part of the library is a place of peace and "
                 "learning.  Here is where the expert fighters of the "
                 "realms come in search of new knowledge.  The room is small "
                 "but has several pieces of furnitures with shelves, which are "
                 "full of books.  On the east wall, the only one without stands,"
                 " there is a big sign with engraved golden letters.  On the celling "
                 "there is a big iron spider lamp illuminating the whole place very good "
                 "making the reading much more easier for those who come here looking for "
                 "something new.\n");

        add_item("sign","The sign reads:\n"
                "+-----------------------------------------------------+\n"
                "|                                                     |\n"
                "|                                                     |\n"
                "|      %^YELLOW%^'cost' To find the XP cost to advance.%^RESET%^         |\n"
                "|      %^YELLOW%^'advance' To advance your skills.%^RESET%^              |\n"
                "|      %^YELLOW%^'info' To get some information.%^RESET%^                |\n"
                "|                                                     |\n"
                "|      %^YELLOW%^You cannot advance above level 5 here.%^RESET%^         |\n"
                "|                                                     |\n"
                "+-----------------------------------------------------+\n"
                "\n");

        add_item("books","The books of the art of combat are all over "
                                    "the room, the talk about heros of the past and "
                                    "the ones to come.\n");

        add_item(({"lamp","spider lamp"}), "A big lamp with eight foot.  At the "
                                           "final of each one there is a candle.\n");

        add_item("shelves", "Simply wooden shelven furniture\n");

        set_light(60);

        add_exit("east",   CAST+"e7.c",   "door");

}

