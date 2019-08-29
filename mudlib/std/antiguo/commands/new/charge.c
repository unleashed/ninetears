/*** Charge Command ***/
/*** Created by Wonderflug, June '95 ***/
/*** For Paladins and Anti-Paladins ***/

#define SP_NAME "Cargar"
#define SPELLTYPE "Paladin"
#define CHARGE_START_GP 10
#define CHARGE_WARCRY_GP 2
#define CHARGE_HIT_GP 3
#define CHARGE_WEAP_GP 5
#define CHARGE_UNARMED_GP 5
#define BASE_RECOVER 10

inherit "/std/spells/patch.c";

string help() 
{
  return
    "\n\n"
    "Nombre del comando: "+SP_NAME+"\n"
    "Coste en Pg: 18 o mas\n"
    "Sintaxis: cargar <objetivo>\n"
    "Descripcion: \n"
    "    Esta habilidad permite a un Guerrero cargar en un combate contra "
    "un unico oponente.  Un guerrero en un carga es alguien poderoso, lleno de "
    "rabia, culminando el ataque en una serie de golpes rapidos que intentan "
    "doblegar a tu oponente.  Esto normalmente deja al guerrero sin "
    "poder realizar otra carga durante un poco de tiempo.\n\n";
}

mixed spell(string str, object caster);
object get_one_weapon(object me);
void end_charge(object me);

int charge(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  if(cast) caster = cast;
  else caster= this_player();

  if(interactive(caster))
    str = (string)caster->expand_nickname(str);

  if ( wrong_alignment(caster))
    return punish_align(caster);

  ret = spell(str, caster);
  if (stringp(ret) || !objectp(ret) )
  {
    notify_fail(ret);
    return 0;
  }

  tell_object(caster,"Insultas repetidas veces a tu cobarde oponente "+
    ret->query_cap_name()+" para intimidarlo.\n");
  tell_room(environment(caster),caster->query_cap_name()+" insulta "
    "repetidas veces a su oponente "+ret->query_cap_name()+" para intimidarlo.\n", ({  caster, ret }) );
  tell_object(ret, caster->query_cap_name()+" te insulta repetidas "
    "veces a ti y a tu familia.\n");

  ret->attack_by(caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  object weap;
  int damage_bonus;
  int recover_time;
  int total_time;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Deberia pensarselo antes, solo los Dioses podrian "
      "intentar ahora otra carga sin sufrir danyos.\n";
  
  ob = find_one_match(str, environment(caster));
  if ( !ob || ob->query_dead() )
    return "Perdona, pero quiza deberia intentar esto con algo real "
      "seria un proposito mas alto para un Caballero como usted.\n";

  if ( ob == caster )
    return "Milord!  Suicidarse no entra en tus planes por el momento!\n";
 
  if ((int)caster->query_gp() < CHARGE_START_GP )
    return "Sus huesos vociferan con cansancio menos de lo que usted pensaba "
      "antes de ejecutar su poderosa carga.\n";
  else caster->adjust_gp(-CHARGE_START_GP);

  damage_bonus = (int) caster->query_level() /3 +2;
  recover_time = BASE_RECOVER - (int)caster->query_level()/2;
  recover_time = ( recover_time < 1 ? 1 : recover_time );
  total_time = recover_time + 5;

  caster->add_spell_effect(total_time, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ total_time,ob,damage_bonus,environment(caster) }));

  return ob;
}

