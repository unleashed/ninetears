#include "tweaks.h"

/*** Cone of Cold Spell ***/
/*** Created by Eerevann Tokani ***/
/*** Adapted to spell base object by Wonderflug ***/

#define TYPE "cold"
#define SIZE_OF_DICE 4
#define save_type "cold"
#define STILLCASTING "stillcasting"

inherit "/std/spells/base.c";

int wiz_fix_damage(object caster,object victim,int damage,string save);

void setup()
{
  set_spell_name("Cone of Cold");
  set_school("invocation");
  set_spell_level(5);
  set_target_type("one");
  set_range(2);
  set_line_of_sight_needed(1);
  set_help_desc("This spell shoots a blast of cold and frost at a single "
    "target.  The damage done is (caster's level)d4 + caster's level.  There "
    "is no maximum to the damage on this spell.\n");
  set_help_extras("Damage Type" TYPE "\nSaving Throw 1/2");
  
  set_casting_time(1);
  set_rounds( ({ "round1" }) );

  set_gp_cost(10);

}

int round1(object caster, mixed target, mixed out_of_range, int time)
{
  int damage;
  int NO_OF_DICE;
  int i;
 
  if ( !objectp(target) )
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

  tell_object(caster, "You chant, 'frezzus es coe'.\n");
  tell_room(environment(caster), (string)caster->query_cap_name() +
    " chants, 'frezzus es coe'.\n");

  tell_object(target, (string)caster->query_cap_name()+
    " makes a gesture toward you and a nimbus of cold blasts over "
    "you \nin a freezing cone.\n");
  tell_object(caster, "You deep-freeze "+
    (string)target->query_cap_name() + " in a numbing cone of cold.\n");
  tell_room(environment(caster),(string)caster->query_cap_name()+
    " finishes a spell as a cone of cold blasts "+
    target->query_cap_name()+".\n",
    ({target,caster}) );
  if ( environment(caster) != environment(target) )
    tell_room(environment(target), target->query_cap_name()+" is blasted "
      "by a cone of cold.\n",
      ({target}) );

  caster->add_timed_property(STILLCASTING,1,2);

  NO_OF_DICE = caster->query_level();
  if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;

  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage += NO_OF_DICE;
  damage = wiz_fix_damage(caster,target,damage,save_type);
  target->spell_damage(target,damage,TYPE,caster);
  target->attack_by(caster);

  return 0; 

}
