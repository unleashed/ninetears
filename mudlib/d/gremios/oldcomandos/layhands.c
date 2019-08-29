/*** Hand of Healing ***/
/*** Paladin ability ***/
/*** By Wonderflug ***/

inherit "/d/gremios/hechizos/patch.c";

#define SP_NAME "Heal"
#define HEAL_LOCKOUT "lay_hands_done"
#define HEAL_LOCKOUT_TIME 600

string help() 
{
 return
    "\n\n"
    "Nombre del Comando: "+SP_NAME+"\n"
    "Sintaxis: sanar <persona>\n"
    "Descripcion:\n"
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
  tell_object(caster,"Invocas los poderes curativos del Bien.\n");
  tell_room(environment(caster),caster->query_cap_name()+" invoca unas "
    "pocas palabras calmadas.\n",
    caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect("paladinheal"))
    return "Usted ya se encuentra en el proceso de sanar, Milord.\n";
  if ((int)caster->query_property(HEAL_LOCKOUT))
    return "Usted ya ha usado sus poderes curativos por hoy.\n";

  ob = find_match(str, environment(caster));
  if (!sizeof(ob) || !living(ob=ob[0]) )
    return "La potencia de sus poderes curativos se aprovecha mejor con "
      "objetivo viviente y herido, Milord.\n";

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
      tell_object(caster, "Tus manos brillan con la luz purificadora de "
        "la curacion.\n");
      tell_room(environment(caster), "Las manos de "+caster->QCN
	+ " comienzan a brillar con una resplandeciente luz amarilla.\n", caster);
      return 1;
    case 2:
      if ( !params[0] || environment(caster) != environment(params[0]) )
        return 1;
      if ( caster == params[0] )
      {
        tell_object(caster, "Pones tus manos sobre tus heridas.\n");
        tell_room(environment(caster), caster->query_cap_name()+
          " pone sus manos sobre sus heridas.\n", caster);
        return 1;
      }
      tell_object(caster, "Impones tus manos sobre "+
        params[0]->query_cap_name()+ ", canalizando tu energia curativa "
        "sobre "+params[0]->query_objective()+".\n", caster);
      tell_object(params[0], caster->query_cap_name()+" pone sus "
        + "manos sobre tus heridas.\n");
      tell_room(environment(caster), caster->query_cap_name()+" pone sus "
        + " brillantes manos sobre "+
        params[0]->query_cap_name()+".\n", 
        ({ caster, params[0] }) );
      return 1;
    default:
      break;
  }
  if (!params[0] || environment(caster) != environment(params[0]) )
  {
    tell_object(caster, "Su objetivo se ha ido!\n");
    return 0;
  }
  
  caster->add_timed_property(HEAL_LOCKOUT, 1, HEAL_LOCKOUT_TIME);
  amount = (int)caster->query_level() * 2;

  if ( params[0]->query_property("undead") )
  {
    tell_object(caster, "Su poder sanador disrupts the cursed undead "
      "fiend!\n");
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
    tell_object(caster, "Curas las heridas de "+params[0]->query_cap_name()+
      " al tiempo que el brillo desaparece de tus manos.\n");
  }

  tell_object(params[0], "La imposicion de manos cura tus heridas.\n");
  tell_room(environment(caster), "Las heridas de "+ params[0]->query_cap_name()+
    " parecen desvanecerse con la imposicion de manos.\n", 
    ({ caster, params[0] }) );

  // mucho cleric_fix_damage y tal pero salen sanares de 120 pvs a lvl 58.

  // params[0]->adjust_hp(amount,caster);
	// si no hacemos adjust_hp no sale en el monitor de vida
  params[0]->set_hp(params[0]->query_max_hp());
  params[0]->adjust_hp(0,caster);

  return amount;
}
