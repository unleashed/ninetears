#include "path.h"
inherit "/std/room";

void setup() {
   set_short("Beneigth the Stables");
   set_long("\nDaggerford :  Beneigth the Stables.\n\n"+
           "   You are in a secret room designed for one Mortal only "+
           "this is used for safety.  Please do not remove it.\n"+
           "\n");

    set_light(60);

    add_exit("up", ROOM+"stables", "door");
   add_exit("hoerk", "/d/hoerk/belaern/s_jung/city/SIG/grim_base.c", "portal");
   }
