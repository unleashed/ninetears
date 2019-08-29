/*** Withering ***/
/*** Created by Wonderflug ***/
 
#include "tweaks.h"

inherit "/std/spells/base.c";

#define WITHER_OBJ "/std/spells/cleric/withering_obj.c"

void setup()
{ 
  set_spell_name("Withering");
  set_spell_level(WITHER_LEVELX);
  set_sphere("necromantic");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell makes the recipient very susceptible to small "
    "wounds and bruises.  Cuts and other minor wounds will appear "
    "periodically by this spell.  In addition, the target will be weakened "
    "somewhat. The spell will last for "+WITHER_DURATION_LEVELX+
    " rounds per level of the caster.");

  set_gp_cost(WITHER_GP);
  set_casting_time(2);
  set_rounds( ({ "round1", "round2" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(environment(caster), "A sudden stench of decay seems to fill the "
    "air.\n", ({ }) );
  return 0;
}


int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int resist;
  int theroll;

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( target->query_property("wither_on") )
  {
    tell_object(caster, "Your target is already withering away.\n");
    return 1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'xo harmi timus'.\n\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'xo harmi timus'.\n\n", ({ caster }));
  }

  /**  you guessed it.  Roan the resistance checker here making sure
       this spell checks for resistances.  In this case DISEASE :)
       using a 100 percentile roll to determine if you made it or not.
       If THEROLL is less than that of your resistance well the spell
       fails.  Else.  OWIE.
  **/
  resist = (int)target->query_property("disease");
  theroll = random(100);

  if(theroll < resist) 
  {
    tell_object(caster, "You point at "+target->query_cap_name()+" but "
      "nothing seems to happen!\n");
    tell_object(target,caster->query_cap_name()+" completes the spell, "
      "and points at you but nothing seems to happen!\n");
    tell_room(environment(caster),caster->query_cap_name()+" completes the "
      "spell and points at "+target->query_cap_name()+" but nothing "
      "seems to happen!\n", ({ caster, target }) );
    return 0;
  }
 
  ob = clone_object(WITHER_OBJ);
  ob->set_spell(target, (int)caster->query_level()/WITHER_AMOUNT_LEVELX);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();

  target->add_extra_look(ob);
  target->add_timed_property("wither_on",1,
    (int)caster->query_level()* WITHER_DURATION_LEVELX);
  target->adjust_temp_str(-3);

  tell_room(environment(caster), target->query_cap_name()+"'s skin starts "
    "to grow sickly, decaying slowly.\n", ({ caster, target }) );
  tell_object(caster,"You cast Withering at "+target->query_cap_name()+", "
    "and "+target->query_possessive()+" skin starts to decay.\n");
  tell_object(target, caster->query_cap_name()+" completes the spell, "
    "and you feel decay enter your body...\n");

  target->attack_by(caster);
}
