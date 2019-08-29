/*** Drain Ability ***/
/*** By Wonderflug ***/
/*** For Anti-Paladins, Dark kuhniggets whatever you wanna call them ***/

#define SP_NAME "Drenar"
#define SPELLTYPE "anti-paladin drain"
#define DRAIN_LOCKOUT "drain_done"
#define DRAIN_LOCKOUT_TIME 35

inherit "/d/gremios/hechizos/bases/patch.c";

string help() 
{
  return
    "\n\n"
    "Nombre del Comando: "+SP_NAME+"\n"
    "Sintaxis: drenar <objetivo>\n"
    "Descripcion: \n"
    "     This ability lets an infernal knight draw from the power of "
    "of the Oaths to Evil that he has sworn, to draw the life force of "
    "an opponent into himself.  A maximum of 2hp per level of the Knight "
    "of Darkness can be drained.  Since the control over the Negative "
    "Material Plane granted by this ability is tenuous at best, not all of the "
    "life force drained shall go to the Anti-Paladin;  indeed the Lord "
    "of Death, Cyric himself, demands half in payment.  This ability will "
    "heal a creature of undeath, but beware, for then the Knight himself "
    "shall have to make Cyric's dread payment.\n\n";  
}


mixed spell(string str, object caster);

int drain(string str,object cast)
{
  mixed ret;
  object caster;
	
  caster = cast ? cast : this_player();
  if(interactive(caster))
    str = (string)caster->expand_nickname(str);

  /*if ( wrong_alignment(caster) )
    return punish_align(caster);*/

  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }

  tell_object(caster,"Cantas en un retorcido lenguaje oscuro "
    "y una gloriosa sensacion de maldad llena el ambiente de perversion.\n");
  tell_room(environment(caster),caster->query_cap_name()+" canta un "
    "retorcido rito, llenando el ambiente de maldad y perversion.\n", caster);

  return 1;
}


mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Usted ya esta ocupado drenando una fuerza vital, y seria "
      "de suicidas intentar abrir dos conductos al plano Material "
      " Negativo!\n";

  if ((int)caster->query_property(DRAIN_LOCKOUT))
    return "Usted ya ha drenado fuerza vital recientemente, Milord, "
      "no seria sabio intentarlo otra vez tan pronto.\n";

  ob = find_one_match(str, environment(caster));

  if (!ob || !living(ob) || ob->query_dead() )
    return "Seria sabio encontrar un objetivo vivo en las inmediaciones "
     "y abrir su canal al Plano Material Negativo, Milord.\n";

  if ( ob==caster )
    return "Drenar su propia vida no seria digno!\n";

  caster->add_spell_effect(2, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob }));
  return 1;
}


int hb_spell(object caster, mixed *params, int time)
{
  int damage, drained;
  int eff_damage;
 
  if (!params[0] || environment(params[0]) != environment(caster))
  {
    tell_object(caster, "Su cobarde objetivo ha huido de su malefico poder!\n");
    return 0;
  }
  if ( time == 2)
  {
    tell_object(caster, "El area se tinye de oscuridad absoluta, y "
      "sus manos son cubiertas en neblinas de maldad.\n");
    tell_room(environment(caster), "El area se tinye de oscuridad absoluta "
      "cuando las manos de "+caster->query_cap_name()+" son cubiertas "
      "en neblinas de maldad.\n", caster);
    return 0;
  }
  
  if(params[0]->query_dead())
  {
    tell_object(caster, "Su objetivo ha expirado!\n");
    return 0;
  }

  caster->add_timed_property(DRAIN_LOCKOUT, 1, DRAIN_LOCKOUT_TIME);

  damage = (int)caster->query_level() * 2;
  damage = cleric_fix_damage(caster,params[0],damage,"magical");
  if ( params[0]->query_property("undead") )
  {
    params[0]->adjust_hp(random(damage/2));
    caster->adjust_hp(-damage, caster);
    tell_object(caster, "The creature of undeath looks refreshed as you "
      "touch it with thy shrouded hands!\n\nCyric rips out a part of thy "
      "lifeforce in payment!\n");
    tell_object(params[0], "You fell refreshed as "+
      caster->query_cap_name()+" touches you with hands shrouded "
      "in darkness!\n\n"+caster->query_cap_name()+" is suddenly "
      "wracked with pain.\n");
    tell_room(environment(caster), caster->query_cap_name()+" touches "+
      caster->query_possessive()+" hands to "+params[0]->query_cap_name()+
      ", who looks refreshed.\n\n"+caster->query_cap_name()+" is wracked "
      "with pain and looks weaker.\n", ({ caster, params[0] }) );
    return 0;
  }

          
  /* We only give the amount based on what was actually drained, not
   * what COULD have been drained.  So have to check hp before and after
   */
  tell_object(caster, "Llevas tus manos sobre "+
    params[0]->query_cap_name()+", drenando "+params[0]->query_possessive()+
    " fuerza vital hacia ti.\n\n"+params[0]->query_cap_name()+" se retuerce "
    "y grita doloridamente cuando Jade le despoja de parte de su vida.\n");
  tell_object(params[0], caster->query_cap_name()+" acerca sus oscuras "
    "manos a ti, y comienza a sentirse refrescado.\n\n"
    "Te retuerces y gritas de dolor, sintiendo tu fuerza vital arrancada "
    "por una fuerza invisible!\n");
  tell_room(environment(caster), caster->query_cap_name()+" acerca sus "
    "oscuras manos a "+params[0]->query_cap_name()+".\n\n"+
    params[0]->query_cap_name()+" grita y se retuerce de dolor al tiempo que "+
    caster->query_cap_name()+" parece refrescado.\n", 
    ({ caster, params[0] }) );



  eff_damage = (int)params[0]->query_hp(); 
  params[0]->adjust_hp(-damage,caster);
  eff_damage -= (int)params[0]->query_hp();
  eff_damage = eff_damage < 0 ? 0 : eff_damage;

  caster->adjust_hp(random(eff_damage/2)+(eff_damage/2),caster);
  params[0]->attack_by(caster);

  return eff_damage;

}
