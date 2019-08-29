/*** Sex Change Spell ***/
/*** By Wonderflug ***/

#define SP_NAME "Sex Change"
#define SPHERE "Quest"
#define LEVELX 7
#define GP_COST 200
#define TYPE "laughter"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Sex Change");
  set_spell_level(7);
  set_sphere("all");

  set_target_type("one");
  set_range(0);

  set_help_desc("This powerful enchantment calls upon the power "
    "of your diety to change the sex of a target.  "
    "Due to its nature, its very taxing on the caster, "
    "and even the highest priests must meditate for days "
    "to cast it.  No guarantee is made that the sexual urges of the "
    "target will change too, of course.");

  set_gp_cost(200);	// We do not want gp cost to vary according to sphere.
  set_casting_time(3);
  set_rounds( ({ "round1", "round2", "round3" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "A nimbus of power forms in front of you.\n");
  tell_room(environment(caster), "A nimbus of power forms in front of "+
    caster->query_cap_name()+".\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( target->query_gender() == 1 )
  {
    tell_object(caster, "You shape the nimbus of power into a "
      "huge, glimmering pair of gardening shears.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " gestures, and the nimbus of power molds into a pair of...\n"
      "gardening shears?\n", caster);
  }
  else
  {
    tell_object(caster, "You form the nimbus of power into something "
      "rather phallic, and best not described here.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " shapes the nimbus of power into something "
      "indescribably phallic.\n", caster);
  }
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target->query_alive() || !living(target) )
  {
    tell_object(caster, "Sex is irrelevant to that.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " stops casting.\n", caster);
    return 0;
  }

  if ( !target )
  {
    tell_object(caster, 
      "Your spell failed ... there is nobody of that name here.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " stops casting.\n", caster);
    return 0;
  }
/*

  if( caster->query_gp() < 200 )
  {
    caster->adjust_gp(-200);
    tell_object(caster, "You are too exhausted to complete the spell.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " stops casting.\n", caster);
    return 0;
  }
*/

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'switchum changeum'!\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'switchum changeum'!\n", caster);
  }

  target->set_gender( (target->query_gender()==1?2:1) );
  if ( target->query_gender() == 1 )
  {
    if ( target != caster )
      tell_object(caster, "You send the.. nimbus.. hurling at "+
        target->query_cap_name()+".\nThere's a large flash, a scream, and "
        "suddenly "+target->query_cap_name()+" is a new man.\n");

    tell_object(target, "The phallic nimbus suddenly hurtles toward you, "
      "and you scream as a very \nfundamental change comes over you.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " gestures, and the phallic nimbus hurtles toward "+
      target->query_cap_name()+".\nA flash of light, and a scream, and "
      "you notice some change in "+target->query_cap_name()+".\n",
      ({ target, caster }) );
  }
  else
  {
    tell_object(target, "The glowing shears of power hurtle at you, "
      "ripping through your armor and \nsuddenly exploding.\n"
      "You feel something missing...\n");
    if ( target != caster )
      tell_object(caster, "You send the glowing shears of power "
        "at "+target->query_cap_name()+", who screams and suddenly \nlooks "
        "to have lost something vital.\n");
    tell_room(environment(caster), caster->query_cap_name()+" gestures, "
      "and the shears of power hurtle at "+target->query_cap_name()+
      ", who is \nenveloped screaming in bright light.\n"
      "When the light fades, "+target->query_cap_name()+
      " appears to have lost something vital.\n",
      ({ target, caster }) );
  }

  return 0;
}

