/*** Neutralise Poison ***/
/*** -by Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Neutralise Poison");
  set_spell_level(2);
  set_sphere("plant");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell will cure the target of any maladies which "
    "happen to affect them.  Most notably, it will counteract the effect "
    "of Poison spells and other poisoned wounds.");

  set_gp_cost(4);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* obs;
  int i;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, 'toxus wrathi aborum'.\n", caster);
    tell_object(caster, "You chant, 'toxus wrathi aborum'.\n");
  }

  if ( target != caster )
    tell_object(caster, "You finish the spell and remove the poison from "+
      target->query_cap_name()+"'s body.\n");

  tell_room(environment(caster), (string)caster->query_cap_name()+
    " finishes the spell and "+target->query_cap_name()+
    " looks much better.\n", ({caster, target}));
  tell_object(target, "You start to feel "
    "much better as if the poison has left your body.\n");

  obs = all_inventory(target);
  for (i=0;i<sizeof(obs);i++)
    if ( (string)obs[i]->query_name() == "poisoned wound" )
      obs[i]->dispell_me();
 
  return 0;
}
