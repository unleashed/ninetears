/*** Major "+TYPE+" Protection Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Re-written as inheritable, Taniwha 1995 */
/*** Using base spell, Wonderflug 1996 ***/

inherit "/std/spells/base.c";

string SP_NAME = "Major Cold Resistance";
int GP_COST = 14;
int level = 7;
string TYPE = "cold";
string save_type = "magical";
int base_save = 50;
int base_div =1;
int base_duration = 100;
int dur_mult = 8;
string chant_message = "marj corozev rissas";

void setup()
{
  set_spell_name(SP_NAME);
  set_spell_level(level);
  set_school("abjuration");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell reduces damage done by "+TYPE+" based attacks "
    "by "+base_save+"% plus + 1% per level of the caster."
    "The duration is based upon the casters level.");

  set_gp_cost(GP_COST);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int resist_value;
  int level;
  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }
  
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants \""+chant_message+"\".\n", ({caster}));
    tell_object(target, "You chant \""+chant_message+"\".\n");
  }
    
  if(target == caster)
  { 
    tell_object(caster, "You cast "+SP_NAME+" upon yourself.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+target->query_objective()+"self.\n",target);
  }
  else
  {
    tell_object(target, "You feel resistant to "+TYPE+" attacks.\n");
    tell_object(caster, "You cast "+SP_NAME+" on "+
      (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+target->query_cap_name()+".\n",
      ({target,caster}) );
  }

  level = (int)caster->query_level();
  resist_value = (level/base_div) + base_save;
  resist_value = wiz_fix_damage(caster,target,resist_value,save_type);
  target->add_timed_property(TYPE,resist_value,base_duration+(level*dur_mult));

  return 0;
}


