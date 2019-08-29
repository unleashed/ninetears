#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Hut of Senchistillan");

    set_long("Hut of Senchistillan.\n\n"
        "       You've entered the small hut of Senchistillan. "
 	"In its dimly lit center stands the Druid giving you a "
	"warm welcoming. All around the room hangs exotic herbs "
	"and potions spreading a delicate and aromatic smell. "
	"From here you clearly hear the pouring sound of SilverBreed "
	"blended with the fair tingling of clocks and birds. "
	"On the left side of the hut stands a desk with many "
	"peculiar knives and tools. \n");
	
	set_light(80);
   
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the "
	"glitter seems to come from the fishes idling around in the "
	"water. \n");   

	add_sound(({"clock","clocks","sound","birds"}),"     When you "
	"listen some closer to the sound you notice a certain harmony "
 	"in it. Making every part of it as important for this "
	"astounding joy. You almost feel the nature spirit surround "
	"your soul in a warm breeze, sharing you a touch making you feel "
	"directly connected to the earth you're standing on. Even the "
	"birds suddenly seem to make sence and for a moment there, "
	"you're totally gone in the newly enlightened heart of yours. \n");
	
	add_item(({"herbs","herb","potion","potions"}),"   The "
	"herbs and potions hanging on the wall all are perfectly "
	"set in a special order where the blue colors start and "
	"red end. Above every potion and herb you see small carvings "
	"giving them all a unique description. \n"
	"The sixteen different symbols are: \n"
	"a star, a snake, a bear, two hands shaking eachother, a harp, "
	"a oaktree, two eyes, a cat, a boar, a moon, a sun, " 
	"a solareclipse, a leaf, a river, a fox and a fish. \n");
		
	add_exit("east",ROOMS+"d5.c","door");
 }