/* Meditation by Greymist */

#define TRANCE "/d/gremios/comandos/meditation_sh.c"

string help()
{
  return
    "\n\n"
    "Nombre de la habilidad:  Meditacion \n\n"
    "Commando: Meditar"
    "\n\n"
    "  Este talento poderoso permite conocer la discilpina "
    "de enfocar el cuerpo y la mente para restaurar todo su "
    "pleno potencial.  Esta discilpina requiere concentracion, "
    "y si te distraes lo mas minimo saldras fuera de tu trance "
    "dejando de enfocar tu cuerpo.\n\n";
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
      write("Por alguna razon no puedes meditar en este lugar.\n");
   return 1;
   }

  if ( disc->query_trance() )
  {
    tell_object(disc, "Sales de tu trance de meditacion.\n");
    tell_room(env, disc->query_cap_name()+" sale del trance "
      "de meditacion y se levanta.\n", disc );
    disc->dest_trance();
    return 1;
  }

  if ( env->query_property("noregen") )
  {
    notify_fail("Por alguna razon no puedes alcanzar tu trance en este "
      "lugar.\n");
    return 0;
  }
  if ( sizeof( disc->query_attacker_list() ) ||
       sizeof( disc->query_call_outed() ) )
  {
    tell_object(disc,"No puedes meditar en medio de un combate!\n");
    return 1;
  }                
  if( (disc->query_property("meditation-good"))>2 &&
      (!env->query_outside()||(env->query_light())<80))
  {
    tell_object(disc,"No puedes meditar en este lugar, busca otro "
      "mejor.\nSolo puedes hacerlo en lugares buenos o A la luz del sol seria mucho mejor.\n");
    return 1;
  }
  else if( (disc->query_property("meditation-evil"))>2 &&
           (env->query_outside()||(env->query_light())>30))
  {
    tell_object(disc,"Solo puedes activar el poder mistico de la meditacion "
      "en algun lugar demoniaco.  Prueba en la oscuridad, "
      "seria ideal.\n");
    return 1;
  }

  tell_object(disc, "Formulas el cantico 'mindus es magnificus' y entras en "
    "trance.\n\n");
  tell_room(environment(disc),(string)disc->query_cap_name()+
    " formula el cantico 'mindus es magnificus' y "
    "entra en trance.\n\n", ({ disc }));

  stuff=all_inventory(disc);
  for(c=0;c<sizeof(stuff);c++)
  {
    if(stuff[c]->query_name()=="meditation_obj")
      return 1;
  }
  ob = clone_object(TRANCE);
  ob->setup_shadow(disc);
  if(ob->query_trance())
    ob->add_extra_look(TO);

  return 1;
}

string extra_look()
{
  return "Esta en trance.\n";

}
