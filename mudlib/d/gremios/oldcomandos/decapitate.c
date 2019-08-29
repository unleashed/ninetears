/*** Decapitate ***/
/*** For assassins, by Wonderflug ***/

#define HEAD "/d/gremios/comandos/head.c"
#define GP_COST 10

string help()
{
  return
    "Nombre del comando: Decapitar\n"
    "Coste GPs: "+GP_COST+"\n"
    "Sintaxis: decapitar <cadaver>\n"
    "Decscripcion:\n"
    "    Esta habilidad te permite arrancar la cabeza de un cadaver. "
    "Util como trofeo, no mucho mas realmente. "
    "Por supuesto, algo que aun viva se puede enfadar si lo pruebas "
    "con el.\n\n";
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
    tell_object(me,"Tu, un espiritu, esperas decapitar algo? "
      "Bonito intento.\n ");
    return 1;
  }

  if ( me->adjust_gp(-GP_COST) < 0 )
  {
    tell_object(me,"Estas demasiado cansado como para hacer salvajadas.\n");
    return 1;
  }

  noweap=1;
  weap = me->query_held_ob();
  if ( weap[0] && (int)weap[0]->query_attack_type() != 2 ) noweap=0;
  if ( weap[1] && (int)weap[1]->query_attack_type() != 2 ) noweap=0;

  if ( noweap )
  {
    tell_object(me, "Harias una autentica chapuza sin un objeto cortante "
      "a mano.\n");
    return 1;
  }

  ob = find_match(str, environment(me));
  if ( sizeof(ob) != 1 )
  {
    tell_object(me, "Hmm.. decapitar que?\n");
    return 1;
  }
 
  ob = ob[0];
 
  if(living(ob))
  {
    tell_object(me, ob->query_cap_name()+" no parece dispuesto a "
      "ser decapitado ahora mismo.\n");
    tell_object(ob, me->query_cap_name()+" se acerca a ti con una bonita "
      "arma cortante en la mano, entonces, mira\nde cerca tu cuello, "
      "parece sorprendido y se vuelve atras desilusionado.\n");
    return 1;
  }
 
  if (!ob->query_corpse())
  {
    tell_object(me, "Solo puedes decapitar cadaveres.\n");
    return 1;
  }
 
  if (ob->query_property("decapitated"))
  {
    tell_object(me, "Alguien ya ha hecho el trabajo por ti. Yo de ti "
      "no comeria\nen un tiempo en el restaurante de la zona.\n");
    return 1;
  }
 
  tell_object(me, "Arrancas la cabeza de el "+ob->short()+".\n");
  tell_room(environment(me), me->query_cap_name()+" arranca la cabeza "
    "de el "+ob->short()+".\n", me);
 
  ob->add_property("decapitated",1);
  ob->set_long(ob->query_long()+"\nParece que alguien le ha arrancado "
    "la cabeza.\n");
 
  head = clone_object(HEAD);
  head->set_head_name(ob->query_owner());
  head->add_property("owner", ob->query_owner());
  head->move(environment(me));
 
  return 1;
}
