/* Have to have one the now famous FR-Tables here too!
 * Baldrick, aug '94.
 */

#define COMMAND_TABLE "/table/command_table.c"

/*
 * this is the thingy that has all the standard commands that
 * players get.
 *
 * This keeps track of all the available commands in the mud with a path
 * and function attached to each one.
 *
 * When a player logs on the path and function is queryed off this object
 * so that even if a command changes location in the sccheme of all things
 * it can still be access without major hacks everywhere...
 */

mapping commands;

void create() 
  {
  commands = COMMAND_TABLE->query_commands();
}

mapping query_commands() 
  { 
  return commands+([ ]); 
}

string *query_command_names()
  {
  return m_values(commands);
}

// Taniwha 1995. Trying to bombproof this
mixed *query_command(string str)
  {
   mixed * m;
   if(commands)
   m = commands[str];
   return m;
}
