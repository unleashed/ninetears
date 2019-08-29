#define HP_RESTORE 8
#define VALUE 500

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("blue mushroom");
   set_main_plural("blue mushrooms");
   add_alias("mushroom");
   add_plural("mushrooms");
   set_short("A Blue Mushroom");
   set_long("This is a very small variety of mushroom.  It is by far the "
      "smallest out of all the types that you have seen here in Dendall so "
      "far.  In a strange sort of way it almost looks like you could eat "
      "it.  Now if only you could remember if it was the poisions type.\n");
   set_value(VALUE);
   set_weight(2);
}
void init()
{  add_action("do_eat","eat");
   ::init();
}
int do_eat(string what)
{  if(what == "mushroom")
   {   this_player()->adjust_hp(random(5)+10);
       write("\nYou sink your teeth into blue mushroom. "
         "\nHummm, it actually tasted good.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
