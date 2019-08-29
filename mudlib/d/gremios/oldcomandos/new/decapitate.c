/*** Decapitate ***/
/*** For assassins, by Wonderflug ***/

#define HEAD "/d/gremios/comandos/head.c"
#define GP_COST 10

string help()
{
  return
    "Nombre de comando: Decapitar.\n"
    "Coste en Pg: "+GP_COST+"\n"
    "Sintaxis: decapitar <objeto>\n"
    "Decscripcion:\n"
    "    Esta habilidad te permite cortar la cabeza d un cuerpo "
    "que este tumbado en el suelo.  Usado en matanzas sangrientas, pero "
    "con poco uso real.  Solo sirve para demostrar la barbarie que uno lleva "
    "dentro. Por supuesto no se puede usar con seres con vida.\n\n";
}

int decapitate(string str,object x)
{
  object me;
  mixed ob;
  object* weap;
  int noweap;
  object head;

  if(x)
    me = x;
  else
    me = this_player();

  if(!str || str == "") 
    str = "cuerpo";

  if(me->query_dead())
  {
    tell_object(me,"Eres un espiritu, intentas hacer "
      "algo?.\nSinister te patea en el trasero diciendote: Buen intento !\n ");
    return 1;
  }

  if ( me->adjust_gp(-GP_COST) < 0 )
  {
    tell_object(me,"Estas demasiado cansado para cortar la cabeza a algun cuerpo.\n");
    return 1;
  }

  noweap=1;
  weap = me->query_held_ob();
  if ( weap[0] && (int)weap[0]->query_attack_type() != 2 ) noweap=0;
  if ( weap[1] && (int)weap[1]->query_attack_type() != 2 ) noweap=0;

  if ( noweap )
  {
    tell_object(me, "No puedes decapitar sin arma cortante en "
      "tus manos.\n");
    return 1;
  }

  ob = find_match(str, environment(me));
  if ( sizeof(ob) != 1 )
  {
    tell_object(me, "Umm.. decapitar que?\n");
    return 1;
  }
 
  ob = ob[0];
 
  if(living(ob))
  {
    tell_object(me, ob->query_cap_name()+" no puede ser decapitado "
      "en estos momentos.\n");
    tell_object(ob, me->query_cap_name()+" camina detras tuyo con una "
      "espada cortante en la mano.\n"+me->query_cap_name()+" te mira\nhace crujir su cuello "
      "y regresa donde estaba.\n");
    return 1;
  }
 
  if (!ob->query_corpse())
  {
    tell_object(me, "Solo puedes decapitar cuerpos.\n");
    return 1;
  }
 
  if (ob->query_property("decapitated"))
  {
    tell_object(me, "Alguien golpea tu moribunda cabeza. Algo "
      "comestible quiza?\n");
    return 1;
  }
 
  tell_object(me, "Decapitas la cabeza de "+ob->short()+".\n");
  tell_room(environment(me), me->query_cap_name()+" decapita la cabeza "
    "de "+ob->short()+".\n", me);
 
  ob->add_property("decapitated",1);
  ob->set_long(ob->query_long()+"\nParece la cabeza decapitada de algun "
    "pobre infeliz.\n");
 
  head = clone_object(HEAD);
  head->set_head_name(ob->query_owner());
  head->add_property("owner", ob->query_owner());
  head->move(environment(me));
 
  return 1;
}

