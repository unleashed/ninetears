#include "path.h"
inherit "std/room";

object board;
void reset() {
   if (!board) {
      board = clone_object("/obj/misc/board");
      board->move(this_object());
      board->set_datafile("Tavern-news");
   }
}

void setup() {
   set_short("Discussion Board room");
   set_long(
      "This room was created to allow ease of posting that was not " +
      "previously available down stairs, in the Lady Luck Tavern.  " +
      "The bulletin board is for players to ask questions, give comments " +
      "and suggestions, and \(most importantly\) post what they want to " +
      "see on the Final Realms.\n");
   set_light(60);
   add_exit("down", ROOM +"ladyluck", "stairs");
   set_co_ord( ({ -3, -4, 1 }) );
}

dest_me() {
   if (board)
      board->dest_me();
   ::dest_me();
}
void event_enter(object ob)
{
int a;
a=(int)ob->query_property("npc");
if (a !=0) {
ob->move(ROOM + "ladyluck.c");
 }
}

