inherit "/std/raiseroom";
#include "path.h"
object helper;
void setup ()   {
set_short("Macedonia:  Temple of Reorx");
set_light(40);

set_long("Macedonia:  Temple of Reorx\n\n"
         "   As you walk into the temple, a sense of reverance "
         "is strongly felt.  "
        "The marble floor and the white wall are a little "
        "plain, but the maple pews and altar give this temple "
        "the architecture that the citizens of this valley "
        "were looking to have.  This temple is a perfect place "
        "for the citizen of this valley, especially the priests, " 
         "to worship to Reorx."
         "\n\n");
  add_sign(" Gnome Raiseroom.\n"
             "You can get raised here by typing: raise me   ");
        add_exit("southeast",VALLEY +"gnome14","path");
   add_clone("/d/newbie/gnome/npcs/priest.c",1);
}
void reset()
  {
  if (!helper)
    {
   helper = clone_object("/baseobs/monsters/healer");
    helper->move(this_object());
    }
    helper->set_name("wise_gnome");
    helper->set_short("Old Gnome");
    helper->add_alias("gnome");
    helper->add_alias("healer");
    helper->set_long("A rather old and distracted looking gnome stands "
    "here waiting to raise those unfortunate enough to die in their "
    "struggles to become mighty adventurers. "
    "\n");
   ::reset();
} /* void reset */ 
void dest_me()
{
  if (helper)
    helper->dest_me();
   ::dest_me();
} /* void dest me */
/*
void init()
{
   ::init();
    add_action("do_raising","raise");
}
*/
int do_raising(string str)
{
   object ob;
   if(!helper)
   {
      tell_room(this_object(),"There appears to be a sad lack of someone here "
        "to raise people, perhaps if you waited ?.\n");
      return 1;
   }
   ob = present(str);
   if(ob && ob->query_dead() && helper)
   {
     helper->do_raising(ob);
   return 1;
   }
}
