#define MIN_LVL 1
#define GP_COST 15
 
mixed spell(string str, int skill, int cast);
 
int cast_spell(string str)
{
 int skill;
 mixed ret;
 
 str = (string)this_player()->expand_nickname(str);
 
 if (str == (string)this_player()->query_name())
 skill = (int)this_player()->query_skill_bonus("occult.spells.enchanting");
 else
 skill = (int)this_player()->query_skill_bonus("occult.spells.enchanting");
 
 if (skill < MIN_LVL)
 {
  notify_fail("You are not skilled enough to cast Sight.\n");
  return 0;
 }
 
 ret = spell(str, skill, 1);
 if (stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You chant a few words of incantation.\n");
 return 1;
}
 
mixed spell(string str, int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("misc"))
  return "You are already casting a miscelleanous spell.\n";
 
 ob = find_match(str, environment(this_player()));
 
 if(sizeof(ob))
  ob = ob[0];
 
 else
  ob = 0;
 
 this_player()->add_spell_effect(1, "misc", "Sight", this_object(),
  "hb_spell", ({ skill,ob,cast }));
 
 return 1;
}
 
int hb_spell(object caster, mixed *params)
{
 int skill, light;
 mixed who;
 
 skill = params[0];
 
 if(!params[1])
 {
  tell_object(previous_object(), "You can't bestow sight on someone "
   "who is not present.\n");
  return 0;
 }
 
 if(params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Not enough GP too complete spell.\n");
  return 0;
 }
 
 if (params[1] == previous_object())
 {
  tell_object(previous_object(),"You will now be able to see in any dark "
   "room.\n");
  say((string)previous_object()->query_cap_name() +
   " mumbles some strange words.\n"+
  (string)previous_object()->query_cap_name()+"'s eyes glow briefly.\n"
   , params[1]);
 }
 
 else
 {
  tell_object(previous_object(),"You cast Sight on "+
   (string)params[1]->query_cap_name()+", whose eyes glow briefly.\n");
  say((string)previous_object()->query_cap_name()+ "mumbles something and "+
   (string)params[1]->query_cap_name()+"'s eyes glow briefly.\n", params[1]);
  tell_object(params[1], (string)previous_object()->query_cap_name()+
   " mumbles something and points at you.\n""Your eyes feel much more "
   "sensitive to light.\n");
 }
 
 params[1]->set_light(50);
 call_out("wear_off", params[0]*4, params[1]);
 
 return 20;
}
 
void wear_off(object target)
{
 target->set_light(0);
 tell_object(target,"Your vision returns to normal.\n");
 say(target->query_cap_name()+"'s vision returns to normal.\n",target);
remove_call_out("wear_off");
}