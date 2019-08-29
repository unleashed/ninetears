#include "path.h";
inherit "/std/room";
#include "path.h"

void setup ()
{
  set_short("Hall of the Silver Fist");
   set_long("This is the heart of the Band's complex.  It is here that "+
   "the most worthy men and women of the Realms come to recieve the "+
   "token that will invest them with the Power of the Silver Fist.  "+
   "If you have proven yourself Worthy, type 'join' to join the band.\n");

	set_light (80);

   add_exit("east",ROOM+"hall1","door");
}

void init()
{
 add_action("get_amulet","join");
 ::init();
}
 
get_amulet()
{
  object ob, *stuff;
 
  int i;
 
  if(sizeof(find_match("fister_amulet",this_player())))
    {
     write("You already have an amulet, you do not need another.\n");
     return 1;
    }
 say(this_player()->query_cap_name()+" joins the Band!\n");
 write("You join the Band and are given your Amulet of Membership.\n");
   log_file("s_f_amulet", this_player()->query_cap_name()+" got an amulet.\n");
 ob=clone_object(ROOM+"famulet.c");
 ob->set_drop();
 ob->move(this_player());
 ob->reset_drop();
 return 1;
}
