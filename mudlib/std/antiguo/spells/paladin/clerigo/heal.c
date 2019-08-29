/****  Heal Spell ****/
/**** Modified by Eerevann Tokani ****/
/*** -> base spell by Wonderflug ***/

inherit "/std/spells/base.c";

#define save_type "magical"

void setup()
{ 
  set_spell_name("Heal");
  set_spell_level(6);
  set_sphere("healing");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This is the most powerful healing spell in a cleric's "
    "repertoire.  The actual amount healed varies upon the sphere power "
    "of the caster, but in any case is unlimited and dependent on level.");

  set_gp_cost(12);
  set_casting_time(3);
  set_rounds(
    ({
      "round1",
      "round2",
      "round3"
    }) );

}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster, "You pray to your diety for ultimate healing power.\n");
  tell_room(environment(caster), caster->query_cap_name()+
    " looks to be praying to someone.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster, "Your diety smiles upon your request, "
    "and power floods into you.\n");
  tell_room(environment(caster), caster->query_cap_name()+
    " smiles beautifically, warmed by some inner glow.\n", caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet )
{
  int hp;
  int damage;
  // this goes, wf. mixed *curses;


  if (!target)
  {
    tell_object(caster, "Your spell fails to find its intended target, "
      "and the power leaves you.\n");
    return -1;
  }

  if (!living(target)) 
  {
    tell_object(caster, (string)target->query_cap_name() +
      " is happy with the way it is now and doesnt want any help" 
      " from you.\n");
    return -1;
  }

  if (target == caster) 
  {
    tell_object(caster,
      "You cast a healing spell on yourself and feel a warm" 
      " sensation.  God that felt good!\n");
    tell_room(environment(caster),
      (string)caster->query_cap_name() +
      " mumbles something and is fully healed.\n", target);
  }
  else 
  {
    tell_object(caster,
      "You channel the healing power into " + (string)target->query_cap_name() +
      ", fully healing "+(string)target->query_objective()+".\n");
    tell_room(environment(caster), (string)caster->query_cap_name() +
      " mumbles something then points at " +(string)target->query_cap_name() +
      ", fully healing "+(string)target->query_objective()+".\n",
      ({ caster, target }) );
    tell_object(target, (string)caster->query_cap_name() +
      " mumbles something then points at you.  You feel a warm" 
      " sensation.  God that felt good!\n");
  }


  hp = target->query_max_hp();

  /**  Roan here trying to make this work like other Healing Spells
       with the damage = cleric_fix_damage(caster,target,damage,save_type); 
       thingie....this might not be pretty.
       12/95
  **/

  damage = hp - (random(4)+1) - (int)target->query_hp();
  damage = cleric_fix_damage(caster,target,damage,save_type); 
  target->adjust_hp(damage, caster);
  tell_object(target, "You feel much healthier.\n");
 
/**********

  if ((int)target->query_tmp_int() < 0) {
    target->adjust_tmp_int(-((int)target->query_tmp_int()));
    tell_object(target, "Your intelligence returns to normal.\n");
    }
  if ((int)target->query_tmp_dex() < 0) {
    target->adjust_tmp_dex(-((int)target->query_tmp_dex()));
    tell_object(target, "Your dexterity returns to normal.\n");
	 }
  if ((int)target->query_tmp_wis() < 0) {
    target->adjust_tmp_wis(-((int)target->query_tmp_wis()));
    tell_object(target, "Your wisdom returns to normal.\n");
    }
  if ((int)target->query_tmp_str() < 0) {
    target->adjust_tmp_str(-((int)target->query_tmp_str()));
    tell_object(target, "Your strength returns to normal.\n");
    }
  if ((int)target->query_tmp_con() < 0) {
	 target->adjust_tmp_con(-((int)target->query_tmp_con()));
    tell_object(target, "Your constitution returns to normal.\n");
    }
  target->reset_all();

********/

  /* cure all curses */
/*
  if (sizeof((curses = (mixed *)target->query_curses())))
    for (i=0; i<sizeof(curses); i+=2)
      if (target->query_remove(curses[i])->query_remove(skill)) {
        target->remove_curse(curses[i]);
	  tell_object(target, "The curse of " + curses[i] + " is lifted.\n");
      }
*/

  /* cure all diseases */
/*
  if (sizeof((curses = (mixed *)target->query_diseases())))
    for (i=0; i<sizeof(curses); i+=2)
      if (target->query_remove(curses[i])->query_remove(skill)) {
        target->remove_disease(curses[i]);
        tell_object(target, "The " + curses[i] + " disease is cured.\n");
      }
 */

  return 0;
}
