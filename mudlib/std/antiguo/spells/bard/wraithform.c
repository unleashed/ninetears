/*** By Wonderflug ***/

#include "tweaks.h"

#define WRAITH_OVERUSE_PROPERTY "wraith_overuse"
#define WRAITH_OVERUSE_CHECK 3
#define WRAITH_OVERUSE_ADJ_MAX 50
#define WRAITH_OVERUSE_DURATION 5

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Wraithform");
  set_spell_level(9);
  set_school("necromancy");

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell vapourises your mortal form, making you into "
    "nothing more than a vapourous cloud.  Only your body is transformed, so "
    "all of your equipment is dropped behind.  Of course, vapour cannot "
    "be attacked, neither by spell, nor by blade, and vapour is also "
    "harmless itself.  The cloud itself resembles a pale human outline, "
    "and hence the name, Wraithform.\n"
    "     The duration increases with level, but beware of using this "
    "spell too often, for it is said that those who do end up wraiths "
    "themselves, for eternity..");

  set_gp_cost(WRAITHFORM_GP_COST);
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,
    "Arms outstretched, you begin to chant.\n");
  tell_room(environment(caster),  caster->query_cap_name()+
    " begins to chant, arms outstretched.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "A swirling mist begins to form above you.\n");
  tell_room(environment(caster), "A swirling mist begins to form above "
    +caster->query_cap_name()+".\n", caster);
    
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int new_count;
  int duration, level;
  int j;
  object wraith;
  object* ob;

  if ( caster->query_wraith_spell() )
  {
    tell_object(caster, "You are already vapour!  What more do you want??\n");
    return -1;
  }
  level = (int)caster->query_level();
  new_count = (int)caster->query_timed_property(WRAITH_OVERUSE_PROPERTY);

  if ( new_count > (level+(int)caster->query_int())*WRAITH_OVERUSE_CHECK)
  {
    tell_object(caster,"You almost complete the spell, but suddenly you "
      "realize something is going horribly, utterly wrong.  The magic goes "
      "out of control, and you feel your life force disintegrate as "
      "surely as your body disintegrates into a cloud of mist.  An "
      "evil presence fills the wraith-like cloud your body has become, "
      "consuming the last of your life essence.\n\nYou die.\n");
    tell_room(environment(caster),
      " starts to cast a spell, then screams horribly as "+
      caster->query_possessive()+" body dissapates into a shadowy cloud "
      "of mist, leaving just a ghost behind.  Two glowing red eyes appear "
      "in the cloud, and the cloud takes on form, until you realize a "
      "wraith has been born.\n",
      caster);
    wraith = clone_object(WRAITH_MONSTER);
    wraith->move(environment(caster));
    ob = all_inventory(caster);
    wraith->give_caster_stats(caster);
    for (j=0;j<sizeof(ob);j++)
      ob[j]->move(wraith);
    wraith->init_equip();
    caster->remove_timed_property(WRAITH_OVERUSE_PROPERTY);
    caster->do_death();
    return 1;
  }

  new_count += WRAITH_OVERUSE_ADJ_MAX - (int)caster->query_int();

  if (level < 20)
  {
    tell_object(caster, "You are too low-level to complete this spell.\n");
    return -1;
  }

  duration = WRAITH_DURATION_BASE+(level*WRAITH_DURATION_LEVEL);

  caster->add_timed_property(WRAITH_PROPERTY, 1, duration);
  caster->add_timed_property(WRAITH_OVERUSE_PROPERTY,
	new_count, duration*WRAITH_OVERUSE_DURATION);
  caster->add_static_property("dead",1);

  
  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, 'corpus formis vaporis'.\n", 
      caster);
    tell_object(caster, "You chant, 'corpus formis vaporis'.\n");
  }

  tell_object(caster, "Your body dissolves into vapour, your equipment "
    "falling in a clutter to the ground, and you assume the form of a "
    "wraith.\n"); 
  tell_room(environment(caster), (string)caster->query_cap_name()+
    " finishes a spell and merges into the cloud of vapour, equipment "
    "falling in a clutter to the ground.  A wraithlike shadow moves "
    "off from where "+(string)caster->query_pronoun()+
    " was.\n", caster); 

  ob = all_inventory(caster);
  for (j=0;j<sizeof(ob);j++)
    caster->drop_ob(ob[j]->query_name());
  
  wraith = clone_object(WRAITH_SHADOW);
  wraith->setup_shadow(caster); 
  caster->add_extra_look(wraith);

  return 0;;
}

