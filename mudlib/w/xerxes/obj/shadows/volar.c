/* Shadow del Vuelo. Para Quest. Xerxes, Nov.2002 */
object tp;

void dest_volar_shadow()
{
  tell_room(ENV(tp),tp->QCN+" aterriza suavemente en el suelo.\n",tp);
  tell_object(tp,"Aterrizas suavemente en el suelo.\n");
  tp->remove_extra_look("/d/urghak/shadows/volar.c");
  tp->setmin(" $N llega de $F.");
  tp->setmout(" $N se va hacia $T.");
  call_out("do_dest_volar_shadow",0);
}

void do_dest_volar_shadow()
{
  destruct(TO);
}

void setup_shadow(object ob)
{
  tp = ob;
  shadow(ob,1);
  tell_object(tp,"Te elevas entre las corrientes de aire.\n");
  tell_room(ENV(tp),tp->QCN+" se eleva entre las corrientes de aire.\n",tp);
  tp->add_extra_look("/d/urghak/shadows/volar.c");
  tp->setmin(" $N llega volando de $F.");
  tp->setmout(" $N se va volando hacia $T.");
  call_out("dest_volar_shadow",100);
}

string extra_look(object ob)
{
  return "Esta volando.\n";
}

int query_volar_shadow()
{
  return 1;
}

varargs mixed move_player(string dir, string dest, mixed message, object followee, mixed enter)
{
  tell_object(tp, "Te vas volando hacia el "+dir+".\n");
  return tp->move_player(dir, dest, message, followee, enter);
}
