#define ROOM "/d/ss/daggerford/fist/"
inherit "/std/room";
object vm;
object man;

string *memberlist = ({"legend","bone","neynar","ellowyn","wolf","tyr","pepparkaka","natas","robot","mori","madmartigan","dirkk","poison","benedick","tamasii","sharq","varth","bingovaffel"});
void setup()
{
  set_long("You stand before the massive complex of the Band of the Silver "+
      "Fist.  Many mysteries lie behind these walls, but few have ever "+
      "proven themselves worthy of entrance.  Tall marble pillars line "+
      "a set of huge stairs, which lead to a set of tall doors.\n");
  set_short("Before a Massive Structure");
   add_exit("east", "/d/ss/daggerford/market2","road");
  add_item("doors","The doors are inlaid with a huge silver fist.\nThere "+
           "is no apparent way to open the doors.\n");
  add_item("door","Each door stands well over 10 feet high.  It would take "+
           "an army of men several days to break down the doors.\n");
  add_item("pillars","The pillars are made of polished white marble.\n");
  add_item("pillar","This pillar is huge.  It would be impossible for you "+
           "to wrap your arms all the way around it.\n");
  add_item("stairs","The stairs lead up to a set of giant double doors.\n");
  set_light(80);
}
 
void event_enter()
{
 int i;
  string me;
 
   me=(string)this_player()->query_name();
 for(i=0;i<sizeof(memberlist); i++)
   if(memberlist[i]==me)
   {
   write("Welcome Mighty One.  Type 'ascend' to "+
        "enter the Halls of the Silver Fist.\n");
     add_action("enter_hall","ascend");
   }
}
 
enter_hall()
{
 say(this_player()->query_cap_name()+" walks up the stairs and through the doors.\n");
 this_player()->move("/d/ss/daggerford/fist/hall1.c");
 this_player()->look_me();
 return 1;
}
 
void reset()
{
 if(!man)
 {
  man=clone_object(ROOM+"old_man");
  man->move(ROOM+"entrance");
 }
}
