#define MIN_LVL 20
#define GP_COST 200
 
mixed spell(int skill, int cast);
 
int cast_spell(string str)
{
 int skill;
 
 skill = (int)this_player()->query_skill_bonus("occult");
 
 if (skill < MIN_LVL)
 {
  notify_fail("You are not skilled enough to cast Cauldron Portal.\n");
  return 0;
 }
 spell(skill, 1);
 write("You mutter a  quick chant.\n");
 return 1;
}
 
mixed spell(int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("misc"))
  return "You are already casting a miscelleanous spell.\n";
 
 this_player()->add_spell_effect(1, "misc", "Cauldron Portal", this_object(),
  "hb_spell", ({ skill,cast }));
 
 return 1;
}
 
int hb_spell(object caster, mixed *params)
{
 int skill;
 
 skill = params[0];
 
 if((int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Not enough GP too complete spell.\n");
  return 0;
 }
 say((string)previous_object()->query_cap_name()+
  " mutters a quick chant.\nA glowing circular portal appears.\n"+
  (string)previous_object()->query_cap_name()+" enters the portal.\n"
  "The portal disappears.\n", previous_object());
 tell_object(previous_object(),
   "A glowing circular portal appears.\nYou enter it.\nYou emerge from a cauldron.\n");
 say((string)previous_object()->query_cap_name()+
   " steps out of the cauldron and grins.\n");
 
previous_object()->move("/d/fr/wilderness/witch.c");
 return -((int)this_player()->query_level());
}
