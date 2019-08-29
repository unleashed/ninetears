
inherit "/std/object.c";


void setup()
{
  set_name("holy symbol");
  add_alias("skull");
  set_short("Obsidian Skull");
  set_long("\nObsidian Skull\n\n"
     "     This small skull, carved from the darkest obsidian, "
     "radiates a dark light.  You take a closer look at it "
     "and it appears to stare straight back at you and "
     "into your soul...\n\n");
  set_read_mess("\nBeware for this skull holds the power of "
     "the mighty Xuerin.\n");
  set_value(0);
  set_weight(100);
  add_property("faith","antipaladin");
  reset_drop();
}

void find_tower(string str)
{
 object *tower;
 int i;
 int p_lev;
 int gps;
 p_lev = this_player()->query_level();
 gps = this_player()->query_gp();
  if(!str)
   {
    write("Stare at what?\n\n");
    return 1;
   }
  if((this_player()->query_guild_name() != "antipaladin") && (str == "skull"))
  {
   write("A small dragon comes and snatches the skull from your "
     "hands saying:  You're not a Dark Lord :P\n\n");
   write("The dragon blows some fire at you for good measure.\n\n");
   this_player()->adjust_hp(-20);
   this_object()->dest_me();
   return 1;
  }
 if((p_lev < 20) && (str == "skull"))
  {
  write("You are too inexperienced to use the powers of the skull.\n\n");
  return 1;
  }
 if((gps < 105) && (str == "skull"))
  {
   tell_object(this_player(), "You are too tired to use your "
    "tower finding ability...\n\n");
   return 1;
  }
 tower = children("/d/omiq/towers/eviltow");
 for(i=0;i<sizeof(tower);i++)
   if((environment(tower[i])) && (str == "skull"))
   {
    tell_object(this_player(), "You stare intently at the "
     "Obsidian Skull.  As you focus all of your energy on the "
     "tiny skull an image appears before you...\n\n"
      ""+environment(tower[i])->query_long()+"\n\n"
     "You feel drained...\n\n");
    this_player()->adjust_gp(-100);
   return 1;
   }
 else return 0;
}

void init()
{
 add_action("find_tower", "stare");
 ::init();
}
