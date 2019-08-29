/* source file -- Board Room */
#include "path.h"

inherit "/d/ss/daggerford/thieves/vthief_guild.c";

object board;

void list_message();
void list_officers();
void list_members();
void list_protected();
void list_roster();

void setup()
{
  set_short("Board Room");
  set_long("The walls of this small room are covered with "+
    "notes, posters, advertisements, and other articles of "+
    "news.  Every scrap of writing pertains to one thing: "+
    "events concerning the thieves' guild.  In the center "+
    "of the room, a small table stands four feet above a "+
    "circular dais.\n\nType 'list' to see available guild functions.\n");
  set_light(70);
  set_zone("guild");

  add_item("dais",  "The dais is only a foot or so high.  "+
    "It provieds shorter beings with a better view of the "+
    "higher postings.\n");
  add_item("table",  "Atop the table sits a stack of vellum, "+
  "an ink well, a stylus, and a small tome.\n");
  add_item( ({"book", "tome" }),
    "The tome is leather bound and entitled \"Guild Journal "+
    "And Handbook\".  It has no current function, but will be "+
    "used in the future.\n");
  add_item ( ({"stylus", "inkwell", "vellum"}),
    "These materials are provide so that you may post your "+
    "own message.\n");
  add_exit("west", ROOM + "hall1", "door");
   set_save_file("/d/ss/daggerford/thieves/black_masks");
  if (!board) {
    board = clone_object("/obj/misc/board");
    board->set_datafile("Thief");
    board->move(this_object());
  }
}

void reset()
{
}

void dest_me()
{
  if (board)
    board->dest_me();
  ::dest_me();
}

void init() {
  ::init();
  add_action("do_list", "list");
}

int do_list(string str) {
  switch (str)
  {
    case "roster":
      list_roster();
      return 1;
    case "protect": case "protections":
      list_protected();
      return 1;
    case "message":
      list_message();
      return 1;
    case "officers":
      list_officers();
      return 1;
    case "members":
      list_members();
      return 1;
    default:
      notify_fail("Available lists are 'protections', "+
        "'roster', and 'message'.\n");
      return 0;
  }
}

void list_roster() {
  string *tmps, tmp;
  int i, n;

  printf("\nGuild: %s\n\n", query_guild_name());
  if (tmps = query_guild_patrons()) {
    printf("Patrons:\n");
    if ((n = sizeof(tmps)) < 1)
      printf("  No current patrons.\n");
      for (i = 0; i < n; i++)
        printf("  %s\n", capitalize(tmps[i]));
  }
  printf("\nGuildmaster: %s", capitalize(query_guildmaster()));
  tmp = query_guildmaster_title();
  if (tmp && tmp != "")
    printf(", %s\n", tmp);
  else
    printf("\n");
  list_officers();
  list_members();
}

void list_protected() {
  mixed *protect;
  int i, n;

  protect = query_protect();
  if (!protect)
    return;
  printf("\nRestricted Players:\n");
  if ((n = sizeof(protect)) < 1)
    printf("  Everybody is fair game.\n");
  for (i = 0; i < n; i += 2)
    printf("  %-15s%s\n", capitalize(protect[i]), ctime(protect[i+1]));
}

void list_message() {
  string message;

  message = query_guild_message();
  printf("\nGuildmaster's message:\n");
  if (!message || message == "")
    printf("  No message.\n");
  else
    printf("%s\n", message);
}

void list_officers() {
  string *officers;
  int i, n;

  officers = query_guild_officers();
  if (!officers)
    return;
  printf("\nOfficers:\n");
  if ((n = sizeof(officers)) < 1)
    printf("  No current officers.\n");
  for (i = 0; i < n; i += 2)
    printf("  %s, %s\n", capitalize(officers[i]), officers[i+1]);
}

void list_members() {
  string *members;
  int i, n;

  members = query_guild_members();
  if (!members)
    return 0;
  printf("\nMembers:\n");
  if ((n = sizeof(members)) < 1)
    printf("  No current members.\n");
  for (i = 0; i < n; i += 4) {
    printf("  %-15s", capitalize(members[i]));
    if (i+1 < n)
      printf("%-15s", capitalize(members[i+1]));
    if (i+2 < n)
      printf("%-15s", capitalize(members[i+2]));
    if (i+3 < n)
      printf("%-15s", capitalize(members[i+3]));
    printf("\n");
  }
}


