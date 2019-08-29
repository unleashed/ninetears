inherit "/std/room";
#include "path.h"

void setup()
{
    set_short("Temple of Raisa\n\n");
    set_light(70);
    set_long("This temple, given to the Halflings of this land, is a "
      "dedication to the values and beliefs of the Goddess Raisa.  Mighty marble "
      "columns span from the floor to the ceiling, wooden pews line each side "
      "of this great temple, and a small statue of the goddess herself "
      "stands at the front of the temple.\n");

    add_exit("south",ROOMS+"half24.c","path");
    add_item("pews","The pews are made of fine wood, and appear to be well kept despite "
      "the lack of life in the temple.\n");
    add_item("columns","The immense columns are made of a blue-white marble and must "
      "have taken a small army to hoist upright.\n");
    add_item("statue","The statue is of the same marble as the columns, yet seems almost "
      "alive.  The statue of raisa has both hands to one side and almost looks like she "
      "was leaning on something at one time.  There is an inscription at the base of the "
      "statue.\n");
    add_item("marble","The marble in this temple all has a blue tint to it.  Perhaps "
      "the mighty Raisa had a weakness for beautiful blue things.");
add_item("inscription","The inscription reads:  Kneel before Raisa and recieve "
"her kindness. \n");

}

void init()
{
    add_action("do_kneel","kneel");
add_action("do_kneel","kneel before");
    ::init();
}

int do_kneel(string str)
{
    int i;
    object *ob;
    if(str !="statue")
    {
write("Wouldn't it be more proper to kneel before the statue?\n");
	return(1);
    }
    //staff
ob = find_match("jewel",TP);
    if(!sizeof(ob))
    {
write("A kind voice fills your head, saying:  I wish I had my old "
"staff to lean on.  But, I haven't seen it in years.\n");
	return 1;
    }
    //jewel
ob = find_match("staff",TP);
    if(!sizeof(ob))
    {
write("A voice says:  I would very much like my old staff back.  It was a "
"fine staff of smooth oak.  You'd know it if you saw it.\n");
return 1;
}
//level check
if(TP->query_level() < 5)
{
write("The voice of Raisa fills your head, saying:  I'm sorry, "+CNAME+", but "
"I fear for your safety outside of this island.  Return here when you are stronger.\n");
return 1;
}
write("As you place the jewel into the staff and then into the hands of the "
"statue, the kind voice of Raisa fills your head, saying:  \n"
"Well done, "+CNAME+".  Your strength and determination will see you far in "
"this world.  Beware the dangers outside of this island, though.  I can no longer "
"protect you there.  Good luck.\n"
"Before the shock of hearing a voice in your head can wear off, the statue gestures "
"toward you with the staff, and you are surrounded by a blinding light.\n"
"\n");
say("The statue of Raisa suddenly moves, points her staff at "+CNAME+", who dissapears "
"in a flash of light.  When the light it gone, "+CNAME+" is nowhere to be found and "
"the staff the statue once held is, as well.\n");
TP->move("/d/hoerk/belaern/s_jung/city/beach/beach09.c");
TP->look_me();
//inv clean up
//staff
ob = find_match("staff",TP);
for(i=0;i < sizeof(ob); i++)
{
ob[i]->dest_me();
}
//jewel
ob = find_match("jewel",TP);
for(i=0;i < sizeof(ob); i++)
{
ob[i]->dest_me();
}
return 1;

}
