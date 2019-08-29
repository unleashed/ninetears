inherit "/std/object";
mapping guilds = (["taniwha":10,"hokemj":10,"Cyrcia":10,"Grimbrand":10,"paladin":20,"antipaladin":20]);
void setup()
{
   set_name("feather");
   set_short("Feather");
   set_long(
      "This is a long feather from the tail of an exotic bird.  "
      "Even though it is not composed of flames, they way the reflecting "
      "light shifts and sparkles as it comes off it almost leads you "
      "to believe it is.  The colors are somewhat disorienting, making "
      "it hard to focus on them for more than a short moment.  "
   "\n");
   set_value(0);
   set_weight(0);

}
void init()
{
   add_action("do_focus","focus",100);;
   ::init();
}
void do_focus(string str)
{
   string guild;
   if(str=="feather")
   {
      guild=this_player()->query_guild_name();
      if( !guilds[guild] ) return 0;
      if( this_player()->query_level() >= guilds[guild] && !sizeof(this_player()->query_spell("wall of fire")) )
      {
         write("As you begin to concentrate on the feather, "
            "the colors burn an image of the feather in your mind.  "
            "You now know how to shape elemental fire in a manner similar "
            "to the forces that shape the feather.\n");
         this_player()->add_spell("wall of fire","wall_fire.c",11);
         this_object()->dest_me();
         return 1;
      }
   }
   return 0;
}
