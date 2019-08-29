/*** Priest Light Spell ***/
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);
object caster;
/*** Revised by: Eerevann ***/

/*** Sun Sphere ***/
/*** level 1 ***/



#define GP_COST 2

mixed spell(string str, int skill, int cast);

string help() {
   return
   "\n\n"
   "Spell Name:  Light\n"
   "Sphere:  Sun\n"
   "Level: 1st\n"
   "Gp Cost: "+GP_COST+"\n"
   "Description: \n"
   "    This spell will create a small globe of light that is placed upon "
   "the target to help illuminate dark areas.  This spell must be cast on a "
   "target of some sort.\n"
	"    The spell has a limited duration.\n\n";
}

int cast_spell(string str,object cast)
{
 int skill;
 mixed ret;

 caster = cast ? cast : this_player();

 if(interactive(caster))
	 str = (string)caster->expand_nickname(str);


 ret = spell(str, skill, 1);
 if (stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 tell_object(caster,"You begin to cast Light.\n");
 tell_room(environment(caster),caster->query_cap_name()+" begins to cast a spell.\n");
 return 1;
}

mixed spell(string str, int skill, int cast)
{
 mixed ob;
 if ((int) caster->query_spell_effect("misc"))
  return "You are already casting a miscelleanous spell.\n";

 ob = find_one_match(str, environment(caster));

 if(sizeof(ob))
  ob = ob[0];

 else
  ob = 0;

 caster->add_spell_effect(1, "misc", "Light", this_object(),
  "hb_spell", ({ skill,ob,cast }));

 return 1;
}

int hb_spell(object caster, mixed *params)
{
 int skill, light;
 mixed who;


 if(!params[1])
 {
  tell_object(caster, "Your light spell fizzles since you "
   "can't see it's intended target.\n");
  return 0;
 }

 if(params[2] && (int)caster->adjust_gp(-GP_COST)<0)
 {
  tell_object(caster, "Your mind is too weary to cast.\n");
  return 0;
 }

 if (params[1] == caster)
 {
  tell_object(caster,"You will now be able to see in any dark "
   "room.\n");
  tell_room(environment(caster),(string)caster->query_cap_name() +
   " raises his hands and a globe of light appears.\n", params[1]);
 }

 else
 {
  tell_object(caster,"You cast light on "+
   (string)params[1]->query_cap_name()+", who starts to glow with light.\n");
  tell_room(environment(caster),(string)caster->query_cap_name()+ "mumbles something and "+
   (string)params[1]->query_cap_name()+" starts to glow with light.\n", params[1]);
  tell_object(params[1], (string)caster->query_cap_name()+
	" points at you and a globe of light appears in your hand.\n");
 }

 params[1]->set_light(60);
 call_out("wear_off", 500, params[1]);

 return GP_COST;
}

void wear_off(object target)
{
 target->set_light(0);
 tell_object(target,"Your globe of light disappears.\n");
 tell_room(environment(caster),target->query_cap_name()+" stops glowing with light.\n",target);

}
