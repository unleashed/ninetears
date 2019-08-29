/*** Falling Wall Spell ***/
/*** Coded by:  Taniwha ***/
/*** Fixed up by Wonderflug ***/
#define TYPE "impact" // yes this is correct it does impact damage
#define SIZE_OF_DICE 7
#define save_type "stone"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Crumble Wall");
  set_school("Wizthief");
  set_spell_level(5);

  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell collapses the walls in a room, crushing the "
    "occupants with the rubble.  The caster avoids damage until the roof "
    "falls in as well, then everyone takes double damage.  The damage caused "
    "is equal to the level of the caster d7, with a maximum of 15d7.");
  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: None");
 
  set_gp_cost(10);
  set_casting_time(3);

  set_rounds(
   ({
     ({ "The walls begin to rumble and shake as you start your spell.\n",
        "The walls begin to rumble and shake.\n" 
     }),
     ({ "The shaking suddenly stops as you near the end of your spell.\n",
        "The shaking suddenly stops and a dreadful silence cloaks the area.\n"
     }),
     "round3"
   }) );

}

mixed extra_checks(string str, object caster)
{
  if ( environment(caster)->query_outside() )
    return "Nobody's stupid enough to stand around outside next "
      "to a wall with YOU around.\n";

  if ( (int)environment(caster)->query_property("walls gone") >= 4 )
    return "There's no walls left to bring down here!\n";

  return 1;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  string str;
  object rubble;
  int NO_OF_DICE;
  int i, j;

  NO_OF_DICE = caster->query_level();
  if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;
  else if (NO_OF_DICE > 15)
    NO_OF_DICE = 15;
  
  if ( (i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);
  
  if(!pointerp(target) || !sizeof(target)) 
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'retro lithos' and the wall explodes!\n",
      caster);
    tell_object(caster, "You chant, 'retro lithos', the walls "
      "shudder as though the very mortar that binds then has "
      "been stolen.\n");
  }

  rubble = new("/std/object");
  rubble->move(environment(caster));
  rubble->reset_get();
  rubble->set_name("pile of rubble");
  rubble->add_alias("rubble");
  rubble->set_main_plural("piles of rubble");
  rubble->set_long("A pile of rubble, as you look round you realize "
    "that it's fallen from the walls here.\n");

  if ( (int)environment(caster)->query_property("walls gone") >= 2 )
  {
    tell_room(environment(caster), "As another wall falls down the entire "
    "roof collapses, to "+caster->query_cap_name()+
    "'s dismay.\n", caster);
    tell_object(caster, "You seem to have miscalculated..\n"
      "The roof collapses upon you!\n");
    target += ({ caster });
    NO_OF_DICE *= 2;
    NO_OF_DICE = ( NO_OF_DICE > 25 ? 25 : NO_OF_DICE );
  }

  environment(caster)->add_property("walls gone", 
    (int)environment(caster)->query_property("walls gone")+1);

  for ( i=0;i<sizeof(target);i++)
    if( target[i] && living(target[i]) )
    {
      target[i]->attack_by(caster);
      damage = roll(NO_OF_DICE,SIZE_OF_DICE);
      damage = wiz_fix_damage(caster,target[i],damage,save_type);
      target[i]->spell_damage(target[i],damage,TYPE,caster);
      tell_object(target[i], 
        "A wall crumbles and you are crushed by rubble.\n");
      tell_room(environment(caster), target[i]->query_cap_name()+" is pummeled "
        "by falling rubble.\n", target[i] );
    }

  if ( pointerp(out_range) && sizeof(out_range) )
    tell_object(caster, "Alas, "+query_multiple_short(out_range)+
      " got out of range of the falling wall.\n");

  return 0;
}

