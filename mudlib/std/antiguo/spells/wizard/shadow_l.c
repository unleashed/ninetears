/*** Shadow Magic Lightning Bolt Spell ***/          
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Shadow Magic Lightning Bolt"
#define GP_COST 10
#define SPELLTYPE "offensive"
#define TYPE "electrical"
#define SIZE_OF_DICE 6
#define save_type "spells"

inherit "/std/spells/base.c";


void setup()
{
  set_spell_name("Shadow Magic Lightning Bolt");
  set_spell_level(5);
  set_school("illusion");

  set_target_type("one");
  set_range(5);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: "+TYPE+"\n"
    "Saving Throw: Special");
  set_help_desc("    This spell is one of the Shadow Magic spells.  "
    "Shadow Magic channels in energy from the Shadow Plane to make "
    "quasi-real wizard spells.  The spell "
    "creates the illusion of a lightning bolt that strikes the target "
    "doing (level)d6 with a maximum of 10d6 damage (the target gets "
    "a saving throw for half damage).  The target gets "
    "a saving throw to detect the illusion.  If he fails this saving "
    "throw, the spell works with the normal effects.  If the target "
    "makes his save (detecting the illusion) the shadow magic only does "
    "20% of normal damage.\n"
    "    Example:  10th level Caster casts Shadow Magic Lightning Bolt "
    "at Target."
    "  Target misses the saving throw and thinks its real.  Target will "
    "take 10d6 damage or 5d6 (if he makes a second saving throw).");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
 
  int wizthiefbonus;
  int i;
  int damage;
  int NO_OF_DICE;
  int DETECTED;

  DETECTED = 0;

  NO_OF_DICE = caster->query_level();
  NO_OF_DICE = ( NO_OF_DICE <= 0 ? 1 : ( NO_OF_DICE > 10 ? 10 : NO_OF_DICE ));

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if(target == caster)
  { 
    tell_object(target, "Wouldn't that be suicide?\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " stops casting.\n", target);
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'xlxyx de gadrum'.\n");
    tell_room(environment(caster), caster->query_cap_name()+
     " chants, 'xlxyx de gadrum'.\n", ({caster}));
  }
    
  wizthiefbonus = 0;
  if ( caster->query_guild_name() == "wizthief" )
    wizthiefbonus = NO_OF_DICE;

  if ( random((int)caster->query_level()) + wizthiefbonus <=
       random((int)target->query_int()) )
  {
    tell_object(caster, (string)target->query_cap_name()+
      " detects your illusion!\n");
    DETECTED = 1;

    tell_object(target, "You realize that "+
      (string)caster->query_cap_name()+"'s spell is only an "
      "illusion and disbelieve most of the damage!\n");
  }

  tell_object(target, (string)caster->query_cap_name()+
    " hits you with a Lightning Bolt.\n");
   
  tell_object(caster, "You cast Shadow Magic Lightning Bolt at "+
    (string)target->query_cap_name()+".\n");
   
  tell_room(environment(caster), (string)caster->query_cap_name()+
    " finishes a spell and "+target->query_cap_name()+" is struck "
    "with a lightning bolt.\n",({target,caster}) );

  if ( environment(target) != environment(caster) )
    tell_room(environment(target),target->query_cap_name()+" is struck "
      "with a lightning bolt.\n",({target}) );

  damage = roll(NO_OF_DICE, SIZE_OF_DICE);
  damage = wiz_fix_damage(caster,target,damage,save_type);

  if (DETECTED)
    damage = (damage*20)/100;

  target->spell_damage(target,damage,TYPE,caster);
  target->attack_by(caster);

  return 0;
}
