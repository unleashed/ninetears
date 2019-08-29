#include "path.h"
inherit "std/room";

object board;

void reset() {
  if(!board) {
    board = clone_object("obj/misc/board");
    board->set_datafile("development");
    board->move(this_object());
  }
}

void setup() {
  set_light(80);
  set_short("Mud Development Office");
  set_long(
    "You are in the Development Office of the mud. Maps and charts of the "
    "world adorn the panelled walls. Forms sit on a table near the door "
    "for registration of new projects.\n");
  add_item("map", "Type 'list' to see available maps, and 'read' to look "
           "at one.\n");
add_exit("north",HEAVEN+"admin1.c","door");
}

void dest_me() {
  if (board)
    board->dest_me();
  ::dest_me();
}
