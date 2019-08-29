/*** Power Word: Stun ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#define PW_STUN_SHADOW "/std/commands/shadows/stun.c"

inherit "/std/spells/base.c";


void setup()
{
  set_spell_name("Power Word: Stun");
  set_spell_level(7);
  set_school("conjuration");

  set_target_type("all");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell allows you to shout the Stun Power Word. "
    "Everyone in the room with you will be stunned for 1-5 rounds.  During "
    "this time, they cannot attack, move, or cast spells, and are more "
    "vulnerable to be attacked.");

  set_gp_cost(14);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* ob;
  int i, j;
  int resist, theroll;
  object* shadows;

  if (!sizeof(target))
  {
    tell_object(caster, "You shout the power word, but nobody is here "
      "to hear it.\n");
    return -1;
  }

  shadows = allocate(sizeof(target));

  /* No quiet version of this, duh */
  tell_room(environment(caster), caster->query_cap_name()+
    " shouts: STUN!!\n", caster);
  tell_object(caster, "You shout: STUN!!\n\n");

  for (i=0;i<sizeof(target);i++)
  {
    if ( target[i] == caster || !living(target[i]) || target[i]->query_dead()
         || target[i]->query_creator() )
      continue;

    if ( target[i]->query_time_spell() )
    {
      tell_object(target[i], "The Power Word destroys your "
        "enchantment!\n");
      target[i]->dispell_time_spell();
    }

    j = random(5)+1;

    /* Pass a dummy property, we just want to adjust up from wizard's int */
    j = wiz_fix_damage(caster, target[i], j, "nothingnonsense");
    resist = (int)target[i]->query_property("magical");
    theroll = random(100);

    if ( j <= 0 || target[i]->query_hold_spell() || 
         target[i]->query_pacify_spell() || theroll < resist)
    {
      tell_room(environment(caster), target[i]->query_cap_name()+
        " resists the effects of the Power Word.\n", target[i]);
      tell_object(target[i],"You resist the effects of the Power Word.\n");
      continue;
    }

    tell_room(environment(caster), target[i]->query_cap_name()+" succumbs "
      "to the Power Word and falls over unconscious.\n", target[i]);
    tell_object(target[i], "You succumb to Power Word and black out.\n");

    target[i]->add_timed_property("stun_on", 1, j);
    target[i]->add_timed_property("nocast",1, j);
    target[i]->add_timed_property("noguild",1, j);
    target[i]->add_timed_property("passed out",
      "You are still recovering from the power word, and can't do anything.\n", 
      j);

    shadows[i] = clone_object(PW_STUN_SHADOW);
    shadows[i]->setup_shadow(target[i], j); 
    target[i]->add_extra_look(shadows[i]);

    target[i]->attack_by(caster);
  }

  return 0;
}

