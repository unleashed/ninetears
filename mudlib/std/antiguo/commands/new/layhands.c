/*** Hand of Healing ***/
/*** Paladin ability ***/
/*** By Wonderflug ***/

inherit "/std/spells/patch.c";

#define SP_NAME "Sanar"
#define HEAL_LOCKOUT "lay_hands_done"
#define HEAL_LOCKOUT_TIME 600

string help() 
{
 return
    "\n\n"
    "Comando : "+SP_NAME+"\n"
    "Sintaxis: sanar <objetivo>\n"
    "Descripcion: \n"
    "     Esta habilidad le permite a un paladin obtener el poder "
    "curativo que Fredrick el Semi-Dios de la luz le otorga para curarse,a el o a otro. "
    "La curacion sera de 2 Pv por nivel del paladin.  Esta habilidad "
    "no cuesta Pg, pero solo puede ser usado una vez al dia.\n"
    "NOTA: No puedes sanar personas diabolicas ni seres sin vida, danyaria "
    "la energia positiva de esta habilidad.\n\n";
}

mixed spell(string str, object caster);

int layhands(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  if(!str)
    { notify_fail("Sanar a quien?\n");  return 0;   }
    
  str = (string)caster->expand_nickname(str);

  if ( wrong_alignment(caster) )
    return punish_align(caster);

  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  tell_object(caster,"Vos invocais el poder curativo de la luz.\n");
  tell_room(environment(caster),caster->query_cap_name()+" canta unas "
    "pocas palbras tranquilizadoras.\n",
    caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect("paladinheal"))
    return "Vos ya esta en proceso de curacion a alguien, Milord.\n";
  if ((int)caster->query_property(HEAL_LOCKOUT))
    return "Vos ya ha usado este poder sanador, hasta manyana.\n";

  ob = find_match(str, environment(caster));
  if (!sizeof(ob) || !living(ob=ob[0]) )
    return "El poder sanador que te otorga tu Semi-Dios Fredrick  "
      "seria mejor usarlo sobre algo con vida , Milord.\n";

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
      tell_object(caster, "Vuestras manos se cubren de un aura purificante de "
        "curacion.\n");
      tell_room(environment(caster), "Las manos de "+caster->query_cap_name()+" se "
        "rodean de un aura luminosa de curacion.\n", caster);
      return 1;
    case 2:
      if ( !params[0] || environment(caster) != environment(params[0]) )
        return 1;
      if ( caster == params[0] )
      {
        tell_object(caster, "Vos extendeis vuestras manos sobre las heridas mas serias.\n");
        tell_room(environment(caster), caster->query_cap_name()+
          " toca con sus manos"
          " sus heridas mas serias.\n", caster);
        return 1;
      }
      tell_object(caster, "Vos extiendeis vuestras manos sobre "+
        params[0]->query_cap_name()+ ",canalizando vuestra energia sanadora "
        "dentro de sus heridas.\n", caster);
      tell_object(params[0], caster->query_cap_name()+" extiende "
        " sus manos sobre tus heridas mas serias.\n");
      tell_room(environment(caster), caster->query_cap_name()+" extiende "+
        " el aura de sus manos sobre "+
        params[0]->query_cap_name()+".\n", 
        ({ caster, params[0] }) );
      return 1;
    default:
      break;
  }
  if (!params[0] || environment(caster) != environment(params[0]) )
  {
    tell_object(caster, "Vuestro beneficiario se fue!\n");
    return 0;
  }
  
  caster->add_timed_property(HEAL_LOCKOUT, 1, HEAL_LOCKOUT_TIME);
  amount = (int)caster->query_level() * 2;

  if ( params[0]->query_property("undead") )
  {
    tell_object(caster, "El poder sanador se rompe al tocar "
      "a vuestro maldito amigo sin vida!\n");
    tell_room(environment(caster), params[0]->query_cap_name()+" sucumbe "
      "bajo el poder sanador de "+caster->query_cap_name()+".\n",
      ({ caster, params[0] }) );
    tell_object(params[0], caster->query_cap_name()+" te destroza con el "
      "poder sanador de la luz!\n");
    params[0]->adjust_hp(-amount,caster);
    params[0]->attack_by(caster);
    return amount;
  }

  amount = cleric_fix_damage(caster, params[0], amount, "healing");

  if ( amount == 0 )
  {
    tell_object(caster, "El Semio-Dios de la Luz rehusa sanar "
      "a un ser corrupto!\n");
    caster->remove_timed_property(HEAL_LOCKOUT);
    return 1;
  }

  if(params[0] != caster)
  {
    tell_object(caster, "Sanas las heridas de "+params[0]->query_cap_name()+
      " imponiendole tus manos luminosas.\n");
  }

  tell_object(params[0], "La vida de la luz os sana las heridas.\n");
  tell_room(environment(caster), "Las heridas de "+params[0]->query_cap_name()+
    "parecen desvanecerse junto con la luz.\n", 
    ({ caster, params[0] }) );

  params[0]->adjust_hp(amount,caster);

  return amount;
}
