inherit "/std/outside";
#include "path.h"

void setup ()   {
    set_short("Macedonia:  Shadow Valley");
    set_light(40);
    set_long("Macedonia:  Shadow Valley\n\n"
      "   This is a large, grassy area at the western edge "
      "of the forest.  The path from the brush comes to an "
      "end here but there in an obvious trail leading south "
      "along the Gnude River.  On the other side of the "
      "river, are the Mithril Mountains.  Your fear of "
      "these mountains urges you to travel back to the "
      "safety of Macedonia.  "
      "\n\n");
    add_item(({"brush","dense brush"}),"This is just normal brush "
      "found in a typical forest.  As you look closer, you "
      "see some sort of reflection coming from it.  If you "
      "were to search the brush, you might find where the "
      "light is coming from.\n");
    add_item(({"forest","woods"}),"From here, you can see the edge of "
      "the forest.  Due to its density, you can not see far "
      "into it.\n");
    add_item("path","This path is a narrow dirt path made by the "
      "large amount of traveling through this forest.\n");
    add_item("trail","The trail travels north and south along the "
      "gentle flowing river.\n");
    add_item(({"mountain","range","mountain range"}),"Far too the "     
      "distance you can see the Mithril Mountains.  The "
      "base of the mountains in pretty clear but the peaks "
      "are somewhat covered by the clouds.\n");
    add_item(({"grass","area","grassy area"}),"The grass here is almost "
      "as tall as you knees.  This area provides a perfect "
      "environment for small animals to live.\n");
    add_item(({"river","gnude river","gnude"}),"This is the gentle "
      "flowing Gnude River.  Although it is so gentle, it is "
      "too deep wo wade in and to wide to swim across\n");

    add_clone(NPC+"bear.c",1);
    add_clone(NPC+"rabbit.c",3);
    add_exit("south",VALLEY +"gnome09","path");
    add_exit("east",VALLEY +"gnome04","path");
    add_exit("southeast",VALLEY +"gnome10","path");
    add_property("no_undead", 1);
}
void init()
{
    ::init();
    add_action("search_me","search");
}
void search_me(string str)
{
    if(str == "brush")
    {
	write("You search the brush and find a small brass key.\n");
	clone_object(MISC+"key.c")->move(this_player());
    }
}
