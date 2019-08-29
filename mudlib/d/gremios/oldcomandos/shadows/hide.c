/* The hide in shadows shadow.  Cute huh?
*/

#define LEVEL_MOD 2
object tp;
int found;

void dest_hide_shadow();

void setup_shadow(object ob) {
   if(ob->query_hide_shadow())
   {
      return;
   }
  tp = ob;
  shadow(ob,1);
}

int attack_by(object him)
{
  dest_hide_shadow();
  return tp->attack_by(him);
}

int cast(string str)
{
  dest_hide_shadow();
  return tp->cast(str);
}

int attack_ob(object him)
{
  dest_hide_shadow();
  return tp->attack_ob(him);
}

object *move_player(string dir, string dest, string mess, object ob) {
  if ( !ob || ob != tp )
    dest_hide_shadow();
  return (object *)tp->move_player(dir, dest, mess, ob);
}

int do_death(string str) {
  dest_hide_shadow();
  return (int)tp->do_death(str);
}

int do_loud_say(string str) {
  dest_hide_shadow();
  return (int)tp->do_loud_say(str);
}

int do_emote(string str) {
  dest_hide_shadow();
  return (int)tp->do_emote(str);
}

int do_echo(string str) {
  dest_hide_shadow();
  return (int)tp->do_echo(str);
}

int do_say(string str) {
  dest_hide_shadow();
  return (int)tp->do_say(str);
}

int event_player_search() {
  dest_hide_shadow();
}

int soul_com(string str) {
  int i;

  if ((i = (int)tp->soul_com(str)) == 1)
    dest_hide_shadow();
  return i;
}

/* EL PROBLEMO DEL CALL_OUT! */
/* Ejemplo: Si EMBOSCAMOS a alguien escondido, al poner
   algo asi como victima->attack_by(me) se destruye la shadow
   PERO al volver y poner me->attack_ob o by(victima) tb se
	destruye! El problema no es que se destruya dos veces
	pq solo la primera es efectiva, el problema es que
	nos NOTAN 2 VECES!
   Por eso, if found se comprueba aki! */
void dest_hide_shadow() {
	if (!found) {
  tell_room(environment(tp), "Notas a "+tp->query_cap_name()+" moverse a tu alrededor.\n",
            ({ tp }));
  tell_object(tp, "Te han descubierto!\n");
  found = 1;
	}
  call_out("do_dest_hide_shadow",0);
}

void do_dest_hide_shadow() {
  destruct(this_object());
}

int query_hide_shadow()
{
  int i;
// aiiiinz
	if (found)
		return 0;
  i = random((int)tp->query_level() * LEVEL_MOD );
  i = (i==0) ? 1 : i;
  return i;
}

string pretty_short() { 
  if (found && tp)
    return (string)tp->pretty_short();
  if (TP)
  if (TP->query_creator() || TP->query_property("sense_life"))
	return (string)("*"+(string)tp->pretty_short()+"*");
	return (string)((string)tp->pretty_short());
  return 0;
}

string short() {
  if (found && tp || (query_verb() && query_verb() == "who"))
    return (string)tp->short();
  if (TP)
//  if (TP->query_creator())
  if (TP->query_creator() || TP->query_property("sense_life"))
	return (string)("*"+(string)tp->short()+"*");
  return 0;
}

string hidden_short() {
	return (string)tp->short();
}

string combat_short() {
	return (string)tp->short();
}

string pretty_plural() {
  if (found && tp)
    return (string)tp->pretty_plural();
  if (TP)
//  if (TP->query_creator())
  if (TP->query_creator() || TP->query_property("sense_life"))
    return (string)("*"+(string)tp->pretty_plural()+"*");
  return 0;
}

string query_plural() {
  if (found && tp)
    return (string)tp->query_plural();
  if (TP)
//	if (TP->query_creator())
  if (TP->query_creator() || TP->query_property("sense_life"))
		return (string)("*"+(string)tp->query_plural()+"*");
 return 0;
}
