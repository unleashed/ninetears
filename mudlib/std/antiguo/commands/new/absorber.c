// Drenaje de GP
// Mas o menos por Nodens
// Comando para Bardos

#define SP_NAME "Absorver poder"
#define SPELLTYPE "drenaje_de_gp"
#define DRAIN_LOCKOUT "drenaje_bardos"
#define DRAIN_LOCKOUT_TIME 500

inherit "/std/spells/patch.c";

string help() 
{
  return
    "\n\n"
    "Comando: "+SP_NAME+"\n"
    "Sintaxis: absorber <objetivo>\n"
    "Coste: 5 PG\n"
    "Descripcion: \n"
    "     Esta extranya habilidad aprendida de los druidas Drow permite "
    "absorber parte del poder de otro ser de los reinos, independientemente "
    "a si este es un ser vivo o reanimado. Para realizarse debe entonarse un "
    "leve cantico mientras se toca al oponente, si se supera la resistencia "
    "que dicho adversario opone a perder poder, se drenara una cantidad de "
    "Puntos de Gremio, que no sera mayor al doble del nivel del Bardo. "
    "Si el oponente resiste al ataque no hay penalizacion, excepto por los PG "
    "gastados en el uso de esta habilidad y que el rival te atacara, por el "
    "contrario, si drenas poder de otro ser, este se sentira debil y no atacara, "
    "aunque esto no detiene un combate ya empezado.\n\n";  
}


mixed spell(string str, object caster);

int absorber(string str,object cast)
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

  tell_object(caster,"  Agitas tu garganta para coger el bemol grave adecuado ....\n" 
                     "  Entonas una ambiciosa melodia, imitando los canticos de las aguilas \n ");
                      
  tell_room(environment(caster),"  "+caster->query_cap_name()+" agita su garganta para coger el bemol adecuado ...\n"
                                "  "+caster->query_cap_name()+" entona una melodia imitando los canticos de las aguilas.\n" , caster);

caster->adjust_gp(-5);
  return 1;
}


mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Estas concentrado para batir mentalmente "
      "a tu oponente, ahora no puedes hacerlo.\n ";

  if ((int)caster->query_property(DRAIN_LOCKOUT))
    return "Tu mente aun esta resentida de el ultimo enfrentamiento "
      "deberas descansar un poco para intentar absorber otra vez.\n";

  ob = find_one_match(str, environment(caster));

  if (!ob || !living(ob) || ob->query_dead() )
    return "No hay nadie cerca de quien poder nutrirse "
     "de poder, busca a algun ser.\n";

  if ( ob==caster )
    return "Eso es algo inutil, no?\n";

  caster->add_spell_effect(2, SPELLTYPE, SP_NAME,this_object(), "hb_spell", ({ ob }));
  return 1;
}


int hb_spell(object caster, mixed *params, int time)
{
  int drenada,prob,a_drenar;
 
  if (!params[0] || environment(params[0]) != environment(caster))
  {
    tell_object(caster, "Tu adversario ha huido antes de "
      "poder tocarlo.\n");
    return 0;
  }
  if ( time == 2)
  {
    tell_object(caster, "  Cantas:   Cada dia puedo sentir como trago algo,\n"
                        "  Cantas:   Que ellos tomaron de dentro de mi.\n");
    
    tell_room(ENV(caster), "  "+caster->query_cap_name()+" canta:   Cada dia puedo sentir como trago algo,\n"
                           "  "+caster->query_cap_name()+" canta:   Que ellos tomaron de dentro de mi.\n", ({ caster, params[0] }));
    tell_object(params[0], "  "+caster->query_cap_name()+" canta para ti:   Cada dia puedo sentir como trago algo,\n"
                           "  "+caster->query_cap_name()+" canta para ti:   Que ellos tomaron de dentro de mi.\n");
   
    return 0;
  }
  
  if(params[0]->query_dead())
  {
    tell_object(caster, "Tu objetivo ha muerto!\n");
    return 0;
  }

  caster->add_timed_property(DRAIN_LOCKOUT, 1, DRAIN_LOCKOUT_TIME);

             
  /* Calculamos la resistencia del adversario para evitar ser
   * Drenado y drenamos o no los GP
   */
  
prob = ( 50 + (( (int)caster->query_int() + (int)caster->query_level() - ( (int)params[0]->query_con() + (int)params[0]->query_level() ) ) * 5 ) ); 
if (prob <= random(100))
{
tell_object(caster, "  Cantas:   Yo no entiendo tu macabra forma de vida... \n"
                    "  Cantas:   Cada dia me siento hueco por dentro,\n");
    
  tell_object(params[0], "  "+caster->query_cap_name()+" canta para ti:   Yo no entiendo tu macabra forma de vida... \n"
                         "  "+caster->query_cap_name()+" canta para ti:   Cada dia me siento hueco por dentro,\n");
    

  tell_room(ENV(caster), "  "+caster->query_cap_name()+" canta:   Yo no entiendo tu macabra forma de vida... \n"
                         "  "+caster->query_cap_name()+" canta:   Cada dia me siento hueco por dentro,\n",({ caster, params[0] }) );
   
  drenada=call_out("acaba",2,caster,params[0],drenada,a_drenar);
   
   return drenada;
}  
else {
  
  tell_object(caster,"Tus palabras acaban sin sentido y no consigues absorber energia.\n");
  tell_object(ENV(caster),"Las palabras de "+caster->query_cap_name()+" acaban sin sentido y\n"
                          "No consigue absorber la energia de "+params[0]->query_cap_name()+" ....\n"
                           ,({ caster, params[0] }));
  tell_object(params[0],"Las palabras de "+caster->query_cap_name()+" acaban sin sentido y\n"
                        "te das cuenta que estaba intentandote absorber energia mental ...\n");
   
params[0]->attack_ob(caster);
return 0;
}
}



int acaba(object yo, object tu,int drenada, int a_drenar)
{

  tell_object(yo,"  Cantas:   Me he estado golpeando, nunca lo vas a entender...\n"
                     "  Cantas:   Asi que baila conmigo.\n"
                     "  Cantas:   Baila conmigo, CONMIGO.\n");


  tell_object(tu,"  "+yo->query_cap_name()+" canta para ti:   Me he estado golpeando, nunca lo vas a entender...\n"
                        "  "+yo->query_cap_name()+" canta para ti:   Asi que baila conmigo.\n"
                        "  "+yo->query_cap_name()+" canta para ti:   Baila conmigo, CONMIGO.\n");

  tell_room(ENV(yo),"  "+yo->query_cap_name()+" canta para ti:   Me he estado golpeando, nunca lo vas a entender...\n"
                        "  "+yo->query_cap_name()+" canta para ti:   Asi que baila conmigo.\n"
                        "  "+yo->query_cap_name()+" canta para ti:   Baila conmigo, CONMIGO.\n",({ yo, tu }) );
   drenada = (int)yo->query_level() * 2 - random(5);
   a_drenar = (int)tu->query_gp(); 
   drenada = bard_fix_damage(yo,tu,drenada,"magical"); 
   drenada = drenada >= a_drenar ? a_drenar : drenada;
   tu->adjust_gp(-drenada);
   yo->adjust_gp(drenada);
   return drenada;
}