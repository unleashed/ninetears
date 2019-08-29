/*** Arrancar Cabellera ***/
/*** Para todos, por Bevilac ***/

#define CABELLERA "/w/bevilac/cabellera.c"
#define GP_COST 5

string help()
{
  return
    "Command name: Arrancar Cabellera\n"
    "GP Cost: "+GP_COST+"\n"
    "Syntax: arrancar <object>\n"
    "Decscription:\n"
    "    Esta habilidad te deja arrancarle la cabellera "
    "a los cuerpos. Su utilidad real no es muy grande , pero  "
    "sirve para tener recuerdos de victimas. Por supuesto, no "
    "puedes arrancar la cabellera a algo vivo.\n\n";
}

int arrancar(string str,object x)
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
    str = "corpse";

  if(me->query_dead())
  {
    tell_object(me,"Tu, un espiritu , estas intentando arrancarle la "
      "cabellera a algo?.\nParis te patea la cabeza y dice: "
      "Buen intento.\n ");
    return 1;
  }

  if ( me->adjust_gp(-GP_COST) < 0 )
  {
    tell_object(me,"Estas demasiado cansado como para ponerte a arrancar"
                   " una cabellera.\n");
    return 1;
  }

  noweap=1;
  weap = me->query_held_ob();
  if ( weap[0] && (int)weap[0]->query_attack_type() != 2 ) noweap=0;
  if ( weap[1] && (int)weap[1]->query_attack_type() != 2 ) noweap=0;

  if ( noweap )
  {
    tell_object(me, "No puedes hacer esto sin el arma adecuada "
      "en la mano.\n");
    return 1;
  }

  ob = find_match(str, environment(me));
  if ( sizeof(ob) != 1 )
  {
    tell_object(me, "Ehhh... Arrancar a quien?\n");
    return 1;
  }
 
  ob = ob[0];
 
  if(living(ob))
  {
    tell_object(me, ob->query_cap_name()+" no parece que quiera que "
      "le arranques la cabellera, Melon.\n");
    tell_object(ob, me->query_cap_name()+" va hacia ti con una sonrisa "
      "demoniaca\n, pero  "
      "al ver que estas vivo se da la vuelta, ofuscado.\n");
    return 1;
  }
 
  if (!ob->query_corpse())
  {
    tell_object(me, "Solo puedes arrancarle la cabellera a cuerpos.\n");
    return 1;
  }
 
  if (ob->query_property("descabellado"))
  {
    tell_object(me, "Parece que alguien se te ha adelantado. "
      ".\n");
    return 1;
  }
 
  tell_object(me, "Arrancas la cabellera del "+ob->short()+".\n");
  tell_room(environment(me), me->query_cap_name()+" arranca la cabellera "
    "del "+ob->short()+".\n", me);
 
  ob->add_property("sin_cabellera",1);
  ob->set_long(ob->query_long()+"\nEs un cuerpo, sin cabellera "
    ", chorreando %^BOLD%^RED%^Sangre%^RESET%^.\n Te preguntas que "
    "animal habra podido hacer esta salvajada .\n");
 
  head = clone_object(CABELLERA);
  head->set_cabellera_name(ob->query_owner());
  head->add_property("owner", ob->query_owner());
  head->move(environment(me));
 
  return 1;
}

