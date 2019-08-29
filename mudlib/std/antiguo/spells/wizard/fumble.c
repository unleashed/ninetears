/*** By Wonderflug ***/

inherit "/std/spells/base.c";
#include "tweaks.h"

void setup() 
{
  set_spell_name("Fumble");
  set_spell_level(4);
  set_school("necromancy");

  set_target_type("one");
  set_range(2);
  set_line_of_sight_needed(1);

  set_help_desc("This spell causes the target to immediately fumble "
    "whatever is in their hand.  Depending on the skill of the caster, "
    "wielded weapons get either unwielded or dropped, and possibly other "
    "equipment as well.  Fast and experienced targets will not be "
    "affected as much.\n");

  set_casting_time(1);
  set_gp_cost(FUMBLE_GP_COST);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* ob;
  object* ob2;
  int caster_level; 
  int target_level;
  int caster_int; 
  int target_dex;
  int caster_roll; 
  int target_roll;
  int i, j;

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, 'digitis mali failus'.\n", caster);
    tell_object(caster, "You chant, 'digitus mali failus'.\n");
  }

  caster_level = (int)caster->query_level();
  target_level = (int)target->query_level();
  caster_int = (int)caster->query_int();
  target_dex = (int)target->query_dex();

  caster_roll = random(FUMBLE_CASTER_ADJ*(caster_level+caster_int));
  target_roll = target_level+
    random(FUMBLE_TARGET_ADJ*(target_level+target_dex));

  if ( caster_roll > target_roll )
  {
    tell_object(caster, "You cast Fumble on "+target->query_cap_name()+
      ", who is momentarily clumsy.\n");
    tell_object(target, caster->query_cap_name()+
      " completes his gestures, and you suddenly feel very clumsy, and"
      " can't hold on to your equipment.\n");
    tell_room(environment(target), caster->query_cap_name()+
      " finishes a spell with a gesture at "+target->query_cap_name()+
      ".\n", ({ caster, target }) );
  }
  else
  {
    tell_object(caster, "You cast Fumble on "+target->query_cap_name()+
      ", but nothing seems to happen.\n");
    tell_object(target, caster->query_cap_name()+
      " points at you, but nothing happens.\n");
    tell_room(environment(target), caster->query_cap_name()+
      " gestures at "+target->query_cap_name()+
      ", but nothing seems to happen.\n", ({ caster, target}) );
    return 1;
  }

  /* kludge since drop_ob notifies the caster of items dropping, not the
   * the target.  no way around except to rewrite drop_ob HERE, which is
   * an even worse kludge, i think.  -- wonderflug
   */
  caster_roll = target_roll+10;

  switch( caster_roll - target_roll )
  {
    case 1..20:
      ob = (object*)target->query_held_ob();
      for (i=0;i<sizeof(ob);i++)
        if ( ob[i] )
          target->unhold_ob(ob[i]);
      break;
    default:
      ob = all_inventory(target);
      ob2 = (object*)target->query_worn_ob();
      for (i=0;i<sizeof(ob);i++)
        if ( member_array(ob[i], ob2) == -1 )
          target->drop_ob(ob[i]->query_name());
      break;
  }

  // Make monsters attack sometimes (well, ok, often)
  if ( !interactive(target) && random(4) )
    target->attack_by(caster);
  
  return 0;
}
