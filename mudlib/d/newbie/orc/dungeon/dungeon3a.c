#include "path.h"
inherit CASTLE+"baseroom.c";
object *npc;
void setup() { my_setup();
set_short("Realm of the Orc:  The Hold");
set_light(40);
set_long("\n   Realm of the Orc:  The Hold.\n\n"
         "     The temperature has increased for some reason.  This "
         "room "
"is much warmer then any of the dungeon you have previously been in. "
"The room is very ornate with pentagrams placed here and there, "
"cruel drawings etched into the walls, and a large bronze basin in the "
"center of the room. "
"There is that same odd odor here but more powerfull and you hear "
"what appears to be 'breathing' from behind two very large metal "
"doors.\n\n");
add_item(({"pentagrams","pentagram","drawings","drawing","etching","echings","walls","wall","door"}),"\n"
"  It seems odd to your orcy brain that humans spend so much time "
"doing senseless works. You have never grasped the concept of 'art'. "
"But yet you feel that it was not the humans' intention to make "
"'art' here. Each work of 'art' has some 'evil' meaning. "
"There are drawings of humans killing humans and the killers "
"are smiling....an odd smile you note...There seems to be some "
"significance to this horrid multi-armed-eyed-legged-mouthed creature. "
"It is depicted quite often doing rather cruel things. "
"You kinda like this creature, it likes to do lots of the "
"things you like to do!\n");
add_feel(({"door","metal door","doors","metal doors"}),"\n"
"   The doors feel hot to the touch.\n");
add_item("basin","\n"
"   Made of bronze, the basin looks HEAVY!!.. It is ornate with "
"pictures of that same horrid creature found on most every "
"wall surface. There appears to be something inside the basin...."
"some kind of liquid...\n");
add_item("liquid","\n"
"  It looks dark and thick...It smells kinda familar.\n");
add_taste("liquid","\n"
"   YUCK!!!  its...old blood!! sour blood!! ACK!\n");
add_smell("liquid","\n"
" It smells familiar...smells like something you've ate once..\n");
add_smell("odor","\n"
"  You smell crap!! ick! ...damn humans!!\n");
add_exit("north",DUNGEON +"dungeon2a","door");
add_exit("south",DUNGEON +"dungeon4a","door");
npc=allocate(1);
}




void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/orc/monsters/offering.c");
   npc[i]->move(this_object());
   }
}
}

void dest_me()
{
   int i;
   for(i = 0; i < sizeof(npc); i++)
   {
      if( npc[i] ) npc[i]->dest_me();
   }
   ::dest_me();
}

