/* Cleaning up.
 * Wonderflug, 96.
 */




int bury(string str,object x)
{
  object me;
  object *target;
  int counter,i;
 
  if(x) 
    me = x;
  else
    me = this_player();

  if (!str || str == "") 
    str = "cuerpo";

  if("/global/omiq.c"->flag_in_progress()){
    tell_object(me,"No puedes hacer esto en estos momentos.\n");
    return 0;
  }
  if(me->query_dead())
  {
    tell_object(me,"Ahora eres un espiritu , como no te entierres a ti mismo! "
      "cuerpos ?.\nDarken te patea en la cabeza y te dice: buen intento.\n ");
    return 1;
  }

  target = all_inventory(environment(me));

  counter = 0;
  for (i=0;i<sizeof(target);i++)
    if( target[i]->query_corpse() )
    {
      target[i]->dest_me(); // Allow them to clean up themselves.
      counter++;
    }

  if (counter)
    tell_object(me,"Entierras "+counter+" cuerpo"+(counter == 1?"":"s")+
      " bajo tierra.\n");
  else
    tell_object(me,"No has encontrado ningun cuerpo!\n");

  return 1;
}

string help()
{
  return
    "\nSintaxis: enterrar\n\n"
    "Este comando entierra todos los cuerpos que hay en la habitacion. Lo que hay en los  "
    "en los cuerpos sera enterrado tambien.\n\n";
}
