/*** Drain Ability ***/
/*** By Wonderflug ***/
/*** For Anti-Paladins, Dark kuhniggets whatever you wanna call them ***/

#define SP_NAME "Drenar"
#define SPELLTYPE "anti-paladin drain"
#define DRAIN_LOCKOUT "drain_done"
#define DRAIN_LOCKOUT_TIME 600

inherit "/std/spells/patch.c";

string help() 
{
  return
    "\n\n"
    "Comando: "+SP_NAME+"\n"
    "Sintaxis: drenar <objetivo>\n"
    "Descripcion: \n"
    "     Esta habilidad permite a un Lord diabolico extraer el poder "
    "del juramento malefico que el ha obtenido, para drenar la vida de "
    "un oponente y transferirsela a el .  Un maximo de 2 Pv por nivel del Lord "
    "de las tinieblas puede ser drenado.  Desde el control del "
    "plano material negativo se te transferira esta habilidad, Toda "
    "la energia drenada por el Anti-Paladin sera puesta en el;  Realmente "
    "el Senyor de la muerte, Sinister, pide una cuanta a cambio. Esta habilidad "
    "cura a una criatura sin vida, pero guarda, para luego el pago "
    "que se le deberia hacer a Sinister.\n\n";  
}


mixed spell(string str, object caster);

int drain(string str,object cast)
{
  mixed ret;
  object caster;
	
  caster = cast ? cast : this_player();
  if(interactive(caster))
    str = (string)caster->expand_nickname(str);

  if ( wrong_alignment(caster) )
    return punish_align(caster);

  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }

  tell_object(caster,"Cantas en un huracanado y complejo lenguaje "
    "y la glorificante maldad invade el aire.\n");
  tell_room(environment(caster),caster->query_cap_name()+" canta en un complejo y "
    "huracanado lenguaje, sientes como el aire se pudre de maldad.\n", caster);

  return 1;
}


mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Vos esta ya ocupado drenando la vida, y seria "
      "un suicidio intentar abrir dos conductos hacia el "
      "plano material negativo!\n";

  if ((int)caster->query_property(DRAIN_LOCKOUT))
    return "Vos ya ha drenado vida recientemente, Milord, y "
      "no seria bueno intentarlo otra vez tan pronto.\n";

  ob = find_one_match(str, environment(caster));

  if (!ob || !living(ob) || ob->query_dead() )
    return "Seria mejor encontrar un objetivo con vida cercano "
     "para abrir el canal hacia el plano negativo, Milord.\n";

  if ( ob==caster )
    return "Drenarse a si mismo no es su proposito!\n";

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
    tell_object(caster, "Su cobarde oponente ha huido despavorido "
      "de vos!\n");
    return 0;
  }
  if ( time == 2)
  {
    tell_object(caster, "La zona es invadida por una luz tremula de osucridad, y "
      "tus manos son amortajadas en una neblina de maldad.\n");
    tell_room(environment(caster), "La zona es invadida por una luz tremula de "
      "osuridad y las manos de "+caster->query_cap_name()+"\nse cubren de una neblina "
      "oscura.\n", caster);
    return 0;
  }
  
  if(params[0]->query_dead())
  {
    tell_object(caster, "Su objetivo ha fallecido!\n");
    return 0;
  }

  caster->add_timed_property(DRAIN_LOCKOUT, 1, DRAIN_LOCKOUT_TIME);

  damage = (int)caster->query_level() * 2;
  damage = cleric_fix_damage(caster,params[0],damage,"magical");
  if ( params[0]->query_property("undead") )
  {
    params[0]->adjust_hp(random(damage/2));
    caster->adjust_hp(-damage, caster);
    tell_object(caster, "La criatura sin vida parece refrescarse cuando "
      "la tocas con tus manos ennegrecidas!\n\nSinister arranca una parte de "
      "tu fuerza vital como pago de tu insolencia!\n");
    tell_object(params[0], "Te sientes refrescado cuando "+
      caster->query_cap_name()+" te toca con sus nubladas manos "
      "de oscuridad!\n\n"+caster->query_cap_name()+" de repente, "
      "se convulsiona en dolores.\n");
    tell_room(environment(caster), caster->query_cap_name()+" toca con "
      " sus manos a "+params[0]->query_cap_name()+
      ", el cual, parece mas refrescado.\n\n"+caster->query_cap_name()+" se "
      "convulsiona con fuertes dolores, parece enfermo.\n", ({ caster, params[0] }) );
    return 0;
  }

          
  /* We only give the amount based on what was actually drained, not
   * what COULD have been drained.  So have to check hp before and after
   */
  tell_object(caster, "Tocas con tus manos a "+
    params[0]->query_cap_name()+", drenando su "
    " fuerza vital en vos.\n\n"+params[0]->query_cap_name()+" grita "
    "espantado al ver como Sinister le extra su fuerza vital"
    ".\n");
  tell_object(params[0], caster->query_cap_name()+" te toca con sus "
    "nubladas y oscuras manos, y se siente mas refrescado.\n\n"
    "Tu gritas de espanto, sintiendo que tu vida es extraida "
    "de ti por algun ser superior!\n");
  tell_room(environment(caster), caster->query_cap_name()+" toca con "
    "sus oscuras y nubladas manos a "+params[0]->query_cap_name()+".\n\n"+
    params[0]->query_cap_name()+" solloza en gritos de panico al ver que "+
    caster->query_cap_name()+" se siente mas refrescado.\n", 
    ({ caster, params[0] }) );



  eff_damage = (int)params[0]->query_hp(); 
  params[0]->adjust_hp(-damage,caster);
  eff_damage -= (int)params[0]->query_hp();
  eff_damage = eff_damage < 0 ? 0 : eff_damage;

  caster->adjust_hp(random(eff_damage/2),caster);
  params[0]->attack_by(caster);

  return eff_damage;

}
