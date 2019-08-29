/* Meditation by Greymist */

#define TRANCE "/d/gremios/comandos/meditation_sh.c"

string help()
{
  return
    "\n\n"
    "Nombre de Habilidad:  Trance \n\n"
    "Comando: Meditar"
    "\n\n"
    "  This powerful talent allows the disciple to "
    "focus the body and mind toward restoration of their "
    "full potential.  The disciple must concentrate, and "
    "destractions will cause them to break out of their "
    "trance, shattering the focus.\n\n";
}


int meditate(string str)
{
  object ob;
  object *stuff;
  int c;
  object disc = this_player();
  object env=environment(disc);
   if( environment(this_player())->query_property("no_undead")) 
   {
      write("Por alguna razon te siente tan seguro aqui que no podrias meditar.\n");
   return 1;
   }

  if ( disc->query_trance() )
  {
    tell_object(disc, "Sales de tu estado de trance.\n");
    tell_room(env, disc->query_cap_name()+" sale de su estado de "
      "trance y se levanta.\n", disc );
    disc->dest_trance();
    return 1;
  }

  if ( env->query_property("noregen") )
  {
    notify_fail("Por alguna razon no puedes entrar en trance "
      "aqui.\n");
    return 0;
  }
  if ( sizeof( disc->query_attacker_list() ) ||
       sizeof( disc->query_call_outed() ) )
  {	// mmm, sin estar en peleas ni nada, solo un orco
	// al intentarme apunyalar, call_out esto ia salta...
    tell_object(disc,"Tu poder mental no te permite meditar en medio de una pelea!\n");
    return 1;
  }                
  if( (disc->query_property("meditation-good"))>2 &&
      (!env->query_outside()||(env->query_light())<80))
  {
    tell_object(disc,"Solo puedes conseguir una buena preparacion de tu "
      "mente en un ambiente de Bien. La luz del sol puede ser de ayuda.\n");
    return 1;
  }
  else if( (disc->query_property("meditation-evil"))>2 &&
           (env->query_outside()||(env->query_light())>30))
  {
    tell_object(disc,"Solo puedes conseguir una buena preparacion de tu "
      "mente en un ambiente de Mal. Un lugar oscuro y cerrado seria "
      "ideal.\n");
    return 1;
  }

  tell_object(disc, "Pronuncias el cantico 'mindus es magnificus' y entras "
    "en trance.\n\n");
  tell_room(environment(disc),(string)disc->query_cap_name()+
    " pronuncia el cantico 'mindus es magnificus' y "
    "entra en trance.\n\n", ({ disc }));

  stuff=all_inventory(disc);
  for(c=0;c<sizeof(stuff);c++)
  {
    if(stuff[c]->query_name()=="meditation_obj")
      return 1;
  }
  ob = clone_object(TRANCE);
  ob->setup_shadow(disc);

  return 1;
}
