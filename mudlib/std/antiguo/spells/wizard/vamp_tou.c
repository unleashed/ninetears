/*** Vampiric Touch Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Adapted to base spell by Wonderflug ***/

#define TYPE "magical"
#define SIZE_OF_DICE 6
#define save_type "magical"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Vampiric Touch");
  set_school("necromancy");
  set_spell_level(3);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: None");
  set_help_desc("This spell allows the caster to drain hit points from a target"
    "and transfer them to himself.  The caster gets one half the "
    "hit points drained transfer to him.  The caster may not exceed his "
    "normal maximum of hit points.  The damage done is 1d6 "
    "for each 2 levels of the caster with a maximum of 6d6 at 12th "
    "level.  Undead creatures love to be affected by this spell.\n");

  set_gp_cost(6);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int NO_OF_DICE;
 
  NO_OF_DICE = (((int)caster->query_level())/2);
  NO_OF_DICE = ( NO_OF_DICE <= 0 ? 1 : ( NO_OF_DICE > 6 ? 6 : NO_OF_DICE ));

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if(target == caster)
  {
    tell_object(target, "Wouldn't that be suicide?\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " stops casting.\n",target);
  }

  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'gimme ye helth'.\n", ({caster}));
    tell_object(caster, "You chant, 'gimme ye helth'.\n");
  }

  target = check_melee_protector( target, caster );

  if (!living(target) || target->query_dead() )
  {
    tell_object(caster, "You need to cast this on living things.\n");
    return -1;
  }

  tell_object(target, (string)caster->query_cap_name()+
    " touches you and you feel drained of health as "+
    (string)caster->query_cap_name()+" looks refreshed.\n");
   
  tell_object(caster, "You cast Vampiric Touch at "+
    (string)target->query_cap_name() + " and feel refreshed.\n");
   
  tell_room(environment(caster),(string)caster->query_cap_name()+
    " finishes a spell and touches "+target->query_cap_name()+" as "
    " lifeforce seems to pass between the two.\n",
    ({target,caster}) );

  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage = wiz_fix_damage(caster,target,damage,save_type);

  if(target->query_property("undead") ) 
  {
    tell_object(caster, "As you cast on the undead creature, you feel "
      "something has strangely gone awry..\n");
    damage = -damage;
  }

  target->spell_damage(target,damage,TYPE,caster);
  caster->adjust_hp(damage/2,target); 
  target->attack_by(caster);

  return 0;
}
