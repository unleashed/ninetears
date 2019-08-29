#define HP_RESTORE 8
#define VALUE 100

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("red mushroom");
   set_main_plural("red mushrooms");
   add_alias("mushroom");
   add_plural("mushrooms");
   set_short("A Red Mushroom");
   set_long("From what you can see, this appears to be the most common type "
      "of mushroom around.  They seem to be all over the place.  Now if "
      "only you could remember if it was the poisions type.\n");
   set_value(VALUE);
   set_weight(3);
}
void init()
{  add_action("do_eat","eat");
   ::init();
}
int do_eat(string what)
{  if(what == "mushroom")
   {   this_player()->adjust_hp(-18);
       write("\n You pop a few of the red mushrooms into your mouth and "
	     "and gulp them down.  It seems to have a rather pleasant "
	     "tart taste.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
