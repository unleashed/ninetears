// Base groups file...
// Radix - January 10, 1996

inherit "/std/object.c";

mixed *group_commands = ({ });

int query_legal_race(string race) { return(1); }

int query_channel() { return 0; }

int add_group_command(string name, int add_if_player) 
{
   if (member_array(name, group_commands) != -1)
      return 0;
   group_commands += ({ name, ({ add_if_player }) });
   return 1;
}

// Mask this and put your shadows in here, scope to this though!
void start_player(object pl) 
{
   int i;
   if (!pointerp(group_commands))
      group_commands = ({ });
   for (i=0;i<sizeof(group_commands);i+=2)
      if (group_commands[i+1][0] || !interactive(pl))
         pl->add_known_command(group_commands[i]);
}
