inherit "/std/group.c";

setup()
{
   set_name("test");

   set_short("Test");

   add_group_command("track",1);
}

int query_legal_race(string str) 
{
   switch(str)
   {
      case("immortal") :
      case("human") :
      case("drow") :
         return(1);
      default : return(0);
   }
}

start_player(object pl)
{
  // loads a shadow!  No more invis objects carried around...
   object shd = clone_object("/w/radix/shadow.c");
   shd->start(pl);
   shd->move(pl);
   return ::start_player(pl);
}
