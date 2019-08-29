#include <player.h>
/*** Power Word: Stun ***/
/*** By Wonderflug ***/

#include "tweaks.h"
#define PW_STUN_SHADOW "/d/gremios/comandos/shadows/stun.c"

inherit "/d/gremios/hechizos/base.c";

/* added "stun_bonus" property for a WISH */

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

  set_gp_cost(20);
  set_casting_time(3);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* ob;
  int i, j;
int bonus;
  int resist, theroll;
  object* shadows;

  if (!sizeof(target))
  {
    tell_object(caster, "Pronuncias la palabra poder pero no hay nadie aqui "
      "para oirla !!.\n");
    return -1;
  }

  shadows = allocate(sizeof(target));

  /* No quiet version of this, duh */
  tell_room(environment(caster), caster->query_cap_name()+
    " grita : %^BOLD%^WHITE%^S T U N ! ! ! ! !%^RESET%^\n", caster);
  tell_object(caster, "Gritas: %^BOLD%^WHITE%^S T U N ! ! ! ! !%^RESET%^\n\n");

  for (i=0;i<sizeof(target);i++)
  {
    if ( target[i] == caster || !living(target[i]) || target[i]->query_dead()
         || target[i]->query_creator() )
      continue;

    if ( target[i]->query_time_spell() )
    {
      tell_object(target[i], "La palabra poder destruye tus "
        "encantamientos!\n");
      target[i]->dispell_time_spell();
    }

    j = random(5)+1;
  j = j + caster->query_property("stun_bonus");

    /* Pass a dummy property, we just want to adjust up from wizard's int */
    j = wiz_fix_damage(caster, target[i], j, "nothingnonsense");
    resist = (int)target[i]->query_property("magical");
    theroll = random(100);

    if ( j <= 0 || target[i]->query_hold_spell() || 
         target[i]->query_pacify_spell() || theroll < resist)
    {
      tell_room(environment(caster), target[i]->query_cap_name()+
        " resiste los efectos de la palabra poder.\n", target[i]);
      tell_object(target[i],"Resistes los efectos de la palabra poder.\n");
      continue;
    }

    tell_room(environment(caster), target[i]->query_cap_name()+" sucumbe "
      "ante el poder y cae al suelo inconsciente.\n", target[i]);
    tell_object(target[i], "You succumb to Power Word and black out.\n");

    target[i]->add_timed_property("stun_on", 1, j);
    target[i]->add_timed_property("nocast",1, j);
    target[i]->add_timed_property("noguild",1, j);
    target[i]->add_timed_property(PASSED_OUT_PROP,
      "Aun te estas recuperando de tanto poder y no puedes hacer nada !!.\n", 
      j);

    shadows[i] = clone_object(PW_STUN_SHADOW);
    shadows[i]->setup_shadow(target[i], j); 
    target[i]->add_extra_look(shadows[i]);

    target[i]->attack_by(caster);
  }

  return 0;
}

