#define HP_RESTORE 8
#define VALUE 250

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("green mushroom");
   set_main_plural("green mushrooms");
   add_alias("mushroom");
   add_plural("mushrooms");
   set_short("A green mushroom");
   set_long("This is a rather large variety of mushroom, certainly the "
      "largest that you have ever come bye in recent time.  In a strange "
      "sort of way it almost looks like you could eat it.  Now if only you "
      "could remember if it was the poisions type.\n");
   set_value(VALUE);
   set_weight(5);
}
void init()
{  add_action("do_eat","eat");
   ::init();
}
int do_eat(string what)
{  if(what == "mushroom")
   {   this_player()->adjust_hp(5+random(5));
       write("\n You tear into the firm green mushroom with your teeth. "
         "\nHummm, it actually tasted good.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
