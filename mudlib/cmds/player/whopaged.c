// Genius whoever did this .. but damned fool just copied the who.c
// Stripped and inherited so it would have color too, Radix Jan 1996
inherit "/global/player/cmds/who.c";

int do_who(string str) {
  string ws;

  ws = who_string((int)this_player()->query_cols(), (int)this_player()->query_creator(), str);
  this_player()->more_string(ws);
  return 1;
}

static int cmd(string str, object me) {
  string ws;

  ws = who_string((int)me->query_cols(), (int)me->query_creator(), str);
  me->more_string(ws);
  return 1;
}

