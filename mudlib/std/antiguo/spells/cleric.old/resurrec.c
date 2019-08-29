/*** Resurrect ***/
inherit "/std/spells/patch.c";

/* find_unique_match() does a find match that ensures the returned 
   object list contains no duplicates
   find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);
int cleric_fix_damage(object caster,object victim,int damage,string save);
object caster;
/*** modified by Eerevann ***/

/*** Sphere Necromantic ***/
/*** Level 7th ***/

#define SP_NAME "Resurrect"
#define GP_COST 14

/*** Help file here ***/
string help() {
   return
	"\n\n"
	"Spell Name: "+SP_NAME+"\n"
   "Sphere:  Necromantic\n"
   "Level:  7th\n"
   "Gp Cost: "+GP_COST+"\n"
   "Description: \n"
   "  This spell ressurects someone after they have died.  It does not remove "
   "one of your lives, unlike "
   "raise, and turns you back from being a ghost.\n\n";
}

mixed spell(string str, int cast);
 
int cast_spell(string str,object cast)
{
  mixed ret;

  caster = cast ? cast : this_player();

  if(interactive(caster))
	 str = (string)caster->expand_nickname(str);
  ret = spell(str, 1);
  if (stringp(ret)) {
    notify_fail(ret);
    return 0;
  }
  return 1;
}
 
mixed spell(string str, int cast) {     
  mixed ob;

  if (!str || str == "")
    return "You try to ressurect nothing and fail miserably.\n";
  ob = find_one_match(str, environment(caster));
  if (sizeof(ob))
    ob = ob[0];
  else
    return "Who is " + capitalize(str) + "?\n";
  if (!living(ob))
	 return (string)ob->query_cap_name() + " refuses to be brought to life.\n";
  if (!ob->query_property("dead"))
    return (string)ob->query_cap_name() + " is not dead ... yet.\n";
  if (ob->query_property("noregen"))
    return "Death tells you: HOLD ON, I'M NOT FINISHED WITH THEM YET.\n";
  if (cast && (int)caster->adjust_gp(-GP_COST) < 0)
    return "Too low on power.\n";
  tell_object(caster,"You call upon the gods to restore to life "+(string)ob->query_cap_name()+
    " from " + (string)ob->query_possessive() + " immaterial state by "
    "hitting "+ob->query_pronoun()+" with a lightning bolt..\n");
  tell_object(ob, (string)caster->query_cap_name() +
    " summons the gods for you, and incidently hits you with a lightning "
    "bolt.  It doesn't seem to hurt.\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + " stares intently into space, "
    "you hear a vage rumbling in the distance, suddenly a lightning bolt "
    "sears through the sky and hits "+ob->query_cap_name()+" restoring "
    " them from the dead.\n", ob);

  ob->remove_ghost();
/* removed to player.c Taniwha 1995
  ob->adjust_con(-1);
   ob->remove_property("dead");
  ob->adjust_max_deaths(1);
*/
   /* adjust the HP back to max, and if the roll is good give the con point back */
   if((int)ob->query_level() > 5)
   {
   if(random((int)caster->query_level()) > random((int)ob->query_level())) ob->adjust_con(1);
   }

  return (random(2000));
}
