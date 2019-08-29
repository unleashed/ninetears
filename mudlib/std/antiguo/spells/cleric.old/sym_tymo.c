/*** Symbol Shadow -- For Tymoran's holy symbol power spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#define TYMORA_SYMBOL "/std/spells/items/tymora_symbol.c"
object my_player;
int threshold;

void setup_spell(object ob)
{
  shadow(ob,1);
  my_player = ob;
  threshold = (int)my_player->query_level()*4;
  my_player->add_extra_look(this_object());
  my_player->add_timed_property("leaves_on",1,
    (int)my_player->query_level() );
  tell_object(ob, "A bolt of pale blue lightning strikes your holy symbol "
	"shattering it into \n4 pieces!\nEach piece, perfectly fragmented "
	"along the leaves of the clover, starts to \nglow with a golden "
	"light.\nThe leaves grow larger and float in the air about you "
	"protectively.\n\n");
  tell_room(environment(ob), "A bolt of pale blue lightning lashes down "
	"from the heavens, shattering "+ob->query_cap_name()+"'s holy "
	"symbol!\nThe pieces glow with a soft golden light, and hover in "
	"the air around "+ob->query_cap_name()+".\n", ob );
}

void destruct_tymoraleaf_shadow()
{
  tell_object(my_player, "The glowing leaves surrounding you shrink and "
	"fit back together \n"
	"into your Holy Symbol.\n");
  tell_room(environment(my_player), "The glowing leaves surrounding "+
	my_player->query_cap_name()+" suddenly shrink and come together "
	"into \na Golden Four-Leaf clover.\n", my_player);
  my_player->remove_extra_look(this_object());
  clone_object(TYMORA_SYMBOL)->move(my_player);
  destruct(this_object());
}

int check_duration()
{
  int i;
  int j;

  if ( !my_player->query_property("leaves_on") && threshold <= 0 )
	return 0;
  else return 1;
}

int query_skin_spell() { return 1; }
/* This spell counts as both of these. */
int query_mirror_spell() { return 1; }
int query_armor_spell() { return 1; }


int adjust_hp( int amount, object hitter)
{
  int ret;
  int num_blocking;
  int amount_blocked;

  if ( amount >= 0 )
	return my_player->adjust_hp(amount, hitter);

  tell_object(hitter, "The glowing leaves floating around "+
	my_player->query_cap_name()+" move to block the blow.\n");
  tell_room(environment(my_player), "The glowing leaves floating around "+
	my_player->query_cap_name()+" move to block "+hitter->query_cap_name()+
	"'s attack.\n",
	({ hitter, my_player }) );

/* The math here gets a little ugly, remember amount is negative. :) */
  num_blocking = random(5);
  amount_blocked = amount*num_blocking/4;
  if ( threshold > 0 ) threshold -= (-amount_blocked);
  ret = amount - amount_blocked;
  tell_object(my_player, num_blocking+" leaves combine to deflect the "
	"attack!\n");
  if ( threshold < 10 )
    tell_object(my_player, "The glow around each leaf is starting to fade.\n");

  if ( check_duration() )
	call_out("destruct_tymoraleaf_shadow",0,0);
  return my_player->adjust_hp( ret , hitter );
}

/* Hmm.  We'll try it using ONLY adjust_hp, since most combat attacks
 * use adjust_hp, things that use set_hp SHOULD get through the leaf shield
 * I think.
 * Guess which shadow I used as a template? :)  -- WF.
int set_hp(int amount, object hitter)
{
  int ret;

  if ( amount >= (int)my_player->query_hp() )
	return my_player->set_hp(amount, hitter);

  tell_object(hitter, "Your attack glances off of "+my_player->query_cap_name()+
	"'s stone-like skin.\n");
  tell_object(my_player, hitter->query_cap_name()+"'s attack glances off "
	"your Stoneskin.\n");
  tell_room(environment(my_player), hitter->query_cap_name()+"'s attack "
	"glances off of "+my_player->query_cap_name()+"'s stone-like "
	"skin.\n",
	({ hitter, my_player }) );

  if ( check_duration() )
	call_out("destruct_tymoraleaf_shadow",0,0);
  return my_player->adjust_hp(
		((int)my_player->query_hp()-amount)*STONESKIN_FRACTION );
}
*/

string extra_look()
{
  return  "4 large, golden, glowing clover-leaves float in the air around "+
    my_player->query_cap_name()+".\n";
}

/* For the amount this spell costs, nondispellable.  (yet) 
void dispell_me()
{
  my_player->remove_timed_property("stoneskin_on");
  tell_object(my_player, "Your skin reverts to normal as the magic is "
	"destroyed.\n");
  tell_object(environment(my_player), my_player->query_cap_name()+
	"'s skin reverts to normal as the magic is destroyed.\n",
	my_player );
  my_player->remove_extra_look(this_object());
  destruct(this_object());
}
*/

