/*** Bash Command ***/
/*** Created by Taniwha, June '96 ***/
/*** For Battleragers ***/

/* This looks a lot like a spell underneath, hmm, probably because
 * I hacked a spell apart to make it. :) (c) Flug
 * Me too (c) Taniwha
 */
 /*Edited by Tek, 11-16-96
  * To take out all Duergar Referances and make it all Battle RAger
  */

// arreglar bug q al seguir sigue entrando el bash

#define SP_NAME "Cabezazo"
#define SPELLTYPE "Rager"
#define GP_COST 8
#define BASE_RECOVER 10
#define PW_STUN_SHADOW "/d/gremios/comandos/shadows/stun.c"

inherit "/std/spells/bases/patch.c";

object yotabaaki;

string * saveraces = ({ "Enano","Duergar","Goblin","Halfling","Medio-Elfo" });
string * bonusraces = ({ "Orco","Hombre-Lagarto","Dragon","Gigante","Troll" });
string * bonus_items = ({ "Armadura Punzante","Yelmo Punzante",
                          "Guanteletes Punzantes" });

string help() 
{
  return
    "\n\n"
    "Nombre del Comando: "+SP_NAME+"\n"
    "Coste en Pg: "+GP_COST+"\n"
    "Sintaxis: "+SP_NAME+" <objetivo>\n"
    "Descripcion: \n"
    "    Esta habilidad permite a un enojado Battle Rager cargar contra "
    "un unico oponente, dentro de un combate.\n"
    "Si sale victorioso, el Battle Rager dara un cabezazo a la victima en "
    "la cintura, dejando al oponente severamente incapacitado durante algun "
    "tiempo. Ten en cuenta que este comando funciona mejor contra oponentes "
    "de gran tamanyo, y el hecho de ir correctamente armado (2 armas es "
    "recomendable) y protegido es aconsejable.\n\n";
    /*
    "    This ability lets an irate Battlerager charge into combat "
    "against a single opponent. "
    "If successful the Battlerager will headbutt the victim somewhere in "
    "the vicinity of the beltline, leaving the opponent "
    "severely discomforted for some time. "
    "Note that this command works best against larger opponents, "
    "and being appropriately beweaponed and armoured is advised. "
    "\n\n";
    */
}

mixed spell(string str, object caster);
object get_one_weapon(object me);
void end_charge(object me);

int bash(string str,object cast)
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
	// para evitar bashes en movimiento
	yotabaaki = ENV(caster);

  tell_object(caster,"    Te encaras al oponente, dibujando mentalmente un "
    "par de lineas entre los hombros\n    y los pies, exclamando el tradicional "
    "grito de guerra induciendo al desafio.\n");
  /*"You line up your opponent, mentally drawing a couple "
    "of lines between shoulders and toes, and yell the traditional "
    "fear inducing challenge.\n");
    */
  tell_room(environment(caster),caster->query_cap_name()+" exclama:  "
    "%^GREEN%^DEEDAH DEEDAH DEEDAH DEEDAH !%^RESET%^\n", caster );
// Alex, modificado para q la victima tb vea el DEEDAH!
  /*tell_object(ret, caster->query_cap_name()+
    " te mira con mala cara.\nHace unos gestos para instarte al combate.\n "
    "Agacha la cabeza hacia ti, y grita una frase de guerra enanil.\n");*/
  /*" draws a bead on you "
    "and hurtles head first towards your groin, yelling something "
    "traditionally dwarven.\n");
    */
    
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  object *weap;
  int bonus,i;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "De ninguna manera, aun estas conmocionado del ultimo intento.\n";
//    return "No way, you are still concussed from the last effort.\n";

  if (caster->query_property("bash_done"))
    return "Aun estas intentando recuperarte del ultimo bash.\n";
    //return "You are still recovering from your last bash.\n";

  ob = find_one_match(str, environment(caster));
  if ( !ob || ob->query_dead() )
    return "Encuentra algo vivo. No creo que te guste traspasar un espiritu.\n";
    //return "Find something alive.\n";

  if ( ob == caster )
    return "Un truco realmente dificil, solo los elfos son suficientemente "
       "flexibles para intentar eso!\n";
//    return "Tricky, really tricky, only elves are flexible or kinky "
//      "enough to try that!\n";

  if ((int)caster->query_gp() < GP_COST )
    return "Quizas tengas animos para atacarle, pero tu cuerpo no piensa "
           "lo mismo.\n";
//    return "The spirit may be willing, but the flesh has had enough for "
//      "a while.\n";
  else 
    caster->adjust_gp(-GP_COST);

  bonus = 0;
  weap = caster->query_held_ob();
  for(i = 0; i < sizeof(weap); i++)
  // Arreglao 1 bug, ya que estaba como weapon_type y no weapon_name. Ishmar
    if(weap[i] && weap[i]->query_weapon_name() == "hacha de batalla" )
      bonus ++;

  weap = caster->query_worn_ob();
  for(i = 0; i < sizeof(weap); i++)
     if(weap[i] && member_array(weap[i]->query_name(), bonus_items) > 0)
        bonus ++;

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob,bonus }));

  return ob;
}

