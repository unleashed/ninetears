inherit "/std/object";

/* The Pub Globe. A chatter between rooms with the Globe in them.
 * Version 2, with globewho
 * Baldrick, '93, fix jan '96.
 */  

/* This object: if it's moved, alter this. */
#define GLOBE "/obj/misc/globe.c"

string drunk_speech(string str);
int do_globe_tell(string bladder);
void globe_tell(string bladder);
int globe_who();

void setup()
  {
  set_name("globe");
  set_short("Globe of Pub chatting");
  set_long("This is one of the most remarkable items in these realms. " +
           "It is a shimmering blue globe, floating a meter over the floor "+ 
           "in the middle of the room.\n");
  reset_get();
  set_weight(10000);
  set_read_mess("This Globe is created by the God of these Realms, Baldrick."+
                "\nUse 'chat' to communicate with other pubs in the realms " + 
                "' and 'globewho' to see who are there.\n");
  set_value(0);
}

void init() 
  {
  add_action("do_chat", "globe");
  add_action("do_chat", "chat");
  add_action("globe_who", "globewho");
  // add_action("ret", "userg");
  ::init();
} /* communicate_commands() */

int do_chat(string str) 
  {
  object *drunks;

  if (!str)
    {
    notify_fail("You wanted to chat what?\n");
    return 0;
     }

  if (this_player()->query_drunk())
    str = drunk_speech(str);
  /* Hmm.. new method, without the event thingie.. */
  do_globe_tell( (string)this_player()->query_cap_name() +
     " [Globe]: " + str + "\n");
  write("You chat through the globe: " + str + "\n");
  return 1;
}

string drunk_speech(string str) 
  {
  /* I think I like replace already */
  return replace(str, ({ "s", "sh", "r", "rr", "ing", "in'", "x", "xsh",
                         "S", "SH", "R", "RR" }));
} /* drunk_speech() */

void show_drunks(object curious)
  {
  object *drunks;
  string drunk_name;
  string place;
  int i;

  if (!clonep(this_object()))
    return;

  place=environment(this_object())->query_short();

  tell_object(curious, "In " + place+ ":\n");

  drunks = all_inventory(environment(this_object()));

  for (i=0;i<sizeof(drunks);i++)
    {
     if(living(drunks[i]) && !drunks[i]->query_hide_shadow())
      { 
      drunk_name = (string)drunks[i]->query_cap_name();
      tell_object(curious, "  " + drunk_name + "\n");
      }
    }
  return;
}

int globe_who() 
  { 
  children(GLOBE)->show_drunks(this_player());
  return 1;
}

int do_globe_tell(string bladder)
  {
  mixed *globes;
  int i;
  children(GLOBE)->globe_tell(bladder);
  return 1;
}

void globe_tell(string bladder)
  {
  tell_room(environment(), bladder, this_player());
} 
