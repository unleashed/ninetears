inherit "/std/pick_lock.c";

void setup(){
   set_name("lockpicking tools");
   set_short("Lockpicking Tools");
   add_alias("lockpicks");
   add_alias("picklocks");
   add_alias("tools");
   add_plural("sets");
   add_plural("lockpicking sets");
   set_main_plural("Lockpicking Sets");
   set_value(500);
   set_weight(15);
   set_long("Lockpicking Tools\n\n"
      "   This is a set of finely crafted tools used to pick locks.  It "
      "requires not only much precision to make them but also to use them as "
      "well.  Many of the small and shiny metal tools have specially "
      "designed hooks and curves at the end to aid in the turning of "
      "a locks tumblers.\n\n");
   add_property("tool_type","tumb");
}
