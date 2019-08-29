/*** Focus ***/
/*** Fighter ability ***/
/*** By Wonderflug ***/

/* Unfortunately we have to use call_out's since we can't remove a 
 * spell effect in the middle of doing them.
 */

inherit "/std/spells/patch.c";

#define SKILL_NAME "Focus"
#define GP_COST 1

string help() 
{
  return
    "\n\n"
    "Nombre del comando: Enfocar.\n"
    "Coste en Pg: "+GP_COST+" Pg por turno\n"
    "Sintaxis: enfocar <objetivo>, enfocar off\n"
    "Descripcion: \n"
    "     Esta habilidad te permite enfocar tus golpes en "
    "un unico objetivo.  Si alguien esta protegiendo al objetivo, "
    "intentaras enfocarle, Seras forzado a enfocarlo atraves "
    "del primer objetivo.  Usa 'enfocar off' para parar de concentrarte "
    "en el.  Despues de 1 turno por nivel, perderas tu concentracion "
    "y tendras que reenfocar a tu oponente.\n";
    
}

mixed spell(string str, object me);

int focus(string str,object doer)
{
  int skill;
  mixed ret;
  object me;

  me = doer ? doer : this_player();

  str = (string)me->expand_nickname(str);

  ret = spell(str, me);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  if (!objectp(ret))
  {
    notify_fail("Fallas al enfocar por alguna razon.\n");
    return 0;
  }
  tell_object(me,"Comienzas a enfocar tu ataque en "+str+".\n");
  tell_room(environment(me),me->query_cap_name()+" se concentra enfocando sus "
    "golpes en "+ret->query_cap_name()+".\n", me);
  return 1;
}

mixed spell(string str, object me)
{
  mixed ob;

  /* A future spell/command will use concentrate */
  if ((int)me->query_spell_effect("concentrate") ||
      me->query_property("flipped") )
    return "Estas demasiado enrabiado para enfocar algo.\n";

  if ( str == "off" )
  {
    me->remove_spell_effect("focus");
    return "Paras de enfocar a tu objetivo.\n";
  }
  
  ob = find_one_match(str, environment(me));
  if (!ob || !living(ob) ||
      member_array(ob, me->query_attacker_list()) == -1 )
    return "No estas luchando con esto.\n";

  /* override any current focus */
  if ((int)me->query_spell_effect("focus"))
    me->remove_spell_effect("focus");

  me->add_spell_effect((int)me->query_level(), 
    "focus", "focus", this_object(), "focus_func", ({ ob }));

  return ob;
}

int focus_func(object me, mixed *params, int time)
{
  if ( !params[0] || environment(params[0]) != environment(me) )
  {
    tell_object(me, "Tu objetivo ha evitado tu agresion.\n");
    call_out("end_focus", 0, me);
    return 0;
  }

  if ( me->adjust_gp(-GP_COST) < 0 )
  {
    tell_object(me, "Estas demasiado cansado para concentrarte.\n");
    call_out("end_focus", 0, me);
    return 0;
  }

  me->set_concentrate(params[0]);
  if ( time == 1 )
    tell_object(me, "Pierdes tu concentracion.\n");

  return 0;
}

void end_focus(object me)
{
  me->remove_spell_effect("focus");
}
