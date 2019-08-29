/*** Regeneration ***/
/*** Created by Wonderflug ***/
 
#include "tweaks.h"

inherit "/std/spells/base.c";

#define REGEN_OBJ "/std/spells/cleric/regeneration_obj.c"

void setup()
{
  set_spell_name("Regeneration");
  set_spell_level(REGEN_LEVELX);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell makes the recipient recover from wounds much much "
    "faster.  Poisoned or other special wounds cannot be regenerated "
    "by this spell.  The spell will last for "+REGEN_DURATION_LEVELX+
    " rounds per level of the caster.  \n"
    "     Overuse of this spell has known to be permanently damaging.  "
    "Much like trolls born with the ability to regenerate innate, "
    "the recipient will become very susceptible to attacks from fire. "
    "Even once the spell has worn off, it is believed some residue is "
    "left over.  One notable high priest who used the spell regularly was "
    "known, after several years' use, to actually catch fire from "
    "the smallest campfire sparks.");

  set_gp_cost(REGEN_GP);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int amount, duration;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( target->query_armour_spell() || target->query_mirror_spell() ||
       target->query_property("regen_on") )
  {
    tell_object(caster, "Magic surrounding your target disrupts "
      "your spell.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'in mani timus'.\n\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'in mani timus'.\n\n", ({ caster }));
  }

  amount = (int)caster->query_level()/REGEN_AMOUNT_LEVELX;
  duration = (int)caster->query_level()*REGEN_DURATION_LEVELX;

  switch( caster->query_sphere_power("healing") )
  {
    case "minor":
      amount = 2*amount / 3;
      duration /= 2;
      break;
    case "major":
      amount = 3*amount / 2;
      duration *= 2;
      break;
  }

  ob = clone_object(REGEN_OBJ);
  ob->set_spell(target, amount);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();
  target->add_extra_look(ob);
  target->add_timed_property("regen_on",1, duration);

  /* Fire resistance hit.  Every three times it drops 1% */
  if ( (int)target->query_property("regen_fire_counter") == 2 )
  {
    target->add_static_property("fire",(int)target->query_static_property("fire")-1);
    target->add_static_property("regen_fire_counter", 0);
    tell_object(target, "You feel more susceptible to fire.\n");
  }
  else target->add_static_property("regen_fire_counter", 
    (int)target->query_property("regen_fire_counter") + 1 );

  if ( target != caster )
    tell_object(caster,"You cast Regeneration on "+target->query_cap_name()+
      ", and "+target->query_possessive()+" skin glows with health.\n");
  tell_room(environment(caster),caster->query_cap_name()+
      "'s skin starts to glow with health.\n", ({ caster }) );
  tell_object(target, "You feel health flow through you, and your "
    "skin starts to glow.\n");

  return 0;
}
