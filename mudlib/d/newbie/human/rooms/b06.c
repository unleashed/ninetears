#include "standard.h"
#include "path.h"
inherit HAVMAND+"beach.c";
object dan;

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "   This small beach ends here. The fine white sand just stops when it gets "
    "to the waters edge. There are trees to the south, but from here there is no "
    "way to enter them. This would be the perfect place to rest for a while. "
    "\n\n");
    add_item("trees","The trees grow very closely together and many of them "
    "have intertwining trunks making it difficult to force your way among them.\n");

}
void init()
{
    add_exit("east",HAVMAND+"b07.c","path");

    add_action("do_raft","make");
    add_action("do_raft","build");
   ::init();
}
void reset()
{
   if(!dan) 
   {
      dan = new(CHARS+"dan.c");
      dan->move(this_object());
   }
   ::reset();
}

int do_raft(string str)
{
   int i;
   object *ob;
   if(!stringp(str)) 
   {
      write("Build what?\n");
      return(1);
   }
   str = lower_case(str);
   if(str != "raft") return 0;
   if(!dan)
   {
      write("There seems to be no one here to help you build a raft.\n");
      return 1;
   }
// 2 casks
   ob = find_match("casks",TP);
   if(sizeof(ob) < 2)
    {
        write("Pirate Dan says: Can't build no raft with nothing for floatation, coupla casks would do at a pinch.\n");
        return 1;
    }
//  vine
    ob = find_match("vine",TP);
    if(!sizeof(ob))
    {
       write("Pirate Dan says: We need summat ter hold it all together "+CNAME+" rope or summat like that.\n");
       return 1;
    }
// door
    ob = find_match("door",TP);
    if(!sizeof(ob))
    {
        write("Pirate Dan says: Summat flat for the decking, maybe ?\n");
        return 1;
    }
// baccy
   ob = find_match("baccy",TP);
   if(!sizeof(ob))
   {
       write("Pirate Dan says: We need summat ta keep the sharks away, chewing tobacco works good.\n");
       return 1;
   }
// level check here
    if(TP->query_level() < 5)
    {
        write("Pirate Dan says: Sorry "+CNAME+" you'd never survive the trip, I'd feel real "
        "guilty getting you killed. Come back when you are more experienced.\n");
        return 1;
    }

   write("Old Dan smiles at you. He quickly lashes the door to the top of the "
   "casks, building a crude raft. You help him push it off from the shore and leap aboard.\n");
   say("Old Dan quickly lashes a door to the top of some casks making a raft. "+
   CNAME+" helps him push it off and climbs aboard. It looks pretty crowded and there "
   "wouldn't have been room for you even if you had been fast enough.\n");
   if(!find_object(HAVMAND+"raft")) clone_object(HAVMAND+"raft.c");
    TP->move(SHIP+"havmand_belaern");
   TP->look_me();
// clean up
// 2 casks
    ob = find_match("casks",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
//  vine
    ob = find_match("vine",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
// door
    ob = find_match("door",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
// baccy
   ob = find_match("baccy",TP);
    for(i= 0;i < sizeof(ob); i++)
    {
        ob[i]->dest_me();
    }
    environment(TP)->do_voyage();
    dan->dest_me();
    return 1;
}
void dest_me()
{
   if(dan) dan->dest_me();
   ::dest_me();
}

