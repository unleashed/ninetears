/*** Bearhugging object ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#include "/std/spells/wizard/useful_stuff.c"
inherit "/obj/monster";

object my_player;
object my_target;
int tried_quit;

void do_death(object ob) { }

void destruct_bearhug()
{
  if (my_target)
	my_target->destruct_bearhug();
  if (my_player)
	my_player->destruct_bearhug();
  destruct(this_object());
}

void init()
{
  ::init();
  add_action("do_release","release");
  add_action("block_get", "take");
  add_action("block_get", "get");
  add_action("block_get", "palm");
  add_action("block_quit","quit");
  set_heart_beat(1);
}

void setup_item(object me,object him)
{
  my_player = me;
  my_target = him;
  tried_quit = 0;
  init();
}

int query_auto_load() { return 1; }

void setup()
{
  set_dead(1);
  set_weight(0);
}

int block_quit(string str)
{
  if (this_player() != my_target)
    return 0;
  force_drop_everything(this_player());
  tell_object(this_player(),"Sorry, you can't take your equipment with you if you "
    "quit out of a bearhug.\n");
  tell_room(environment(this_player()), this_player()->query_cap_name()+
    " drops some stuff in "+this_player()->query_possessive()+" rush to leave "
    "the game.\n", this_player());
  tried_quit = 1;
  return 0;
}

int block_get( string str )
{
  if ( this_player() != my_target ) return 0;
  if ( !tried_quit ) return 0;
  tell_object(this_player(), "Nice try, but it wouldn't be much "
    "of a penalty if you could just pick everything up after, would it?\n");
  return 1;
}
int do_release( string str )
{
  if ( this_player() != my_player )
	return 0;

  tell_object(my_player, "You release "+my_target->query_cap_name()+
	" from the bearhug.\n");
  tell_object(my_target, my_player->query_cap_name()+" mercifully "
	"releases you.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+
        " releases "+my_target->query_cap_name()+" from the bearhug.\n",
        ({ my_player, my_target }) );
  my_player->remove_static_property("noguild");
  my_player->remove_static_property("nocast");
  my_target->remove_static_property("noguild");
  my_target->remove_static_property("nocast");
  call_out("destruct_bearhug",0,0);
  return 1;
}

void heart_beat()
{
  if( !my_player || (int)my_player->query_dead() 
	|| !my_target || (int)my_target->query_dead() )
	destruct_bearhug();

  set_heart_beat(1);
}

