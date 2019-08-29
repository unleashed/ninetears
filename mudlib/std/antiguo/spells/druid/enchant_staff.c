/*** Enchant Staff -- Druids Spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Enchant Staff");
  set_spell_level(3);
  set_sphere("druid");

  set_target_type("item");
  set_range(0);

  set_help_desc("This spell will place an enchantment on a staff.  The power "
    "of the enchantment is +1 per 8 levels of the druid, to a maximum "
    "of +5.  Multiple enchants are not cumulative; the most recent "
    "enchant will be the one in effect.  It is rumored that some "
    "special staves will both increase the power of the enchantment "
    "and add some extra abilities and powers over nature.  The "
    "existence of these legendary staves is emphatically "
    "denied in the highest Druidic Circles.");

  set_gp_cost(ENCHANT_GP);
  set_casting_time(4);
  set_rounds( ({ "round1", "round2", "round3", "round4" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target )
    return 0;

  tell_object(caster, "You draw in power from the world for your "
    "enchantment.\n");
  tell_room(environment(caster), caster->query_cap_name()+" goes into "
    "an odd trance-like state.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target )
    return 0;

  tell_object(caster, "You hold the "+target->query_short()+
    " out in front of you.\n");
  tell_room(environment(caster),caster->query_cap_name()+
    " holds a "+target->query_short()+" out in front of "+
    caster->query_objective()+".\n", caster );
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target )
    return 0;

  tell_object(caster, "You release the "+target->query_short()+
    ", and it hovers in the air in front of you.\n");
  tell_room(environment(caster), caster->query_cap_name()+
    " releases the "+target->query_short()+" and it hovers in "
    "mid-air!\n", caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i, j;

  if ( !target )
  {
    tell_object(caster, "The object of your enchant seems to have "
      "disappeared!  Oopsie.\n");
    return -1;
  }

  if ( (string)target->query_weapon_name() != "quarterstaff" )
  {
    tell_object(caster, "You come out of the trance and realize you "
      "cannot enchant this item!\n\nThe backlash of power whips you.\n");
    tell_room(environment(caster), caster->query_cap_name()+" comes out "
      "of the trance and glows briefly with power.\n\nThe power goes out "
      "of control and whips "+caster->query_cap_name()+"!\n\n"+
      caster->query_cap_name()+" howls with pain.\n", caster);
    caster->adjust_hp(-random(ENCHANT_BACKLASH)-1);
    return 0;
  }


  tell_object(caster, "You come out of the trance and channel your power "
    "into the "+target->query_short()+".\n");
  tell_room(environment(caster), caster->query_cap_name()+" glows with a "
    "soft blue aura that slowly seeps into the "+target->query_short()+
    ".\n", caster);
  tell_room(environment(caster), "The "+target->query_short()+" pulses "
    "with a blue radiance that slowly fades away.\n\nThe "+
    target->query_short()+" drops to the ground.\n");

  i = (int)caster->query_level() / 8;
  i = ( i < 1 ? 1 : ( i > 5 ? 5 : i ));

  target->set_enchant(i);

  return 0;
}