int hb_spell(object me, mixed *params, int time)
{
  int i,mybonus,hisbonus,j,imagen=0,piel=0;
  object shad;
  int bonus = params[1];
  object him = params[0];
  object *weap;


	if (me->query_dead()) {
		tell_object(me, "La vida se te escapa al igual que el equilibrio y tu cabezazo solo sirve para esparcirte mas lejos.\n");
		return 1;
	}

	// considerar lo de dejar hacer bashes a destajo hasta que
	// en alguno se kede la victima, como estaba antes.
	// rebajado d random(10)+5 a random(8)+4 por si falla y tal
    me->add_timed_property("bash_done", 1, random(8)+ 4);

	// soluciona el bug de bashes en movimiento
	/* in movement =)
	if (ENV(me) != yotabaaki) {
		tell_object("Parece que no puedes continuar con tu bash.\n");
		return 1;
	} */

  if ( me->query_property("noguild") )
  {
    tell_object(me, "Parece ser que no puedes continuar el ataque por ahora.\n");
    // "You cannot seem to continue your bash right now.\n");
    return 1;
  }

  if ( !him || environment(me) != environment(him) )
  {
    tell_object(me, "Tu objetivo vio venir tu ataque, y huyo!\n");
    //"Your target saw you coming and legged it!\n");
    return 1;
  }

	if (him->query_dead()) {
		tell_object(me, "Tu enemigo ha caido gracias a tu poder.\n");
		return 1;
	}

  mybonus = me->query_level()+me->query_str() + bonus;
  hisbonus = him->query_level()+him->query_dex();
  if(member_array((string)him->query_race(),saveraces) >= 0 ) 
    hisbonus *= 2;
  if(member_array((string)him->query_race(),bonusraces) >= 0) 
    hisbonus /=2;

  hisbonus *= (100 - (int)him->query_total_ac() );
  mybonus *= ( 200 - (int)me->query_thac0() );

  if( random(mybonus) > random(hisbonus) )
  {
    j = bonus + random(5)+1;
	
// bueeeno, esto aki no se deberia meter, se deberia poner algo asi
// como him->can_attack_me(BASH) q dewelva 1 o 0 o algo asi. Pero
// weno, como siempre, por ahora no esta hecho asi q vamos a hacer
// q esto tb depende de las imagenes y seguramente de las piel de piedra
// seguramente tb habra q hacer lo mismo para el santuario

    if (him->query_mirror_spell())
	imagen = 1;
	/*else if (him->query_stoneskin_spell())
		piel = 1;*/

    if (!him->adjust_hp( -(random((int)me->query_str())+1), me)) {
	if (imagen) {
	tell_object(me, "Te lanzas de cabeza contra lo que parecia ser "+
	him->QCN + ", pero no es mas que una burda ilusion.\n");
	tell_object(him, me->QCN + " se lanza de cabeza contra una de tus imagenes.\n");
	tell_room(ENV(me), me->QCN + " se lanza de cabeza contra lo que parecia ser "+
	him->QCN + ", pero descubre que era una ilusion.\n", ({me, him}));
        }
	else {
	tell_object(me, "Te lanzas de cabeza contra "+ him->QCN +
	" pero no consigues hacerle rodar por el suelo.\n");
	tell_object(him, me->QCN + " se lanza de cabeza contra ti pero no consigue tirarte al suelo.\n");
	tell_room(ENV(me), me->QCN + " se lanza de cabeza contra "+
	him->QCN + " pero no consigue tirarle al suelo.\n", ({me, him}));
	}
	him->attack_by(me);
        return 1;
    }

    tell_object(me,"Con un guinyo intimidador consigues un magnifico golpe!\n"+him->query_cap_name()+
      " cae al suelo agonizando !!\n");
/*
    tell_room(environment(me), me->query_cap_name()+" headbutts "+
      him->query_cap_name()+" somewhere around the beltline and "+
      him->query_cap_name()+" falls over writhing in agony.\n",
      ({ him,me }) );
    tell_object(him, "A maddened Battlerager headbutts you "
      "just below the belt. IT HURTS!!!!!!!!!!!!!!!!!\n");
*/
    tell_room(environment(me), me->query_cap_name()+" golpea a "+
      him->query_cap_name()+" en alguna parte de la cintura y "+
      him->query_cap_name()+" cae al suelo agonizando.\n",
      ({ him,me }) );
    tell_object(him, "Un enloquecido Battle Rager te golpea justo debajo "
      "de la cintura. ESTO DUELE!!!!!!!!!!\n");

    //him->adjust_hp( -random((int)me->query_str()), me);
    him->add_timed_property("stun_on", 1, j);
    him->add_timed_property("nocast",1, j);
    him->add_timed_property("noguild",1, j);
    him->add_timed_property("passed out",
/*
      "You are still rolling round on the floor recovering from the "
      "headbutt, and can't do anything.\n",j);
*/
      "Aun estas dando vueltas por el suelo recuperandote del cabezazo,  "
      "y no puedes hacer nada.\n",j);
    shad = clone_object(PW_STUN_SHADOW);
    shad->setup_shadow(him, j);
    him->add_extra_look(shad);
  }
  else
  {
    tell_object(me, "Vaya, fallaste el cabezazo, una pena realmente.\n");
    //"Alas you miss, pity really.\n");
    tell_room(environment(me),me->query_cap_name()+
      " falla por completo el cabezazo.\n",({me,him}));
    //" totally misses his "
    //  "headbutt.\n",({me,him}) );
    tell_object(him,me->query_cap_name()+" falla por poco, pero "
      "te asusta ver lo que te pudiera haber pasado.\n");
    //" just misses you, but scares "
    //  "the hell out of you anyway.\n");
  }
  him->attack_by(me);
  return 1;
}
