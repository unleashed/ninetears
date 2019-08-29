
/*** Flesh to Stone ***/
/*** By Taniwha ***/
#include "tweaks.h"
#define STONED SPELLS+"stoned.c"
inherit "/std/spells/base.c";
void setup()
{
  set_spell_name("Flesh to stone");
  set_spell_level(15);
  set_school("healing");
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("This spell turns flesh to stone. In particular, the "
    "victim cannot fight, can only move with incredible effort. "
    "The plus side is that the victim is nearly immune to physical "
    "Note: this spell does NOT wear off on it's own.\n");
  set_gp_cost(30);
  set_casting_time(2);
  set_rounds( ({ "round1","round2" }) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
   if(!target) return 0;
  if ( target->query_haste_spell() )
  {
    target->dispell_time_spell();
    return 0;
  }
if(target->query_dead() )
{
	tell_object(caster, "You can not stone a ghost!\n");
	return 0;
}
  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " glares stonilly at "+target->query_cap_name()+".\n",
      caster);
    tell_object(caster, "You glare stonilly at "+target->query_cap_name()+".\n");
  }
  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster,"An enchantment already on the target disrupts "
      "your spell.\n");
    return -1;
  }
  if ( target->query_property("stoned") )
  {
    tell_object(caster,"Your target has already been Stoned.\n");
    return -1;
  }
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration,mi;
  object ob;
  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }
if(target->query_dead())
{
	tell_object(caster,
		"Your spell failed... a ghost can not be turned to"
		" stone.\n");
	return -1;
}

  duration = wiz_fix_damage(caster, target, (int)caster->query_level(), "magical");
  if(random(duration) < 10)
  {
        tell_object(caster,"Your spell fails.\n");
        tell_object(target,"A cold shudder passes through you as you escape the spell.\n");
        target->add_timed_property("stoned",1,80000);
        return -1;
  }
  mi = target->query_property("mirror");
  tell_object(caster, "You cast flesh to stone at "+ target->query_cap_name()+".\n");
  if(mi > random(caster->query_level())+1) // Target is using a mirror of % reflection
  {
    tell_object(caster,"Alas however, your target seems to have come prepared with a mirror.\n");
    tell_object(caster, "You feel yourself slow, your body feels leaden slowing "
    "your every movement.\n"); 
    tell_room(environment(caster), caster->query_cap_name()+
      " eyes flash with brilliant green light at "+target->query_cap_name()+
      ", and "+caster->query_possessive()+" slows to a halt with a terrible grinding sound.\n",
      ({ caster, target}) ); 

    ob = clone_object(STONED);
    ob->move(caster);
    ob->reset_get();
    ob->setup_shadow(caster);
  }
  else
  {
    tell_object(target, "You feel yourself slow, your body feels leaden slowing "
    "your every movement.\n"); 
    tell_room(environment(caster), caster->query_cap_name()+
      " eyes flash with brilliant green light at "+target->query_cap_name()+
      ", and "+target->query_possessive()+" slows to a halt with a terrible grinding sound.\n",
      ({ caster, target}) ); 

    ob = clone_object(STONED);
        target->add_timed_property("stoned",1,80000);
    ob->move(target);
    ob->reset_get();
    ob->setup_shadow(target);
  }
  return 0;
}

