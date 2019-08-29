/*** FlameStrike Spell ***/
/*** Created by Eerevann Tokani ***/
/*** ->base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define TYPE "fire"
#define SIZE_OF_DICE 8
#define save_type "fire"

void setup()
{
  set_spell_name("Flamestrike");
  set_spell_level(5);
  set_sphere("combat");

  set_target_type("one");
  set_range(3);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell brings down a column of (un)holy flame upon your "
    "enemy.  The damage caused is dependent upon the priesthood's "
    "combat sphere power.  Also note only the most vengeful combat dieties "
    "will strike a victim who has run away.");
 
  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int NO_OF_DICE;
  int env_check;

  switch( caster->query_sphere_level("combat") )
  {
    case "major":  
      env_check=0; 
      NO_OF_DICE=6;
      break;
    case "minor": 
      env_check=1; 
      NO_OF_DICE=6-random(3);
      break;
    default:
      env_check=1; 
      NO_OF_DICE=6;
  }

 
  NO_OF_DICE = 6;

  if ( !target || ( env_check && environment(target) != environment(caster)) )
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
    return -1;
  }
    
  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'flamious os colus'.\n", ({target,caster}));
    tell_object(caster, "You chant, 'flamious os colus'.\n");
  }

  tell_object(target, (string)caster->query_cap_name()+
    " brings down a pillar of flame upon you!\n");
   
  tell_object(caster, "You cast Flamestrike at "+
    (string)target->query_cap_name() + ".\n");
   
  tell_room(environment(caster),(string)caster->query_cap_name()+
    " envelopes "+target->query_cap_name()+" in a pillar of flame!\n",
    ({target,caster}) );


  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage = cleric_fix_damage(caster,target,damage,save_type);
  if ( random((int)target->query_level()) > random(40) )
    damage = damage / 2;
  target->spell_damage(target,damage,TYPE,caster);
  target->attack_by(caster);

  return 0;
}
