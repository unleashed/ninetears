/*** Bearhug ***/
/*** By Wonderflug ***/

inherit "/d/gremios/hechizos/patch.c";
object check_melee_protector(object, object);

#define BEARHUG_GP_ROUND 2
#define BEARHUG_LOCKOUT 20
#define BEARHUG_GRAB_GP 6

#define BEARHUG_HUGGER_SHADOW "/d/gremios/comandos/bearhug_hsh.c"
#define BEARHUG_TARGET_SHADOW "/d/gremios/comandos/bearhug_tsh.c"
#define BEARHUG_HUGGER_OBJECT "/d/gremios/comandos/bearhug_hobj.c"

string help()
{
  return "\nSintaxis:  abrazo <objetivo>\n"
    "Coste: "+BEARHUG_GRAB_GP+" Pg de principio, "+
    BEARHUG_GP_ROUND+" Pg por turno\n\n"
    "     El abrazo del oso te permite agarrar a un oponente con tus brazos y "
    "ahogarlo hasta matarlo.  Mientras se realiza el ataque, tu y "
    "tu oponente no os podeis mover y no te puede atacar, tu oponente ira sumando "
    "cada vez mas danyo.  Haras el ultimo abrazo cuando ya no te queden "
    "Pg, tu oponente se libere, o tu oponente te haga liberarlo. "
    "Un oponente con mas fuerza y mas destreza tendra ms posibilidades de "
    "soltarse.  Solo las criaturas humanoides pueden ser capturadas con "
    "abrazo del oso.\nNota: Hay muchos NPC'S que deberian ser humanos pero "
    "que por algun motivo no lo son.  Escribelo en el tablon del gremio o envia un mail "
    "y se intentara arreglar."
    "\n\n";
}

int bearhug(string str, object doer)
{
  int i;
  object *ob;
  object hugger;
  object target;
  object h_shadow, t_shadow;
  object h_obj;

  hugger = doer ? doer : this_player();

  str = hugger->expand_nickname(str);

  if (!str)
  {
    tell_object(hugger,"Sintaxis: abrazo <objetivo>\n");
    return 1;
  }
  if(interactive(hugger) && member_array(hugger->query_guild_name(),({"Guerrero","Ranger"})) == -1 )
  {
    tell_object(hugger, "Oops! realmente no sabes que estas haciendo, "
      "ya puedes olvidarlo.\n");
    hugger->remove_known_command("abrazar");
    return 1;
  }
  if ( hugger->query_property("flipped") )
  {
    tell_object(hugger, "Pierdes la paciencia y abrazas "
      "alguna cosa en un ataque de rabia.\n");
    return 1;
  }
  if ( hugger->query_property("bearhug_done") )
  {
    tell_object(hugger, "Tus brazos estan cansados de tanto abrazar.\n");
    return 1;
  }

  /* Make sure they're not holding anything */
  if ((int)hugger->query_gp() < BEARHUG_GP_ROUND )
  {
    tell_object(hugger,"No tienes la necesidad de abrazar nada "
      "en estos momentos.\n");
    return 1;
  }
  ob = (object*)hugger->query_held_ob();
  if (sizeof(ob) && ( ob[0] || ob[1] ))
  {
    tell_object(hugger,"Como vas a agarrar algo llevando armas?\n");
    return 1;
  }

  /* Find the target */
  ob = (object*)find_match(str, environment(hugger));

  if (!(sizeof(ob)))
  {
    tell_object(hugger,"Tu objetivo no esta aqui.\n");
    return 1;
  }
  target = ob[0];
  target = check_melee_protector( target, hugger );
  if (target->query_time_spell() || target->query_hold_spell() )
  {
    tell_object(hugger, "No puedes abrazar a "+target->query_cap_name()+
      " ahora.\n");
    return 1;
  }

  hugger->adjust_gp(-BEARHUG_GRAB_GP);
  hugger->add_timed_property("bearhug_done", 1, BEARHUG_LOCKOUT);

  /* Check the race of the target.  Non-humanoid = non-huggable */
  switch( (string)target->query_race() )
  {
    case "Duergar":
    case "Humano":
    case "Orco":
    case "Medio-Elfo":
    case "Medio-Orco":
    case "Elfo":
    case "Goblin":
    case "Drow":
    case "Halfling":
    case "Hombre-Lagarto":
    case "Enano":
    case "Gnomo":
      break;
    default:
      tell_object(hugger, "Intentas realizar el abrazo del oso con "+
        target->query_cap_name()+" pero no tienes exito.\n");
      tell_room(environment(hugger), hugger->query_cap_name()+
        " intenta agarrar a "+target->query_cap_name()+" pero "
        "no tiene exito.\n", ({hugger, target}));
      tell_object(target, hugger->query_cap_name()+
        " intenta hacerte el abrazo del oso pero fracasa.\n");
      target->attack_ob(hugger);
      return 1;
  }

  /* Make a hit roll.  hugger->query_thac0 vs. target->query_total_ac
   * straight and simple.  The 'straight' roll happens at ac 0, which is
   * maybe a little easy.
   */

  if ( random(200) < 
       (int)hugger->query_thac0() - (int)target->query_total_ac() )
  {
    tell_room(environment(hugger), hugger->query_cap_name()+
      " intenta agarrar a "+target->query_cap_name()+" pero pierde su concentracion.\n",
      ({ hugger, target }) );
    tell_object(hugger, "Intentas agarrar a "+target->query_cap_name()+
      " pero pierdes la concentracion.\n");
    tell_object(target, hugger->query_cap_name()+" intenta agarrarte "
      "pero te sueltas de alguna manera.\n");
    target->attack_ob(hugger);
    return 1;
  }
  /* Success */
  tell_object(hugger,"Agarras a "+target->query_cap_name()+" con un "
    "abrazo mortal.\n");
  tell_object(target,hugger->query_cap_name()+" te agarra "
    "fuertemente y sientes como la vida se te va!\n");
  tell_room(environment(hugger), hugger->query_cap_name()+" agarra a "+
    target->query_cap_name()+" en un gran abrazo mortal!\n",
    ({ hugger, target }) );

  /* Now clone the shadows and return. */
  h_obj = clone_object(BEARHUG_HUGGER_OBJECT);

  h_shadow = clone_object(BEARHUG_HUGGER_SHADOW);
  h_shadow->setup_shadow(hugger, target, h_obj);

  t_shadow = clone_object(BEARHUG_TARGET_SHADOW);
  t_shadow->setup_shadow(target, hugger, h_obj);

  h_obj->move(environment(hugger));
  h_obj->setup_item(hugger, target);
  h_obj->reset_get();
  h_obj->reset_drop();

  target->add_static_property("noguild", 1);
  target->add_static_property("nocast", 1);
  hugger->add_static_property("noguild", 1);
  hugger->add_static_property("nocast", 1);

  target->attack_by(hugger);

  return 1;
}
