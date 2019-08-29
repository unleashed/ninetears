

object my_player;

void destruct_stun_shadow() 
{
  destruct(this_object());
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
}

int check_duration()
{
  if ( !my_player || !(my_player->query_timed_property("stun_on")) )
  {
    if ( my_player )
      my_player->remove_extra_look(this_object());
    return 1;
  }
  else return 0;
}

mixed move( mixed dest, mixed messout, mixed messin )
{
  if ( check_duration() )
    call_out("destruct_stun_shadow",0,0);
  return my_player->move(dest, messout, messin );
}

int query_hold_spell() { return 1; }

object* query_weapons_wielded()
{
  if ( check_duration() )
    call_out("destruct_stun_shadow",0,0);
  return ({ this_object() });
}

int weapon_attack( object him, object me )
{
  tell_object(me, "Estas demasiado concentrado como para atacar!\n");
  tell_room(environment(me), me->query_cap_name()+" intenta atacar pero no puede.\n", me);
  if ( check_duration() )
    call_out("destruct_stun_shadow",0,0);
  return 0;
}

int shield_attack(object him, object me)
{
	if (check_duration())
		call_out("destruct_stun_shadow",0,0);
	return 0;
}

int attack_ob(object ob) 
{
  tell_object(my_player, "Estas demasiado concentrado como para atacar!\n");
  if ( check_duration() )
    call_out("destruct_stun_shadow",0,0);
  return 0;
}

/* for the player's desc. */
string extra_look()
{
  return "Esta concentrado invocando un Portal entre los Planos.\n";
}

varargs mixed move_player(string dir, string dest, mixed message, object
                                followee, mixed enter)
{
  if ( this_player(1) && this_player(1)->query_creator() )
    return my_player->move_player(dir, dest, message, followee, enter);

  //tell_object(my_player, "No estas en condiciones de intentar eso, estas aturdido.\n");
  notify_fail("Estas demasiado concentrado como para hacer otra cosa.\n");

  if ( check_duration() )
    call_out("destruct_stun_shadow",0,0);

  return 0;
}
