// Drenaje de GP
// Mas o menos por Nodens
// Comando para Bardos

#define SP_NAME "Drenaje"
#define SPELLTYPE "drenaje_de_gp"
#define DRAIN_LOCKOUT "drenaje_bardos"
#define DRAIN_LOCKOUT_TIME 600

inherit "/std/spells/patch.c";

string help() 
{
  return
    "\n\n"
    "Comando: "+SP_NAME+"\n"
    "Sintaxis: drenar <objetivo>\n"
    "Coste: 5 PG\n"
    "Descripcion: \n"
    "     Esta extranya habilidad aprendida de los druidas Drow permite "
    "absorver parte del poder de otro ser de los reinos, independientemente "
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

  tell_object(caster,"Entonas una oscura melodia:\n "
    "Cada dia puedo sentir como trago algo,\n"
    "que ellos tomaron de dentro de mi.\n"
    "Yo no entiendo tu macabra forma de vida... \n"
    "cada dia me siento hueco por dentro,\n"
    "me he estado golpeando, nunca lo vas a entender...\n"
    "asi que baila conmigo.\n"
    "Baila conmigo, CONMIGO.\n");
  tell_room(environment(caster),caster->query_cap_name()+" entona una triste melodia:\n"
    "Cada dia puedo sentir como trago algo,\n"
    "que ellos tomaron de dentro de mi.\n"
    "Yo no entiendo tu macabra forma de vida... \n"
    "cada dia me siento hueco por dentro,\n"
    "me he estado golpeando, nunca lo vas a entender...\n"
    "asi que baila conmigo.\n"
    "Baila conmigo, CONMIGO.\n", caster);
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
      "deberas descansar un poco para intentar drenar otra vez.\n";

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
    tell_object(caster, "Colocas tus manos en el cuerpo de "+params[0]->query_cap_name()+" "
      "sonries maliciosamente y repites la tonadilla convirtiendo "
      "tu melodica voz en un alarido de histeria.\n");
    tell_room(ENV(caster), caster->query_cap_name()+" coloca sus manos en el pecho "
      "de "+params[0]->query_cap_name()+ " y repite la cancion mientras entra en un estado de "
      "histeria...\n", ({ caster, params[0] }));
    tell_object(params[0], "Antes de que te de tiempo a reaccionar "+caster->query_cap_name()+" "
      "esta ante ti, con sus manos en tu pecho. Sientes un escalofrio al ver una sonrisa de "
      "perversidad desdibujarse en su rostro y la locura te envuelve al sentir su grito de histeria.\n");
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
tell_object(caster, "Notas el poder de "+params[0]->query_cap_name()+" fluir a traves de tus manos "
    " hacia tu cuerpo.\n"+params[0]->query_cap_name()+" empieza a "
    "debilitarse por momentos mientras tu continuas la extraccion.\n"
    "Al cabo de unos instantes te separas de "+params[0]->query_cap_name()+" "
    "dejando un cuerpo extasiado tras de ti.\n");
  tell_object(params[0], "Empiezas a marearte y a sentirte debil "
    "mientras la sonrisa de "+caster->query_cap_name()+" se hace mas brillante "
    "sabes ques algo de ti te esta abandonando... aunque no notas tu cuerpo sangrar.\n"
    "Tu vista se nubla y pierdes la nocion del espacio por unos instantes.\n");
  tell_room(ENV(caster), caster->query_cap_name()+" empieza a sonreir "
    "mientras sus gritos de histeria parecen saciarse poco a poco.\n"
    ""+params[0]->query_cap_name()+" se balancea visiblemente y no parece estar en muy buen estado.\n"
    ""+caster->query_cap_name()+" se separa lentamente de su victima.\n",({ caster, params[0] }) );
   
   drenada = (int)caster->query_level() * 2 - random(5);
   a_drenar = (int)params[0]->query_gp(); 
   drenada = drenada >= a_drenar ? a_drenar : drenada;
   params[0]->adjust_gp(-drenada);
   caster->adjust_gp(drenada);
   return drenada;
}  
else {
  tell_object(caster,"Notas como "+params[0]->query_cap_name()+" "
  "consigue resistir tu cancion maldita y oponerse asi a tu ataque. "
  "Te separas rapidamente de "+params[0]->query_cap_name()+" mientras una "
  "sensacion de panico se apodera de ti.\n");
  tell_object(params[0],"No notas nada especial... parece que todo sigue en su sitio "
  "excepto la mirada de "+caster->query_cap_name()+" que parece mirarte con unos ojos carentes "
  "de vida, "+caster->query_cap_name()+" se separa poco a poco de ti, es un buen momento para "
  "atacarle.\n");
tell_room(ENV(caster),caster->query_cap_name()+" se separa lentamente de "+params[0]->query_cap_name()+" "
  "mientras este aprovecha para devolver el ataque.\n",({ caster, params[0] }) );
caster->attack_by(params[0]);
return 0;
}
}
