/*** Carga para paladines y antipaladines ***/
/*** Tyrael, Oct '01 ***/
/*** Creado a partir de mi bash modificado ***/

#define SP_NAME "Golpear"
#define SPELLTYPE "golpeando"
#define GP_COST 8
#define BASE_RECOVER 10

inherit "/std/spells/bases/patch.c";

object yotabaaki;

string help()
{
  return
    "\n\n"
    "Nombre del Comando: "+SP_NAME+"\n"
    "Coste en Pg: "+GP_COST+"\n"
    "Sintaxis: "+SP_NAME+" <objetivo>\n"
    "Descripcion: \n"
    "    Esta habilidad permite al Barbaro preparar su potencia"
    "bruta para descargarla con su arma sobre el cuerpo de su\n"
    "enemigo.\n\n";
}

mixed spell(string str, object caster);

int golpear(string str,object cast)
{
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  if(interactive(caster))
    str = (string)caster->expand_nickname(str);

  ret = spell(str, caster);
  if (stringp(ret) || !objectp(ret) )
  {
    tell_object(caster,ret);
    return 1;
  }
	// para evitar cargas en movimiento
	yotabaaki = ENV(caster);

  tell_object(caster,"Concentras todas tus fuerzas para realizar el movimiento de golpeo.\n");
  tell_room(ENV(caster), caster->QCN+" se dispone a golpear a un enemigo!\n",
	({caster}) );
// Alex, modificado para q la victima tb vea el DEEDAH!
	// iniciar peleas aki!
    ret->attack_by(caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  object *weap;
  int bonus,i;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Ya estas intentando descargar tu fuerza sobre tu enemigo.\n";
  if (caster->query_property("golpeo_hecho"))
    return "Aun no estas en condiciones de realizar un movimiento de este calibre.\n";

	weap = caster->query_weapons_wielded();
	if (!sizeof(weap))
		return "Que tal si lo pruebas empunyando un arma?\n";

  ob = find_one_match(str, environment(caster));
  if ( !ob || ob->query_dead() || ob->query_hidden())
    return "Intenta golpear algo que respire.\n";

/* deberia permitir que un orco se golpee a si mismo con mucho menos
   danyo? como son un poco tontines... xD */
  if ( ob == caster )
    return "No encuentras el movimiento preciso para poder golpearte.\n";

  if ((int)caster->query_gp() < GP_COST )
    return "No estas suficientemente concentrado para realizar esto.\n";
  else
    caster->adjust_gp(-GP_COST);

/*  bonus = 0;
  BUGS A MANTA - USAR query_weapons_wielded()
  weap = caster->query_held_ob();*/
	/* ARREGLAR ESTO PARA LLEVAR TIPO DE ARMA ESKUDO, Y SUMAR A BONUS
  for(i = 0; i < sizeof(weap); i++)
    if(weap[i] && weap[i]->query_weapon_name() == "hacha de batalla" )
      bonus ++;
	*/
	/* ARREGLAR ESTO OTRO PA KE A NADIE SE LE OCURRA CARGAR CON 2 ESCs
  weap = caster->query_worn_ob();
  for(i = 0; i < sizeof(weap); i++)
     if(weap[i] && member_array(weap[i]->query_name(), bonus_items) > 0)
        bonus ++;
	*/

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob,bonus }));

  return ob;
}

int hb_spell(object me, mixed *params, int time)
{
  int i,mybonus,hisbonus,j,imagen=0,piel=0;
  int bonus = params[1];
  object him = params[0];
  object *weap;

	if (me->query_dead()) {
		tell_object(me, "Al caer al suelo imaginas tu golpe destrozando a tu victima, pero la vista se te nubla.\n");
		return 1;
	}

	// los golpeos no puedes ir haciendolos por ahi como
	// las rosquillas xD
    me->add_timed_property("golpeo_hecho", 1, 4);

	// soluciona el bug de golpeos en movimiento, cosa q en pusa si pasa
	// vamos a dejar que ocurran - FEATURE ! XD
	/*
	if (ENV(me) != yotabaaki) {
		tell_object("Dejas de realizar tu movimiento.\n");
		return 1;
	}*/

  if ( me->query_property("noguild") )
  {
    tell_object(me, "Parece que no puedes continuar con tu golpeo.\n");
    return 1;
  }

  if ( !him || environment(me) != environment(him) )
  {
    tell_object(me, "Bonito movimiento, si senyor, pero... y tu victima?\n");
	if (him)
    tell_object(ENV(me), me->QCN+" completa un espectacular movimiento, pero... y su victima?\n");
    return 1;
  }

	if (him->query_dead()) {
		tell_object(me, "Tu objetivo ha muerto antes de degustar tu arma en sus entranyas.\n");
		return 1;
	}

	// LAS REGLAS PARA COLAR EL GOLPEO SE DEJAN ASI HASTA
	// KE QUIEN SE ENCARGUE DE LOS BARBAROS LAS CAMBIE

  mybonus = me->query_level()+me->query_str() + bonus + 20;
  hisbonus = him->query_level()+him->query_dex();
  /*if(member_array((string)him->query_race(),saveraces) >= 0 ) 
    hisbonus *= 2;
  if(member_array((string)him->query_race(),bonusraces) >= 0) 
    hisbonus /=2;*/

  hisbonus *= (100 - (int)him->query_total_ac() );
  mybonus *= ( 275 - (int)me->query_thac0() );

  if( random(mybonus) > random(hisbonus) )
  {
	int danio;

	tell_room(ENV(me), me->QCN+" entierra su arma en el debil cuerpo de "+him->QCN+"!\n", ({me, him}));
	tell_object(me, "Desgarras la piel de "+him->QCN+" dejandole graves y sangrientas heridas!\n");
	tell_object(him, me->QCN+" entierra su arma en tu debil cuerpo desgarrandote la piel!\n");

// bueeeno, esto aki no se deberia meter, se deberia poner algo asi
// como him->can_attack_me(GOLPEO) q dewelva 1 o 0 o algo asi.
// aki no hace falta manejar nada de pieles ni images pq no hay shadow

// danio basico sin contar las armas tipo demoniaca y esa mierdecilla
	danio = me->query_level() * 4 + me->query_str() * (random(5) + 1) + random(me->query_con());
    him->adjust_hp(-danio, me);
  }
  else
  {
    tell_room(environment(me),him->QCN+
      " consigue esquivar el movimiento de "+me->QCN+".\n",({me,him}));
    tell_object(me, "No consigues alcanzar a tu enemigo!\n");
    tell_object(him, "Consigues esquivar el movimiento de "+me->QCN+".\n");
  }
  him->attack_by(me); //se supone que ya estan en peleas, pero iwal ha parado
  return 1;
}
