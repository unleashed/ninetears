/***  Sobriety Spell  ***/
/*** Blame this spell on Caanan ***/
/*** ->base spell, Wonderflug ***/
 
inherit "/std/spells/base.c";
 
#define ALCOHOL 0
#define VOLUME -200
#define LVL_FACTOR -10 
#define MIN_DRUNK 0
 
void setup()
{
  set_spell_name("Sobriety");
  set_spell_level(2);
  set_school("bard");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell sobers up the target when intoxicated.  "
    "Amount of sobriety increases with level of bard.");

  set_gp_cost(4);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " sings:\n\n"   
      "   Adventure has waited, we've been in a slump,\n"  
      "   No treasure we've plundered, nor goods not a lump.\n"
      "   How can we overcome this inebriated hump?\n"
      "   Mind to your manners and stop being " 
      "drunk.\n\n", ({caster}) );
    tell_object(caster, "You sing:\n\n" 
      "   Adventure has waited, we've been in a slump,\n"  
      "   No treasure we've plundered, nor goods not a lump.\n"
      "   How can we overcome this inebriated hump?\n"
      "   Mind to your manners and stop being " 
      "drunk.\n\n");
  }

  if ( target == caster )
  {
    tell_object(target, "You cast Sobriety upon yourself.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " casts a spell upon "+target->query_objective()+"self.\n",target);
  }
  else
  {
    tell_object(target, "You feel less inebriated.  What a drunk!\n");
    tell_object(caster, "You cast Sobriety on "+
      (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster), target->query_cap_name()+
      " seems to sober up a bit.\n",
      ({target,caster}) );
  }
 
  if ((target->query_volume(ALCOHOL)) > MIN_DRUNK)
  {
    target->adjust_volume(ALCOHOL, 
      VOLUME+((int)caster->query_level()*LVL_FACTOR));
  }
  
  return 0;
}
