/*** Comando Jugadasucia ***/
/*** Tyrael - Oct '01 ***/
/*** Crear shadow que no permita moverse mas q a randoms ***/
/*** de poca duracion, que no permita hacer looks, pero ***/
/*** que si permita ejecutar comandos, Y no permita tirar ***/
/*** mas hechizos que los de area! ***/

/*** AUN ESTA POR TERMINAR
 *** NECESITAMOS DIFERENCIAR AL MENOS TRES JUGADAS Y SHADOWS:
 *** - DEDO EN EL OJO - STUN TOTAL + CEGUERA
 *** - ECHAR TIERRA A LA CARA - CEGUERA
 *** - BURLARSE - MENOR THAC0 Y MENOR TOHIT
 ***/

#define SP_NAME "Jugadasucia"
#define SPELLTYPE "jugandosucio"
#define GP_COST 8
#define BASE_RECOVER 10
#define JG_CEGUERA_SHADOW "/d/gremios/comandos/shadows/ceguera.c"

inherit "/std/spells/bases/patch.c";

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
}

mixed spell(string str, object caster);

int jugadasucia(string str,object cast)
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

    caster->add_timed_property("jugada_hecha", 1, random(8)+ 4);
    ret->add_timed_property("telanjugado", 1, random(10)+ 6);

	// CALCULAR EXITO

	// FALLAMOS

	// LE DAMOS PAL PELO
    if (ret->query_mirror_spell())
	imagen = 1;
	/*else if (him->query_stoneskin_spell())
		piel = 1;*/

	// ESTO SERIA PARA DEDO EN EL OJO
    if (!ret->adjust_hp( -(random((int)caster->query_str())+1), caster)) {
	if (imagen) {
	tell_object(caster, "Intentas hacerle una jugarreta a "+
	ret->QCN + ", pero das con una burda ilusion.\n");
	tell_object(ret, caster->QCN + " hace una esplendida jugarreta a una de tus imagenes.\n");
	tell_room(ENV(caster), caster->QCN + " hace una jugarreta a "+
	ret->QCN + ", pero descubre que era una ilusion.\n", ({caster, ret}));
        }
	else { /* atencion, para el piel, en caso de ceguera por tierra ignorar piel */
	// PODRIA SER SANTUARIO TB, ARREGLAR AKI Y EN BASH
	tell_object(caster, "Intentas hacerle una jugarreta a "+
	ret->QCN + ", pero chocas contra la dureza de la roca.\n");
	tell_object(ret, caster->QCN + " te hace una esplendida jugarreta para nada.\n");
	tell_room(ENV(caster), caster->QCN + " hace una jugarreta a "+
	ret->QCN + ", pero descubre el tacto de la roca.\n", ({caster, ret}));
	}
	him->attack_by(me);
        return 1;
    }

  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  object *weap;
  int bonus,i;

/* NO ES FACTIBLE, ES COMANDO INSTANT
  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Tu cerebro aun esta intentando idear otra jugada sucia.\n";
*/

  if (caster->query_property("jugada_hecha"))
    return "Tu cerebro aun esta intentando idear otra jugada sucia.\n";

  ob = find_one_match(str, environment(caster));
  if ( !ob || ob->query_dead() )
    return "Busca algo vivo para tus propositos.\n";

  if ( ob == caster )
    return "Diriges uno de tus dedos a tu ojo, lo ves grande y peligroso y acabas por retirarlo.\n"

  if ((int)caster->query_gp() < GP_COST )
    return "Te encuentras cansado para andar con juegos.\n";
  else 
    caster->adjust_gp(-GP_COST);

  return ob;
}

// CHADOUS Y TAL

    him->add_timed_property("stun_on", 1, j);
    him->add_timed_property("nocast",1, j);
    him->add_timed_property("noguild",1, j);
    him->add_timed_property("passed out",
      "Aun estas dando vueltas por el suelo recuperandote del cabezazo,  "
      "y no puedes hacer nada.\n",j);
    shad = clone_object(JG_STUN_SHADOW);
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
