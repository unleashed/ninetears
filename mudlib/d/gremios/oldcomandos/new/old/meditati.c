/* The meditation shadow, by Greymist
 */

object my_tp, TRANCE;
#define OBJ "/d/gremios/comandos/meditation_obj.c"

int adjust_hp(int dam, object hitter)
{
int damm=dam;
if(dam<0){damm=3*dam;}
return my_tp->adjust_hp(damm,hitter);
}


void setup_shadow(object disciple) {
  my_tp = disciple;
  shadow(disciple,1);
TRANCE=clone_object(OBJ);
  TRANCE->set_get();
  TRANCE->move(disciple);
  TRANCE->reset_get();
  TRANCE->reset_drop();
  TRANCE->set_trance(disciple);
  disciple->add_static_property("nocast", 1);
}

void dest_trance() {
  call_out("do_dest_trance",0);
TRANCE->destruct_trance();
}

attack_by(object him)
{
  dest_trance();
  return my_tp->attack_by(him);
}

attack_ob(object him)
{
  dest_trance();
  return my_tp->attack_ob(him);
}

object *move_player(string dir, string dest, string mess, object ob) {
  if ( this_player(1)->query_creator() )
    return my_tp->move_player(dir, dest, mess, ob);
  tell_object(my_tp, "You cannot move while meditating!\n");
  return 0;
}

int do_death(string str) {
  dest_trance();
  return (int)my_tp->do_death(str);
}

void do_dest_trance() {
  my_tp->remove_static_property("nocast");
  tell_object(my_tp, "You are no longer meditating.\n");
   destruct(this_object());
}

int query_trance()
{
	return 1;
}

int query_total_ac()
{
  return my_tp->query_total_ac() + 100;
}

mixed query_property(string prop)
{
  if ( prop == "sense_life" )
    return 0;
  else return my_tp->query_property(prop);
}

