object tp;

void dest_fd_shadow()
{
  tell_room(ENV(tp),"%^YELLOW%^Miles, millones de pequenyos "
  "puntos de luz comienzan a concentrarse ante tus ojos.\n\n"
  +tp->query_cap_name()+" se materializa en este plano...\n"
  "   ...particula a particula,\n"
  "      ...atomo a atomo,\n"
  "         ...molecula a molecula.\n%^RESET%^",tp);
  tell_object(tp,"%^RED%^Regresas al Plano Material .\n");
  tp->remove_extra_look("/w/xerxes/obj/shadows/forma_demoniaca.c");
  call_out("do_dest_fd_shadow",0);
}

void do_dest_fd_shadow()
{
  destruct(TO);
}

void setup_shadow(object ob)
{
  tp = ob;
  shadow(ob,1);
  tell_object(tp,"%^RED%^Te concentras en el punto mas "
  "profundo de tu alma y convocas tu Forma del Plano del Abismo: "
  "el Glabrezu.%^RESET%^\n");
  tell_room(ENV(tp),"%^RED%^BOLD%^"+tp->QCN+" se concentra "
  "profundamente, y toma la forma de tu temible Glabrezu.\n",tp);
  tp->add_extra_look("/w/xerxes/obj/shadows/glabrezu.c");
  call_out("dest_fd_shadow",100);
}

string extra_look(object ob)
{
  return "%^BOLD%^RED%^Tiene la forma de un Glabrezu%^RESET%^\n";
}

int query_fd_shadow()
{
  return 1;
}

int unarmed_attack(object target, object me)
{
  int i;
  object *att;
  att=(object *)me->query_attacker_list();
  TP->adjust_tmp_damage_bon(45);
  TP->unarmed_attack(att[random(sizeof(att))],me);
  TP->unarmed_attack(att[random(sizeof(att))],me);
  TP->unarmed_attack(att[random(sizeof(att))],me);
  TP->unarmed_attack(att[random(sizeof(att))],me);
  TP->adjust_tmp_damage_bon(-45);
}

