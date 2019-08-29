/*** Decapitate ***/
/*** For assassins, by Wonderflug ***/

#define HEAD "/d/gremios/comandos/head.c"
#define GP_COST 10

string help()
{
  return
    "Command name: Decapitate\n"
    "GP Cost: "+GP_COST+"\n"
    "Syntax: decapitate <object>\n"
    "Decscription:\n"
    "    This ability lets you hack the head off of a corpse "
    "lying around.  Useful for trophies, and not much else "
    "really.  Of course, something still alive might get annoyed "
    "if you try this on them.\n\n";
}

int decapitate(string str,object x)
{
  object me;
  object* ob;
  object* weap;
  int noweap;
  object head;

  if(x)
    me = x;
  else
    me = this_player();

  if(!str || str == "") str = "corpse";

  if(me->query_property("dead"))
  {
    tell_object(me,"You, a disembodied ghost, expect to decapitate "
      "something?.\nCyric pats you on the head and tells you: Nice try.\n ");
    return 1;
  }

  if ( me->adjust_gp(-GP_COST) < 0 )
  {
    tell_object(me,"You are too tired to hack the head off anything.\n");
    return 1;
  }

  noweap=1;
  weap = me->query_held_ob();
  if ( weap[0] && (int)weap[0]->query_attack_type() != 2 ) noweap=0;
  if ( weap[1] && (int)weap[1]->query_attack_type() != 2 ) noweap=0;

  if ( noweap )
  {
    tell_object(me, "You'd make a mess of it without a sharp "
      "weapon in hand.\n");
    return 1;
  }

  ob = find_match(str, environment(me));
  if ( sizeof(ob) != 1 )
  {
    tell_object(me, "Umm.. decapitate which?\n");
    return 1;
  }
 
  ob = ob[0];
 
  if(living(ob))
  {
    tell_object(me, ob->query_cap_name()+" doesn't feel like being "
      "decapitated right now.\n");
    tell_object(ob, me->query_cap_name()+" walks toward you with a long "
      "sharp weapon in hand, then, looking\ncloser at your neck, appears "
      "startled and backs away, disappointed.\n");
    return 1;
  }
 
  if (!ob->query_corpse())
  {
    tell_object(me, "You can only decapitate corpses.\n");
    return 1;
  }
 
  if (ob->query_property("decapitated"))
  {
    tell_object(me, "Someone's beat you to the head of this one.  Wouldn't "
      "eat at the local\nrestaurant anytime soon if I were you.\n");
    return 1;
  }
 
  tell_object(me, "You hack the head off the "+ob->short()+".\n");
  tell_room(environment(me), me->query_cap_name()+" hacks the head off "
    "the "+ob->short()+".\n", me);
 
  ob->add_property("decapitated",1);
  ob->set_long(ob->query_long()+"\nIt appears someone has hacked off the "
    "head.\n");
 
  head = clone_object(HEAD);
  head->set_short("Decapitated head of "+ob->query_owner());
  head->move(environment(me));
 
  return 1;
}

