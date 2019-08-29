#define HP_RESTORE 8
#define VALUE 3

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("orange mushroom");
   set_main_plural("orange mushrooms");
   add_alias("mushroom");
   add_plural("mushrooms");
   set_short("An Orange Mushroom");
   set_long("This fist sized mushroom reminds you of the oranges that you "
      "had heard of in some of the surface citys.  The only differance seems "
      "seems to be that this one grows on the ground and the surface variety "
      "grows on a tree.  It looks like the most appetizing thing that you "
      "have seen in a while.\n");
   set_value(VALUE);
   set_weight(4);
}
void init()
{  add_action("do_eat","eat");
   ::init();
}
int do_eat(string what)
{  if(what == "mushroom")
   {   this_player()->adjust_hp(-15);
       write("\n You take a bite of the Orange mushroom, and its tangy taste "
 	 "surprises you.  You continue to enjoy the mushroom until you begin "
	 "to feel a little sick.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
