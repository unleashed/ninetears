/*** Focus ***/
/*** Fighter ability ***/
/*** By Wonderflug ***/

/* Unfortunately we have to use call_out's since we can't remove a 
 * spell effect in the middle of doing them.
 */

inherit "/std/spells/patch.c";


#define SKILL_NAME "Focus"
#define GP_COST 1

string help() {
 return
    "\n\n"
    "Command Name: "+SKILL_NAME+"\n"
    "GP Cost: "+GP_COST+" GP per round\n"
    "Syntax: focus <target>, focus off\n"
    "Description: \n"
    "     This ability lets you attempt to concentrate your blows "
    "upon a single foe.  If something is protecting the target you "
    "attempt to focus on, it is likely that you will be forced "
    "to go through it first.  Use 'focus off' to stop concentrating "
    "upon a foe.  After 1 round per level, you will lose your "
    "concentration and have refocus on your opponent.\n";
    
}

mixed spell(string str, object me);

int focus(string str,object doer)
{
  int skill;
  mixed ret;
  object me;

  me = doer ? doer : this_player();

  str = (string)me->expand_nickname(str);

  ret = spell(str, me);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  /* sanity check */
  if (!objectp(ret))
  {
    notify_fail("You fail to focus for some reason.\n");
    return 0;
  }
  tell_object(me,"You begin to focus your attack on "+str+".\n");
  tell_room(environment(me),me->query_cap_name()+" snarls and "
    "leaps at "+ret->query_cap_name()+".\n", me);
  return 1;
}

mixed spell(string str, object me)
{
  mixed ob;

  /* A future spell/command will use concentrate */
  if ((int)me->query_spell_effect("concentrate") ||
      me->query_property("flipped") )
    return "You are too enraged to focus on anything.\n";

  if ( str == "off" )
  {
    me->remove_spell_effect("focus");
    return "You stop focusing.\n";
  }
  
  ob = find_one_match(str, environment(me));
  if (!sizeof(ob) || !living(ob=ob[0]) ||
      member_array(ob, me->query_attacker_list()) == -1 )
    return "You are not fighting that.\n";

  /* override any current focus */
  if ((int)me->query_spell_effect("focus"))
    me->remove_spell_effect("focus");

  me->add_spell_effect((int)me->query_level(), 
    "focus", "focus", this_object(), "focus_func", ({ ob }));

  return ob;
}

int focus_func(object me, mixed *params, int time)
{
  if ( !params[0] || environment(params[0]) != environment(me) )
  {
    tell_object(me, "The target of your aggression has left.\n");
    call_out("end_focus", 0, me);
    return 0;
  }

  if ( me->adjust_gp(-GP_COST) < 0 )
  {
    tell_object(me, "You are too tired to concentrate further.\n");
    call_out("end_focus", 0, me);
    return 0;
  }

  me->set_concentrate(params[0]);
  if ( time == 1 )
    tell_object(me, "You lose your concentration.\n");

  return 0;
}

void end_focus(object me)
{
  me->remove_spell_effect("focus");
}
