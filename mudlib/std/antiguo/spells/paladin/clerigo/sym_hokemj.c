/*** Symbol Shadow -- For Hokemj's holy symbol power spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#define HOKEMJ_SYMBOL "/std/spells/items/hokemj_symbol.c"
object my_player;
int threshold;

void setup_spell(object ob)
{
  shadow(ob,1);
  my_player = ob;
  threshold = (int)my_player->query_level()*4;
  my_player->add_extra_look(this_object());
  my_player->add_timed_property("leaves_on",1,(int)my_player->query_level() );
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

void destruct_hokemjleaf_shadow()
{
  tell_object(my_player, "The glowing leaves surrounding you shrink and "
    "fit back together into your Holy Symbol.\n");
  tell_room(environment(my_player), "The glowing leaves surrounding "+
    my_player->query_cap_name()+" suddenly shrink and come together "
    "into \na Golden Four-Leaf clover.\n", my_player);
  my_player->remove_extra_look(this_object());
  clone_object(HOKEMJ_SYMBOL)->move(my_player);
  destruct(this_object());
}

int check_duration()
{
  int i;
  int j;

  if ( !my_player->query_property("leaves_on") && threshold <= 0 )
    return 1;
  else 
    return 0;
}

int query_skin_spell() { return 1; }
int query_mirror_spell() { return 1; }
int query_armor_spell() { return 1; }


int adjust_hp( int amount, object hitter)
{
  int ret;
  int num_blocking;
  int amount_blocked;
   if(!my_player) { call_out("destruct_hokemjleaf_shadow",0,0); return ; }

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
    call_out("destruct_hokemjleaf_shadow",0,0);
  return my_player->adjust_hp( ret , hitter );
}

string extra_look()
{
  return  "4 large, golden, glowing clover-leaves float in the air around "+
    my_player->query_cap_name()+".\n";
}

