/*** Snowball Swarm Spell ***/
/*** Coded by:  Eerevann Tokani ***/
/*** Adapted to base spell by wonderflug ***/

#define TYPE "cold"
#define SIZE_OF_DICE 3
#define save_type "cold"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Snowball Swarm");
  set_spell_level(2);
  set_school("invocation");

  set_target_type("many");
  set_range(1);
  set_line_of_sight_needed(1);

  set_help_extras(
    "Damage Type: " TYPE "\n"
    "Saving Throw: 1/2");
  set_help_desc("This spell will pelt a group of your enemies with several "
       "snowballs.  The damage is 1-3 points per level of the caster up "
       "to 10th level.");

  set_gp_cost(10);
  set_casting_time(3);
   set_rounds( ({ "round1","round1","round1" }) );
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int NO_OF_DICE;
  int i;
 
  NO_OF_DICE = (int)caster->query_level();
  NO_OF_DICE = ( NO_OF_DICE <= 0 ? 1 : ( NO_OF_DICE > 10 ? 10 : NO_OF_DICE ));

  /* to remove the caster, if he uses 'all' */
  if((i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);

  if ( !sizeof(target) )
  {
    tell_object(caster,
      "Your spell failed ... there is noone here by that name.\n");
    return -1;
  }

  tell_room(environment(caster), caster->query_cap_name()+ 
    " chants, 'spheros frezious'.\n", ({caster}));
  tell_object(caster, "You chant, 'spheros frezious'.\n");

  i = 0;
  for (i=sizeof(target)-1; i>=0; i-- )
  {
   if( !target[i] || !target[i]->query_alive() )
   {
      target -= target[i];
      continue;
   }
    tell_object(target[i], caster->query_cap_name()+ 
      " hits you with a swarm of snowballs!\n");
    tell_room(environment(target[i]), target[i]->query_cap_name()+
      " is pelted with little balls of ice.\n", target[i] );

    damage = roll(NO_OF_DICE, SIZE_OF_DICE);
    damage = wiz_fix_damage(caster,target[i],damage,save_type);
    target[i]->spell_damage(target[i],damage,TYPE,caster);

    target[i]->attack_by(caster);
  }

  tell_object(caster, "You envelope " + query_multiple_short(target) + 
    " in a snowball swarm!\n");

  if ( sizeof(out_range) )
    tell_object(caster, "Alas, "+query_multiple_short(out_range)+
      " made it out of the range of your swarm.\n");

  return 1;
}
