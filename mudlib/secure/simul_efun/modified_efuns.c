#define MAX_SIZE 50000
// Taniwha 1995. Got fed up :). maybe return 0 is better, maybe not
string lower_case(string str)
{
   if(!stringp(str)) return "";
   else return efun::lower_case(str);
}

string capitalize(string str)
{
   if(!stringp(str)) return "";
   else return efun::capitalize(str);
}


varargs void say(string str, mixed avoid) {
  if (!pointerp(avoid))
    avoid = ({ this_player(), previous_object() }) + ({ avoid });
  else
    avoid += ({ this_player(), previous_object() });
  if (!environment(previous_object()))
    if (this_player() && environment(this_player()))
      event(environment(this_player()), "say", str, avoid);
    else
      event(previous_object(), "say", str, avoid);
  else
    event(environment(previous_object()), "say", str, avoid);
} /* say() */

varargs void tell_room(object ob, string str, mixed avoid) {
  if (!ob || !objectp(ob))
    return ;
  event(ob, "say", str, avoid);
} /* tell_room() */

void tell_object(object ob, string str) {
  if (objectp(ob))
    ob->event_write(previous_object(), str);
} /* tell_object() */

object find_living(string str) {
  string nick;
  object ob;

  if(!stringp(str)) return 0; // Taniwha 1995
  if (this_player() && (nick = (string)this_player()->expand_nickname(str)))
    str = nick;
  if ((ob = efun::find_living(str)))
    if ((int)ob->query_invis() == 2)
      return 0;
  return ob;
} /* find_living() */

object find_player(string str) {
  object ob;
  if(!stringp(str)) return 0; // Taniwha 1995
  if ((ob = efun::find_player(str)))
    if ((int)ob->query_invis() == 2)
      return 0;
  return ob;
} /* find_player() */

/* Hamlet added me */
/* Taniwha removed me, recurses to death in line (now 73)
object clone_object(string file) {
  object ret;
  seteuid(geteuid(previous_object()));
  
  if(find_object(file) || (member_array(explode(file,"/")[0],
                                       ({ "d", "w", "baseobs" })) == -1))
    catch(ret = efun::clone_object(file));
  else
    catch(ret = efun::load_object(file));

  seteuid(0);
  return ret;
}
*/

