
/*** Greymist 1995 ***/
/*** Resist Disease Spell ***/
/*** Modded Taniwha 1996 for base.c ****/
#include "tweaks.h"
inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Resist disease");
  set_spell_level(4);
  set_school("protection");
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc(
       "    This spell offers 50% resistance to the debilitating effects "
        "of most diseases.  The duration is based upon the casters level.\n\n"
        );

  set_gp_cost(4);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int resist_value;
  int level;

  tell_room(environment(caster), (string)caster->query_cap_name()+
           " chants, 'immunus strongus'.\n", ({target,caster}));
  if(target == caster)
   {
    tell_object(target, "You chant, 'immunus strongus'.\n");
    tell_object(target, "You cast Resist disease upon yourself.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " casts a spell upon "+target->query_objective()+"self.\n",target);
   }
  else
  {
    tell_object(caster, "You chant, 'immunus strongus'.\n");
    tell_object(target, (string)caster->query_cap_name()+
                " chants, 'immunus strongus'.\n");
    tell_object(target, "You feel resistant to disease.\n");
    tell_object(caster, "You cast Resist disease on "+
    (string)target->query_cap_name() + ".\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
        " casts a spell upon "+target->query_cap_name()+".\n",
        ({target,caster}));
  }
  resist_value = cleric_fix_damage(caster,target,50,"magical");

  target->add_timed_property("disease", resist_value,
        10*(50+((int)caster->query_level())));
  return 4;
}


