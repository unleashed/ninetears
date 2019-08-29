/*** Resist Evil Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Changed this_player() calls to variable caster for NPC use -Caanan ***/
/*** ->base spell by Wonderflug ***/

#define TYPE "evil"
 
inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Resist evil");
  set_spell_level(2);
  set_sphere("protection");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell reduces damage done by evil based attacks "
    "by 50%.  The duration is based upon the casters level.");

  set_gp_cost(4);
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
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, 'Sinister rissas cleios'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'Sinister rissas cleios'.\n");
  }
    
  if(target == caster)
  { 
    tell_object(target, "You feel resistant to evil attacks.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " seems to radiate an inner goodness.\n",target);
  }
  else
  {
    tell_object(target, "You feel resistant to Evil attacks.\n");
    tell_object(caster, "You cast Resist Evil on "+
      (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster), (string)target->query_cap_name()+
      " seems to radiate an inner goodness.\n",
      ({target,caster}));
  }
 
  resist_value = 50;
  level = (int)caster->query_level();

  switch( caster->query_sphere_power("protection") )
  {
    case "minor":
      resist_value = 40;
      level -= 5;
      break;
    case "major":
      resist_value = 60;
      level += 5;
  }
 
  target->add_timed_property(TYPE, resist_value, 20*level);
  
  return 0;
}
