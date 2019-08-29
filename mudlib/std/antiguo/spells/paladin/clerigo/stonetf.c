
/*** Stone to Flesh ***/
/*** By Taniwha ***/
#include "tweaks.h"
inherit "/std/spells/base.c";
void setup()
{
  set_spell_name("Stone to Flesh");
  set_spell_level(10);
  set_school("healing");
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("This spell reverses the flesh to stone spell.\n");
  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration,mi;
  object ob;
  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }
  if(!target->query_stone_spell())
  {
    tell_object(caster,"Um, not a statue, sorry, no can do.\n");
    return -1;
  }
  duration = wiz_fix_damage(caster, target, 100, "magical");
  if(random(duration) < 10)
  {
        tell_object(caster,"Your spell fails.\n");
        tell_object(target,"A warm breeeze passes over you, alas that is all that happens .\n");
        target->add_timed_property("stoned",1,200);
        return -1;
  }
  mi = target->query_property("mirror");
  tell_object(caster, "You cast stone to flesh at "+ target->query_cap_name()+".\n");
  if(random(mi) > random(caster->query_level())+1) // Target is using a mirror of % reflection
  {
    tell_object(caster,"Alas however, your target seems to have a mirror and nothing happens.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " eyes flash with brilliant green light at "+target->query_cap_name()+
      ", and "+caster->query_possessive()+" shudders but the spell doesn't break!.\n",
      ({ caster, target}) ); 
    return -1;
  }
  else
  {
    tell_object(target, "You feel yourself soften and warm "
    "as your body returns to flesh.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " eyes flash with brilliant green light at "+target->query_cap_name()+
      ", and "+target->query_possessive()+" shudders monentarilly and flakes of stone fall to the ground.\n",
      ({ caster, target}) ); 
    target->dispell_me();
  }
  return 0;
}


