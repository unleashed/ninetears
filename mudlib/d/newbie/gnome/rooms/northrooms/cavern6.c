inherit "/std/room";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  Cavern of Plantipus\n");
    set_light(20);
add_property("no_undead",1);
    set_long("Macedonia:  Plantipus' Layer\n\n"
      "     This cavern is strewn with bones and the crushed armour of many adventurers.  Small "
      "grinding noises come from the room, and you realize that it is the sound of armour being "
      "moved with the breathing of adventurers who are still alive.  The only way out of the terrible "
      "place is to the West.\n");
    add_item(({"bodies","adventurers","armour","crushed armour"}),"The poor adventurers who "
      "fell in battle to Plantipus lie here.  Those who are still alive are beyond your help.\n");
add_item("bones","The bones have had the flesh eaten completely eaten off of them.  They "
"serve as the only memorial to those who lost their lives to Plantipus.\n");
    add_item("water","Water is dripping all around you, and you are already quite soaked from it.\n");
    //     * senses *
    add_smell(({"here","cave","air","area","mouth"}),"The air here is damp and stale smelling.\n");
    add_sound(({"grinding","armour","breathing"}),"The few poor souls who are alive are soon "
      "to be dead.  The thoughts of ending up like these adventurers doesn't quite appeal to you.\n");
    add_feel(({"here","cave","area","stalagtite","stalagmite"}),"The entire area has a cold, "
      "damp, slimey feeling to it.  You quickly find yourself not wanting to touch more than you "
      "have to in here.\n");
    add_clone(NPC+"plantipus.c",1);
add_exit("west",NORTHRMS +"cavern5.c","path");
}
