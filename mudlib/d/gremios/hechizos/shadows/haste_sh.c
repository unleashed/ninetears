#include <spells.h>

object my_player;

void destruct_haste_shadow()
{
  if (interactive(my_player) && my_player->query_str()>3) my_player->adjust_tmp_str(-1);
  if (my_player->query_dex()>5) my_player->adjust_tmp_dex(-2);
  destruct(TO);
}

void setup_shadow(object ob)
{
  shadow(ob,1);
  my_player=ob;
}

int check_duration()
{
  if (!(my_player->query_timed_property("haste_on")))
  {
    tell_object(my_player,"Time seems TO resume its normal speed as the spell wears off.\n");
    tell_room(ENV(my_player),my_player->QCN+" doesn't seem TO be moving so fast anymore.\n",my_player);
    return 1;
  }
  return 0;
}

move(mixed dest, mixed messout, mixed messin)
{
  if (check_duration()) call_out("destruct_haste_shadow",0,0);
  return my_player->move(dest, messout, messin);
}

varargs mixed move_player(string dir, string dest, mixed message,object followee, mixed enter)
{
  if (check_duration()) call_out("destruct_haste_shadow", 0, 0);
  return my_player->move_player(dir, dest, message, followee, enter);
}

int query_haste_spell()
{
  return 1;
}

int query_time_spell()
{
  return 1;
}

int weapon_attack(object him, object me)
{
  int ret=0,i;
  object *weap;

  weap=my_player->query_weapons_wielded();
  if (sizeof(weap))
    for (i=0;i<sizeof(weap);i++)
      ret+=weap[i]->weapon_attack(him,me)+weap[i]->weapon_attack(him,me);
  else
    ret=my_player->unarmed_attack(him,me)+my_player->unarmed_attack(him,me);
  return ret;
}

object *query_weapons_wielded()
{
  if (check_duration()) call_out("destruct_haste_shadow",0,0);
  return my_player->query_weapons_wielded();
}

void dispell_me()
{
  my_player->remove_timed_property("haste_on");
  tell_object(my_player,"You move slowly again as time resumes its normal flow for you.\n");
  tell_room(ENV(my_player),my_player->QCN+" moves normally again as the magic is destroyed.\n",my_player);
  destruct(TO);
}

void dispell_time_spell()
{
  dispell_me();
}
