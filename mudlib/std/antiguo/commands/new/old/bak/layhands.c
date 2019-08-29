/*** Hand of Healing ***/
/*** Paladin ability ***/
/*** By Wonderflug ***/

inherit "/std/spells/patch.c";

#define SP_NAME "Heal"
#define HEAL_LOCKOUT "lay_hands_done"
#define HEAL_LOCKOUT_TIME 600

string help() {
 return
	"\n\n"
	"Command Name: "+SP_NAME+"\n"
	"Syntax: layhands <target>\n"
	"Description: \n"
	"     This ability lets a Paladin summon the healing powers of "
	"the Demigods of Goodness to heal himself, or a wounded comrade. "
	"The amount healed is 2 hp per level of the Paladin.  This ability "
	"costs no GP, but may only be used once per day.\n"
        "NOTE: You cannot heal evil souls, and undead will take damage "
        "from the positive energy of this ability.\n\n";
}

mixed spell(string str, object caster);

int layhands(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  str = (string)caster->expand_nickname(str);

if ( wrong_alignment(caster) )
    return punish_align(caster);

  ret = spell(str, caster);
  if (stringp(ret))
  {
	 notify_fail(ret);
    return 0;
  }
  tell_object(caster,"You summon the healing powers of Good.\n");
  tell_room(environment(caster),caster->query_cap_name()+" chants a few "
	"quiet words.\n",
	caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect("paladinheal"))
    return "Thou art already in the process of healing someone, milord.\n";
  if ((int)caster->query_property(HEAL_LOCKOUT))
    return "Thou hast already used thy healing powers 'til the morrow.\n";

  ob = find_match(str, environment(caster));
  if (!sizeof(ob) || !living(ob=ob[0]) )
    return "The potency of thy healing powers is best realized with a "
      "still-living, wounded target, milord.\n";

  caster->add_spell_effect(3, "paladinheal", SP_NAME,
    this_object(), "hb_spell", ({ ob }));
  return 1;
}

int hb_spell(object caster, mixed *params, int time)
{
  int amount;

  switch( time )
  {
    case 3:
      tell_object(caster, "Thy hands glow with the purifying glow of healing.\n");
      tell_room(environment(caster), caster->query_cap_name()+"'s hands begin "
        "to glow with a soft yellow light.\n", caster);
      return 1;
    case 2:
      if ( !params[0] || environment(caster) != environment(params[0]) )
        return 1;
      if ( caster == params[0] )
      {
        tell_object(caster, "You lay thy hands upon thy grievous wounds.\n");
        tell_room(environment(caster), caster->query_cap_name()+
          " touches "+caster->query_possessive()+" hands to "+
          caster->query_possessive()+" wounds.\n", caster);
        return 1;
      }
      tell_object(caster, "You lay thy hands upon "+params[0]->query_cap_name()+
        ", channeling thy healing energy into "+params[0]->query_objective()+
        ".\n", caster);
      tell_object(params[0], caster->query_cap_name()+" lays "+
        caster->query_possessive()+" hands on your grievous wounds.\n");
      tell_room(environment(caster), caster->query_cap_name()+" lays "+
        caster->query_possessive()+" glowing hands on "+
        params[0]->query_cap_name()+".\n", 
        ({ caster, params[0] }) );
      return 1;
    default:
      break;
  }
  if (!params[0] || environment(caster) != environment(params[0]) )
  {
    tell_object(caster, "Thy beneficiary has left!\n");
    return 0;
  }
  
  caster->add_timed_property(HEAL_LOCKOUT, 1, HEAL_LOCKOUT_TIME);
  amount = (int)caster->query_level() * 2;

  if ( params[0]->query_property("undead") )
  {
    tell_object(caster, "Thy healing power disrupts the cursed undead fiend!\n");
    tell_room(environment(caster), params[0]->query_cap_name()+" staggers "
      "back under the healing power of "+caster->query_cap_name()+".\n",
      ({ caster, params[0] }) );
    tell_object(params[0], caster->query_cap_name()+" disrupts you with the "
      "healing power of Goodness!\n");
    params[0]->adjust_hp(-amount,caster);
    params[0]->attack_by(caster);
    return amount;
  }

  amount = cleric_fix_damage(caster, params[0], amount, "healing");

  if ( amount == 0 )
  {
    tell_object(caster, "The Gods of Goodness refuse to heal such a "
      "tainted soul!\n");
    caster->remove_timed_property(HEAL_LOCKOUT);
    return 1;
  }

  if(params[0] != caster)
  {
    tell_object(caster, "You heal "+params[0]->query_cap_name()+
      "'s wounds as the glow fades from thy hands.\n");
  }

  tell_object(params[0], "The healing touch soothes your wounds.\n");
  tell_room(environment(caster), params[0]->query_cap_name()+
    "'s wounds seem to vanish at the glowing touch.\n", 
    ({ caster, params[0] }) );

  params[0]->adjust_hp(amount,caster);

  return amount;
}
