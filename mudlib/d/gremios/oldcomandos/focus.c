/*** Focus ***/
/*** Fighter ability ***/
/*** By Wonderflug ***/

/* Unfortunately we have to use call_out's since we can't remove a 
 * spell effect in the middle of doing them.
 */

inherit "/d/gremios/hechizos/patch.c";

#define SKILL_NAME "Centrar"
#define GP_COST 1

string help() 
{
  return
    "\n\n"
    "Nombre de Comando: "+SKILL_NAME+"\n"
    "Coste GPs: "+GP_COST+" GP per round\n"
    "Sintaxis: centrar <objetivo>, centrar off\n"
    "Descripcion: \n"
    "     This ability lets you attempt to concentrate your blows "
    "upon a single foe.  If something is protecting the target you "
    "attempt to focus on, it is likely that you will be forced "
    "to go through it first.  Use 'focus off' to stop concentrating "
    "upon a foe.  After 1 round per level, you will lose your "
    "concentration and have refocus on your opponent.\n";
    
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
    notify_fail("No consigues centrar tus golpes.\n");
    return 0;
  }
  tell_object(me,"Empiezas a centrar tus golpes contra "+str+".\n");
  tell_room(environment(me),me->query_cap_name()+" comienza a centrar "
    "sus golpes contra "+ret->query_cap_name()+".\n", me);
  return 1;
}

mixed spell(string str, object me)
{
  mixed ob;

  /* A future spell/command will use concentrate */
  if ((int)me->query_spell_effect("concentrate") ||
      me->query_property("flipped") )
    return "Estas demasiado enrabietado para centrar tus golpes.\n";

  if ( str == "off" )
  {
    me->remove_spell_effect("focus");
    return "Dejas de centrar tus golpes.\n";
  }
  
  ob = find_one_match(str, environment(me));
  if (!ob || !living(ob) ||
      member_array(ob, me->query_attacker_list()) == -1 )
    return "No estas luchando contra eso.\n";

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
    tell_object(me, "Tu objetivo no esta aqui.\n");
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
    tell_object(me, "Pierdes la concentracion.\n");

  return 0;
}

void end_focus(object me)
{
  me->remove_spell_effect("focus");
}
