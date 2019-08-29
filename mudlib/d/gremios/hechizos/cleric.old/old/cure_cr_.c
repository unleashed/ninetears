#define MIN_LVL 20
#define DIVISOR 2
#define SP_COST 100
 
mixed spell(string str, int skill, int cast);
 
int cast_spell(string str)
{
  int skill;
  mixed ret;

  str = (string)this_player()->expand_nickname(str);
  if (str==(string)this_player()->query_name())
    skill = (int)this_player()->query_skill_bonus("faith.spells.curing.self");
  else
    skill = (int)this_player()->query_skill_bonus("faith.spells.curing.target");
  if (skill<MIN_LVL)
  {
    notify_fail("You are not skillful enough.\n");
    return 0;
  }
  ret = spell(str, skill, 1);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  write("You cast Cure Critical Wounds.\n");
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)this_player()->query_spell_effect("curative"))
    return "You are already casting a curative spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;
  this_player()->add_spell_effect(1, "curative", "Cure Critical Wounds",
    this_object(), "hb_spell", ({ skill/DIVISOR,ob,cast }));
  return 1;
  }

int hb_spell(object attacker, mixed *params)
{
  int hp;

  if (!params[1])
  {
    tell_object(previous_object(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  if (params[2] && (int)previous_object()->adjust_gp(-SP_COST)<0)
  {
    tell_object(previous_object(), "Too low on power.\n");
    return 0;
  }

  if(params[1] == previous_object())
  {
    say((string)params[1]->query_cap_name()+" cures some of "+
     (string)params[1]->query_possessive()+" critical wounds.\n", params[1]);
    tell_object(params[1], "You cure some of your critical wounds.\n");
  }
  else
  {
    say((string)previous_object()->query_cap_name() +
      " cures some of " + (string)params[1]->query_cap_name() +
      "'s critical wounds.\n", params[1]);
    tell_object(params[1], (string)previous_object()->query_cap_name() +
      " cures some of your critical wounds.\n");
    tell_object(previous_object(), "You cure some of " +
      (string)params[1]->query_cap_name() + "'s critical wounds.\n");
  }

  hp = (int)params[1]->query_hp();
  return ((int)params[1]->adjust_hp(params[0])-hp)/10+50;
}
