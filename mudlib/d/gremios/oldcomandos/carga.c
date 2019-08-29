/*** Carga para paladines y antipaladines ***/
/*** Tyrael, Oct '01 ***/
/*** Creado a partir de mi bash modificado ***/

#define SP_NAME "Carga"
#define SPELLTYPE "cargando"
#define GP_COST 8
#define BASE_RECOVER 10

inherit "/d/gremios/hechizos/bases/patch.c";
//inherit "/d/gremios/comandos/bases/comando.c";

object yotabaaki;

/*
string * saveraces = ({ "Enano","Duergar","Goblin","Halfling","Medio-Elfo" });
*/
string * bonusraces = ({ "Orco","Hombre-Lagarto","Dragon","Gigante","Troll" });
string * bonus_items = ({ "escudo templanza","escudo templario", "portador de tormentas",
                          "escudo negro" , "gran escudo del demonio", "desplazador" });

string help()
{
  return
    "\n\n"
    "Nombre del Comando: "+SP_NAME+"\n"
    "Coste en Pg: "+GP_COST+"\n"
    "Sintaxis: "+SP_NAME+" <objetivo>\n"
    "Descripcion: \n"
    "    Esta habilidad permite a Usted efectuar una carga a "
    "un unico oponente, corriendo hacia el y estampandose en su cuerpo.\n"
    "Las cargas a seres de gran tamanyo son mas eficaces.\n\n";
}

mixed spell(string str, object caster);
object get_one_weapon(object me);
void end_charge(object me);

int carga(string str,object cast)
{
  int skill;
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

  tell_object(caster,"Insultas fervorosamente a la familia de "+ret->QCN+
    " a modo de reto.\n");
  tell_room(ENV(caster), caster->QCN+" reta a "+ret->QCN+" insultando "+
	"fervorosamente a su familia.\n", ({caster, ret}) );
// Alex, modificado para q la victima tb vea el DEEDAH!
  tell_object(ret, caster->QCN+ " insulta de forma fervorosa a tu familia, "+
    "parece que te esta retando.\n");
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
    return "Milord, ya esta Usted cargando hacia su cobarde oponente.\n";
  if (caster->query_property("carga_hecha"))
    return "Gran Senyor, tan solo los mas poderosos dioses podrian hacer una segunda carga en tan poco tiempo.\n";

  ob = find_one_match(str, environment(caster));
  if ( !ob || ob->query_dead() )
    return "Milord, cargue hacia un objetivo digno de su categoria.\n";

  if ( ob == caster )
    return "Todavia no entra en sus planes el suicidio, Milord.\n";

  /*if (caster->query_guild_ob() == ob->query_guild_ob() &&
	member_array(ob, caster->query_attacker_list()) == -1)
	return "Seria una deshonra atacar a un companyero de la
causa!\n";*/

  if ((int)caster->query_gp() < GP_COST )
    return "Su cansado cuerpo no responde a sus deseos, Milord.\n";
  else 
    caster->adjust_gp(-GP_COST);

  bonus = 0;
  weap = caster->query_held_ob();
	/* ARREGLAR ESTO PARA LLEVAR TIPO DE ARMA ESKUDO, Y SUMAR A BONUS
  for(i = 0; i < sizeof(weap); i++)
    if(weap[i] && weap[i]->query_weapon_name() == "hacha de batalla" )
      bonus ++;
	*/
	// ARREGLAR ESTO OTRO PA KE A NADIE SE LE OCURRA CARGAR CON 2 ESCs
  //weap = caster->query_worn_ob();
  weap = caster->query_held_ob();
  for(i = 0; i < sizeof(weap); i++)
     if(weap[i] && member_array(weap[i]->query_name(), bonus_items) != -1)
        bonus++;

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob,bonus }));

  //comando_instant(SPELLTYPE, caster, ({ob}));

  return ob;
}

int hb_spell(object me, mixed *params, int time)
{
  int i,mybonus,hisbonus,j,imagen=0,piel=0;
  int bonus = params[1];
  object him = params[0];
  object *weap;

	// nada de meter cargas una vez muerto
	if (me->query_dead()) {
		tell_object(me, "Desfalleces y caes heroicamente en la batalla.\n");
		return 1;
	}

	// las cargas no puedes ir haciendolas por ahi como
	// las rosquillas xD
    me->add_timed_property("carga_hecha", 1, 3);

	// soluciona el bug de cargas en movimiento
	if (ENV(me) != yotabaaki) {
		tell_object(me, "Huyendo del campo de batalla?\n");
		return 1;
	}

  if ( me->query_property("noguild") )
  {
    tell_object(me, "Parece que Usted no puede continuar con su carga.\n");
    return 1;
  }

  if ( him && (environment(me) != environment(him)) )
  {
    tell_object(me, "Aun sigue vociferando gritos de guerra tras su cobarde oponente!\n");
    tell_object(ENV(me), me->QCN+" aun sigue vociferando gritos de guerra.\n");
	if (him)
 //   tell_object(him, me->QCN+" aun sigue vociferando gritos de guerra detras de ti!\n");
    return 1;
  }
	if (!him || him->query_dead()) { // !him por si muere un NPC!
		tell_object(me, "Su oponente cayo derrotado ante su poder.\n");
		return 1;
	}

	// LAS REGLAS PARA COLAR LA CARGA SE DEJAN ASI HASTA
	// KE QUIEN SE ENCARGUE DE LOS LORDS LAS CAMBIE

  mybonus = me->query_level()+me->query_str() + bonus+40;
  hisbonus = him->query_level()+him->query_dex();
  /*if(member_array((string)him->query_race(),saveraces) >= 0 ) 
    hisbonus *= 2;*/
  if(member_array((string)him->query_race(),bonusraces) >= 0) 
    hisbonus /=2;

  hisbonus *= (100 - (int)him->query_total_ac() );
  mybonus *= ( 300 - (int)me->query_thac0() );

	tell_object(me, "Vociferas gritos de guerra y comienzas tu carga.\n");
	tell_room(ENV(me), me->QCN+" vocifera gritos de guerra y comienza su carga.\n", me);
	// mmm, no se si hacer uno personalizao pal chupacargas

  if( random(mybonus) > random(hisbonus) )
  {
	int danio;
    j = bonus + random(5)+1;

	tell_room(ENV(me), me->QCN+" choca contra "+him->QCN+" con un descomunal golpe.\n", ({me, him}));
	if (bonus)
	tell_object(me, "Chocas contra "+him->QCN+" dejandole el sello de tu escudo en su cara!\n");
	else
	tell_object(me, "Chocas contra "+him->QCN+" con un descomunal golpe!\n");
	tell_object(him, me->QCN+" choca contra ti con un descomunal golpe!\n");

// bueeeno, esto aki no se deberia meter, se deberia poner algo asi
// como him->can_attack_me(CARGA) q dewelva 1 o 0 o algo asi.
// aki no hace falta manejar nada de pieles ni images pq no hay shadow

// danio basico sin contar los escudos y esa mierdecilla
	danio = me->query_level() * (4 + bonus) + me->query_con() * 3 + random(me->query_dex());
    him->adjust_hp(-danio, me);
  }
  else
  {
    tell_room(environment(me),him->QCN+
      " consigue esquivar la carga de "+me->QCN+".\n",({me,him}));
    tell_object(me, "Su malvado oponente consigue esquivar su carga.\n");
    tell_object(him, "Consigues esquivar la carga de "+me->QCN+".\n");
  }
  him->attack_by(me); //se supone que ya estan en peleas, pero iwal ha parado
  return 1;
}
