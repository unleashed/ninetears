/*** MuG ***/
/*** By Wonderflug ***/

#define MUG_GP 5
#define MUG_LOCKOUT 50
#define STUN_SHADOW "/d/gremios/comandos/shadows/stun.c"

// Radix was here..
void setup_stun(int, object, object);

string help()
{
  return "\nSintaxis:  estudiar <objetivo>\n"
    "Coste en Pg: "+MUG_GP+" \n\n"
    "     Este comando te permite intentar estudiar a alguien.  Estudiar a "
    "a alguien significa reptar detras de el y golpear sobre la cabeza "
    "con una larga arma aplastante, si tienes exito le golpeas sin "
    "que te noten en unos cuantos turnos , tambien puedes robarles sin "
    "que te noten mientras ellos se recuperan .  Debes estar oculto y empunyando "
    "un arma de tipo aplastante.  hay alguna habilidad que te permite "
    "mejorar este comando."
    "\n\n";
}

int mug(string str, object doer)
{
  int i, damage;
  object *ob;
  object mugger, weap;
  object target;

  mugger = doer ? doer : this_player();

  str = mugger->expand_nickname(str);

  if (!str)
  {
    tell_object(mugger,"Sintaxis: estudiar <objetivo>\n");
    return 1;
  }

  if ((int)mugger->query_property("just mugged"))
  {
    tell_object(mugger, "Estas demasiado excitado del ultimo estudio "
      "para intentarlo otra vez.\n");
    return 1;
  }
  if ((int)mugger->query_gp() < MUG_GP )
  {
    tell_object(mugger,"No tienes suficiente energia para estudiar "
      "a alguien.\n");
    return 1;
  }
  if (sizeof(mugger->query_attacker_list()) )
  {
    tell_object(mugger,"Demasiado complicado estudiar a alguien mientras luchas.\n");
    return 1;
  }

  /* Find the target */
  ob = (object*)find_match(str, environment(mugger));

  if (!(sizeof(ob)))
  {
    tell_object(mugger,"Tu objetivo no esta aqui.\n");
    return 1;
  }
  target = ob[0];
  if ( target->query_creator() )
  {
    tell_object(mugger,"No es bueno estudiar inmortales.\n");
    return 1;
  }
  if ( member_array(mugger,target->query_attacker_list()) != -1 )
  {
    tell_object(mugger, "Complicado estudiar a alguien con el que luchas.\n");
    return 1;
  }

  /* Make sure he's holding a blunt weapon */
  ob = (object*)mugger->query_held_ob();
  if ( !ob[0] && !ob[1] )
  {
    tell_object(mugger,"Intentas estudiar a "+target->query_cap_name()+" con tus manos vacias, "
      "pero fallas en el intento.\n");
    tell_room(environment(mugger), mugger->query_cap_name()+" intenta "
      "estudiar a "+target->query_cap_name()+" con sus "
      " manos, pero falla.\n",
      ({ mugger, target }) );
    tell_object(target, mugger->query_cap_name()+" aparece de "
      "la nada saltando hacia ti, "
      "mirandote confundido.\n");
    target->attack_by(mugger);
    return 1;
  }

  for ( i=0; i<sizeof(ob); i++)
    if ( ob[i] && (int)ob[i]->query_attack_type() == 2 )
      weap = ob[i];
  if (!weap)
  {
    tell_object(mugger, "Realmente piensas que la proxima vez deberias usar "
      "un arma aplastante para esto.\n");
    tell_room(environment(mugger), mugger->query_cap_name()+
      " intenta rodear a "+target->query_cap_name()+" sobre su cabeza "
      "con un "+ob[0]->query_name()+", pero falla.\n",
      ({ mugger, target }) );
    tell_object(target, mugger->query_cap_name()+" intenta golpearte "
      "sobre la cabeza con un "+ob[0]->query_name()+". "
      "Lo esquivs sin problema.\n");
    target->attack_ob(mugger);
    return 1;
  }

  mugger->add_timed_property("just mugged",1,MUG_LOCKOUT);
  mugger->adjust_gp(-MUG_GP);

  switch( (string)target->query_race() )
  {
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
    case "Duergar":
      break;
    default:
      tell_object(mugger, "Intentas estudiar inadecuadamente a "+
        target->query_cap_name()+".\n");
      tell_room(environment(mugger), mugger->query_cap_name()+
        " intenta estudiar a "+target->query_cap_name()+" "
        "insatisfactoriamente.\n", ({mugger, target}));
      tell_object(target, mugger->query_cap_name()+
        " intenta estudiarte.\n");
      target->attack_ob(mugger);
      return 1;
  }

  /* Make a hit roll.  mugger->query_thac0 vs. target->query_total_ac - 4
   * straight and simple. 
   */

  // Giving a better chance, for now.  Wonderflug, nov '95
  if( !mugger->query_hide_shadow() ||
      (int)target->query_level() + random(8) >
      random((int)mugger->query_level()+(int)mugger->query_dex()) )
  {
    tell_room(environment(mugger), mugger->query_cap_name()+
      " intenta estudiar a "+target->query_cap_name()+" pero falla.\n",
      ({ mugger, target }) );
    tell_object(mugger, "Intentas estudiar a "+target->query_cap_name()+
      " pero fallas.\n");
    tell_object(target, mugger->query_cap_name()+" intenta estudiarte "
      "pero te apartas de su camino.\n");
    target->attack_ob(mugger);
    return 1;
  }
  tell_object(target,"Sientes un crujido por detras de tu cabeza "
    "...\n");
  tell_room(environment(target),mugger->query_cap_name()+" salta "
    "desde las sombras rodeando a "+target->query_cap_name()+" por "
    "la cabeza.\n",
    ({ mugger, target }) );
  tell_object(mugger,"Saltas sobre "+target->query_cap_name()+
    ", situandote detras y asestandole un maginifico golpe .\n");
  tell_room(environment(target),target->query_cap_name()+" retrocede "
    "desconcertado.\n", target);

  damage = (int)weap->query_damage_roll();
  damage += mugger->query_damage_bonus();
  damage *= 2;
  
  // Made this a function - Radix
  setup_stun(damage, mugger, target);

  target->adjust_hp(-damage*3/2,mugger);
  mugger->dest_hide_shadow();
  return 1;
}

void setup_stun(int damage, object mugger, object target)
{
  object shad;
  target->add_timed_property("passed out",1,damage/3);
  target->add_timed_property("steal at will",1,damage/2);
  target->add_timed_property("stun_on",1,damage/3);
  if ( !interactive(target) )
    call_out("wake_up", damage, target, mugger);

  shad = clone_object(STUN_SHADOW);
  shad->setup_shadow(target);
}

void wake_up(object who, object me)
{
  if ( who && me )
    who->attack_by(me);
}
