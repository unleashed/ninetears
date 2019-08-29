inherit "/std/outside";
#include "path.h"

void setup ()   {
set_short("Macedonia:  Shadow Valley");
set_light(40);
    set_long("Macedonia:  Shadow Valley\n\n"
	"     This is a large grassy area at the northeastern"
           " corner of Whispering Woods.  The scenery from here "
           "is breath-taking.  With the Gnude River gently flowing "
           "into Lake Chicamocomico, and outlines of forest and"
           " mountain ranges, you feel like you want to stay here to "
           "rest for a short time. "
           "\n\n");
add_item(({"grass","area","grassy area"}),"This is a small plain "
           "covered with bright green, knee-deep grass.  This area "
           "has a breathtaking view of the lake and river.\n");
add_item(({"river","gnude river","gnude"}),"You are looking closely "
           "at the gently flowing Gnude River as it flows into Lake "
           "Chicamocomico.  The water is fresh and clear, but you "
            "are too afraid to take a dip. It looks very "
            "refreshing however.\n");
add_item(({"lake","lake chicamocomico","chicamocomico"}),"Lake "
           "Chicamocomico is a very quiet and peaceful lake.  "
          "As you look at its size, you estimate that is covers "
           "about half of the base of Shadow Valley.\n");
add_item(({"forest","woods"}),"From here, you can see the edge of "
           "the forest.  Due to its density, you can not see far "
           "into it.\n");
add_item(({"mountain","range","mountain range"}),"Far too the "     
           "distance you can see the Mithril Mountains.  The "
           "base of the mountains in pretty clear but the peaks "
           "are somewhat covered by the clouds.\n");
add_clone(NPC+"deer.c",1);
add_clone(NPC+"rabbit.c",2);
add_exit("east",VALLEY +"gnome02","path");
add_exit("north",NORTHRMS +"gnomech1.c","path");
}
void init()
{
   add_action("do_drink","drink");
   ::init();
}
int do_drink(string str)
{
   write("You take a drink from the refreshing waters of the lake. "
         "It is surprising how much better it makes you feel.\n");
   say(this_player()->query_cap_name()+" has a drink of water.\n",
         this_player() );
   this_player()->adjust_hp(random(4)+1 );
   return 1;
}

