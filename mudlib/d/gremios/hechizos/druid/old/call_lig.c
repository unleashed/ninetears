/*** Call Lightning ***/
/*** By Wonderflug ***/

inherit "/std/spells/patch.c";

mixed find_unique_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);

#define SP_NAME "Call Lightning"
#define GP_COST 10
#define SPELLTYPE "offensive"
#define TYPE "electrical"
#define SIZE_OF_DICE 8
#define save_type "electrical"


 /*** help file ***/
string help() {
  return
    "\n\n"
    "Spell Name: "+SP_NAME+"\n"
    "Sphere: Druid\n"
    "Level: 5th\n"
    "Gp Cost: "+GP_COST+"\n"
    "Damage Type: "+TYPE+"\n"
    "Saving Throw: 1/2\n"
    "Description: \n"
    "    This spell brings down the wrath of nature upon your foes. "
    "Lightning will lance out from even the clearest skies to strike "
    "your enemies for 8d8 hp damage.  Of course, the damage is "
    "greatly reduced indoors.\n";

}

mixed spell(string str, object caster);

int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  if(interactive(caster))
    str = (string)caster->expand_nickname(str);

  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }

  tell_object(caster,"You begin the chant to "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins "
    "a crackly, broken chanting.\n", caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";

  ob = find_unique_match(str, environment(caster));
  if (!sizeof(ob))
    return "There is nobody of that name here.\n";

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ 1, ob }));
  return 1;
}


int hb_spell(object caster, mixed *params, int time)
{
  int i;
  int damage;
  object* bolted;

  /* Prevent caster from hitting herself */
  params[1] -= ({ caster });
  bolted = ({ });

  /* Check if everyone has run away */
  for ( i=0; i<sizeof(params[1]); i++ )
    if ( living(params[1][i]) && environment(params[1][i]) == environment(caster) )
      bolted += ({ params[1][i] });  

  if (!bolted || !sizeof(bolted) )
  {
    tell_object(caster, "There is nobody of that name here.\n");
    return 0;
  }

  /* If it's being cast, adjust gp if possible */
  if (params[0] && (int)caster->adjust_gp(-GP_COST)<0)
  {
	 tell_object(caster, "You are too tired to complete the chant.\n");
	 return 0;
  }

  if ( params[0] )
  {
    /* the effect is being cast, not 'produced' otherwise */  
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " clenches a fist heavenward, and the skies rumble in response.\n",
      ({ caster }) );

    tell_object(caster, "You clench your fist heavenward, and the skies "
      "rumble in response.\n");
  }

  tell_room( environment(caster), "A blinding bolt of lightning suddenly "
    "explodes into the room!\n");

  /* do damage and individual messages */
  for ( i=0; i<sizeof(bolted); i++)
  {
    damage = roll(8, 8);
    damage = cleric_fix_damage(caster, bolted[i], damage, save_type);
    if (!environment(caster)->query_outside()) damage = damage/(random(3)+2);
    bolted[i]->spell_damage(bolted[i], damage, TYPE, caster);
    bolted[i]->attack_by(caster);
    tell_object(bolted[i], "Pain spasms through your body as the bolt "
      "forks and blasts into you.\n");
  }

  /* let the caster know who she hit */
  tell_object(caster, "The bolt forks into "+sizeof(bolted)+" lances of "
    "electricity, blasting into\n"+query_multiple_short(bolted)+".\n");
  return GP_COST;

}

