/******************
 * Dispell magic  *
 * -by Wonderflug *
 *****************/

#include "tweaks.h"
inherit "/std/spells/base.c";

#define TYPE "magical"
#define save_type "spells"

void setup()
{
  set_spell_name("Dispell Magic");
  set_sphere("summoning");
  set_spell_level(3);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell disrupts any enchantments that are upon the "
    "target. Higher level targets have enchantments (both good or bad) "
    "drawn to them more strongly, and thus enchantments on them will be "
    "more difficult to dispel.  A single dispel will only destroy one "
    "spell on the target, and will only affect one target.  This spell "
    "will not affect inanimate objects.  Casting on yourself might work, "
    "but could have some harmful side-effects.\n");

  set_casting_time(1);
  set_gp_cost(DISPELL_MAGIC_GP);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target )
  {
    tell_object(caster, "Your target has left.\n");
    return 0;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant \"nullo magius\".\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, \"nullo magius\".\n", caster);
  }

  if ( target == caster )
  {
    if ( random(caster->query_wis()) > random((int)caster->query_level()) )
    {
      tell_room(environment(caster), (string)caster->query_cap_name()+
        " finishes a spell but nothing seems to happen.\n", ({caster}) );
      tell_object(caster,"You complete your spell, but you realize that any "
        "enchantments on \nyourself were too powerful for your meager "
        "abilities to dispell.\n");
      return 0;
    }

    tell_object(caster, "You finish the spell and feel magic seep "
      "away from you.\n");
    tell_room(environment(caster), caster->query_cap_name()+" finishes a "
      "spell and seems oddly.. normal.\n", caster);
    caster->dispell_me();
    caster->add_timed_property("nocast", 1, (int)caster->query_level() );
    return 0;

  }
  else if ( (int)caster->query_wis() < random((int)target->query_level()) )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " finishes the spell with a gesture at "+target->query_cap_name()+
      ", \nbut nothing happens.\n", ({caster,target}));
    tell_object(caster,"You complete your spell, but you realize that any "
      "enchantments on \n"+target->query_cap_name()+" were too powerful "
      "for your meager abilities.\n");
    tell_object(target,caster->query_cap_name()+
      " finishes the spell with a gesture at you, but nothing \nseems to "
      "happen.\n");
    return 0;
  }

  tell_room(environment(caster), (string)caster->query_cap_name()+
	" finishes the spell with a flourish.\n", ({caster, target}));
  tell_object(target, caster->query_cap_name()+
	" finishes the spell with a gesture at you.\n");
  tell_object(caster, "You finish the spell and destroy the magic "
	"around "+target->query_cap_name()+".\n");

  /* Any dispellable enchantment on the target has a dispell_me() */
  target->dispell_me();

  return 0;
}
