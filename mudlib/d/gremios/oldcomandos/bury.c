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
    tell_object(me,"You can't bury during capture the flag.\n");
    return 0;
  }
  if(me->query_dead())
  {
    tell_object(me,"Asi que intentando enterrar cuerpos cuando estas "
      "en forma espiritual, eh?.\n");
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
    tell_object(me,"Entierras "+ (counter == 1?"el":"los") + " cuerpo"+(counter == 1?"":"s")+
      " bajo tierra.\n");
  else
    tell_object(me,"No has encontrado ningun cuerpo!\n");

  return 1;
}

string help()
{
  return
    "\nSintaxis: enterrar\n\n"
    "Este comando entierra todos los cadaveres de un lugar.  Lo que haya "
    "en los cuerpos se entierra con ellos.\n\n";
}