int hb_spell(object me, mixed *params, int time)
{
  int i;
  int damage;
  int total_time = params[0];
  int damage_bonus = params[2];
  object him = params[1];
  object weap;
  object where = params[3];

  if ( me->query_property("noguild") || !him)
  {
    tell_object(me, "No parece que usted pueda continuar con su carga ahora.\n");
    call_out("end_charge", 0, me);
    return 1;
  }
  
  switch( total_time - time )
  {
    case 0:
	if( him->query_dead() )
	{
	tell_object(me, "Su objetivo ha perecido bajo su espada.\n");
		call_out("end_charge",0,me);
		return 1;
	}
   if(environment(me) != where)
   {
		tell_object(me,"Regrese al campo de batalla como el cobarde que vos es !.\n");
	   me->add_static_property("noguild",1);	
	   call_out("end_charge",0,me);
		return 1;
   }
      if ( !him || environment(me) != environment(him) )
      {
        tell_object(me, "Su cobarde oponente ha huido !!  Su carga "
         "continuara con su "
         "triste batalla!\n");
        tell_object(him, me->query_cap_name()+" continuas siendo "
         "lanzado y cargado!\n");
      }
      if ( (int)me->query_gp() < CHARGE_WARCRY_GP ) 
      { 
        tell_object(me, "Su desarrollo apresurado ha hecho que se lanzara cansado "
          "para continuar su carga.\n");
        tell_room(environment(me), me->query_cap_name()+" intenta "
          "gritar algo sin ningun sentido en esta batalla.\n", me);
        call_out("end_charge",0,me); 
        return 1;
      }  
      else me->adjust_gp(-CHARGE_WARCRY_GP);

      tell_object(him, me->query_cap_name()+" vocifera algo insultandote "
        "para empezar a cargar sobre ti!\n");
      tell_object(me, "Vociferas gritos de guerra para empezar "
        "con tu carga.\n");
      tell_room(environment(me),  me->query_cap_name()+" vocifera "
        " insultando a toda la familia de "+
        him->query_cap_name()+" para empezar su carga.\n", ({ me, him }) );
      return 1;

    case 1:
	if(!him)
	{
	  tell_object(me, "Su objetivo a perecido bajo la fuerza de su espada.\n");
	call_out("end_charge",0,me);
	return 1;
	}
	if ( environment(me) != environment(him) )
      {  
        tell_object(me, "Su oponente esta intentando escapar, pero te "
          "abalanzas sobre el con un golpe de rabia!\n");
        tell_object(him, me->query_cap_name()+" viene chillando hacia "
          "ti!\n");
      }  

      if ( (int)me->query_gp() < CHARGE_HIT_GP ) 
      { 
        tell_object(me, "Su desarrollo apresurado ha hecho que se lanzara cansado "
          "para continuar su carga.\n");
        tell_object(him, me->query_cap_name()+" intenta gritar algo "
          "sin ningun sentido en esta batalla.\n");
        tell_room(environment(me), me->query_cap_name()+" carga sobre "+
          him->query_cap_name()+" pero no esta muy convencido y se para.\n",
          ({ me, him }) );
        call_out("end_charge",0,me); 
        return 1;
      }  
      else me->adjust_gp(-CHARGE_WARCRY_GP);

      if ( random(200) < -(random(12*damage_bonus)) +
           (int)me->query_thac0() + (int)him->query_body_ac() )
      {
        tell_object(me, "Su vil y malvado oponente hace un movimiento extranyo "
          "y usted falla su carga!\n");
        tell_object(him, "Te percatas de la carga de "+me->query_cap_name()+
          " y la esquivas sin problemas.\n");
        tell_room(environment(me), me->query_cap_name()+" carga contra "+
          him->query_cap_name()+" pero falla ridiculamente.\n", ({ me, him }) );
        call_out("end_charge",0,me);
        return 1;
      }
      tell_object(me, "Te estampas contra "+him->query_cap_name()+" con un "
        "magnifico crujir de huesos de tu armadura!\n");
      tell_object(him, me->query_cap_name()+" se estampa contra tu "
        "armadura haciendo crujir tus huesos!\n");
      tell_room(environment(me), me->query_cap_name()+" se estampa contra "+
        him->query_cap_name()+" con un magnifico crujir de huesos en su "
        "armadura!\n", ({ me, him }) );
      damage = 0;
      damage = random((int)me->query_level()) + damage_bonus;
      him->adjust_hp(-damage,me);
      return 1;

    case 2:
	if(!him)
	{
	tell_object(me, "Su objetivo ha perecido bajo su espada!\n");
	call_out("end_charge",0,me);
	return 1;
	}
	if(environment(me) != environment(him))
      {  
        tell_object(me, "Su cobarde oponente teme por "
         "su vida!  y escapa como un traidor!\n");
        tell_object(him, me->query_cap_name()+" ves tu vida "
         "en peligro y huyes como un traidor del campo de batalla!\n");
      }  
      weap = get_one_weapon(me);
      if (!weap) return 0;
      if ( (int)me->query_gp() < CHARGE_WEAP_GP )  
      {  
        tell_object(me, "Usted esta demasiado cansado para insultar a su oponente "
          "debidamente con un arma.\n");
        tell_object(him, me->query_cap_name()+" baja su "
          "su arma pausadamente, golpeandose en "
          "la cabeza.\n");
        tell_room(environment(me), me->query_cap_name()+" mira cansado a "+
          him->query_cap_name()+" y baja su "
          "arma pausadamente.\n",
          ({ me, him }) );   
      /* don't end_charge, just let the next ones fail out too */
        return 1;
      }   
      else me->adjust_gp(-CHARGE_WEAP_GP);

      if ( random(200) < -random(10*damage_bonus) +
	(int)me->query_thac0() + (int)him->query_body_ac() )
      {
        tell_object(me, "Llevas su arma bajo la herida de "+  
          him->query_cap_name()+" pero fallas.\n");
        tell_object(him, "Esquivas el brazo de "+me->query_cap_name()+" que "
          "intentaba urgar tu herida.\n");
        tell_room(environment(me), me->query_cap_name()+" esquiva "
          "el filo de la espada de "+him->query_cap_name()+".\n",
          ({ me, him }) );
        call_out("end_charge",0,me);
        return 1;
      }

      tell_object(me, "Llevas tu espada bajo sus heridas consiguiendo abrir a "+
        him->query_cap_name()+" una seria brecha!\n");
      tell_object(him, me->query_cap_name()+" hace crujir "
        "el filo de su arma bajo tus heridas !\n");
      tell_room(environment(me), me->query_cap_name()+" clava su "
        "arma entre los huesos de "+him->query_cap_name()+"!\n", ({ him, me }) );
      damage = 0;
      damage = weap->query_damage_roll();
      damage *= ((int)me->query_level()/10 + 1);
      damage += damage_bonus;
      him->adjust_hp(-damage,me);
      return 1;

    case 3:
      if ( !him || environment(me) != environment(him) )
      {  
        tell_object(me, "Su cobarde oponente teme por su vida y huye!\n"); 
        return 1; 
      }  
      if ( (int)me->query_gp() < CHARGE_UNARMED_GP )  
      {  
        return 0;
      }   
      else me->adjust_gp(-CHARGE_UNARMED_GP);

      tell_object(me, "Vociferas levantando tu punyo para "
        "volver a la carga.\n");
      tell_object(him, me->query_cap_name()+" te hace un guinyo "
        "y finaliza su carga.\n");
      tell_room(environment(me), me->query_cap_name()+" le hace un guinyo "+
        him->query_cap_name()+" y acaba su carga "
        "apartandose.\n", ({ me, him }) );
      for (i=0;i<(int)me->query_level()/10+1;i++)
        me->unarmed_attack(him, me);
      return 1;

    default:
      return 0;
  }
 
  return 1;

}

void end_charge(object me)
{
  me->remove_spell_effect(SP_NAME);
}

object get_one_weapon(object me)
{
  object* ob = me->query_held_ob();
  if (ob[0]) 
    return ob[0];
  else if (ob[1]) 
    return ob[1];
  else return 0;
}
