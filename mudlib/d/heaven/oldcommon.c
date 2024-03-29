#define HEAVEN "/d/heaven/heaven/"
inherit "std/room";

object board;

int i,n;
int x;
void reset() {
   object *all;
  if(!board) {
    board = clone_object("obj/misc/board");
    board->set_datafile("commonroom");
    board->move(this_object());
   }
   n = reclaim_objects();
   for(i = 0; i < sizeof(all=children("/global/lord.c")); i++)
   {
      if(all[i])
      tell_object(all[i],"[Objects reclaimed: "+ n +" ]\n");
   }
   //::reset();
}

void setup() {
  set_light(60);
  set_short("Habitacion Comun del Creador");
  set_long(
"You are in the Creator common room.  This room is for discussion of issues "+
"relating to the entire mud.  Feel free to put notes on the Board and "+
"please post your opinions on issue under discussion.  It is your"+
" mud too.. There is a portal to the bar here.  The door to the "+
"sur leads to the Palace of Immortals Admin wing.  The door to the"+
" north glow with power.  A plaque on the northern door reads: "+
"Immortal meeting chambers. A pulsing light in the shape of an arrow points "+
"to the east, beckoning you to enter.\n");
  add_exit("fuera", "/w/common", "door");
}

void dest_me() {
  if (board)
    board->dest_me();
  ::dest_me();
}
