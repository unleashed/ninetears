inherit "/std/object";

object mi_player, mi_invocacion;

int query_auto_load() { return 1; }

void setup_invocacion(object shaman, object invocacion, int invocacion_pv, int invocacion_pg)
{
  mi_player=shaman;
  mi_invocacion=invocacion;
  mi_invocacion->set_hp(invocacion_pv);
  mi_invocacion->set_gp(invocacion_pg);
  mi_invocacion->set_propietario(mi_player);
}

void setup()
{
  reset_drop();
}

void init()
{
  add_action("do_sigueme","sigueme");
  add_action("do_protegeme","protegeme");
  add_action("do_ataca","ataca");
  add_action("do_dismiss","despedir");
  add_action("do_convocar","convocar");
  if(mi_player&&!mi_player->query_static_property("criatura_invocada"))
    this_object()->dest_me();
  ::init();
}

int do_convocar()
{
  int coste = 20;

  if (this_player() != mi_player)
  {
    tell_object(this_player(),"No gozas de ning�n poder sobre �sta "
    "criatura, por lo tanto, ignora tus ordenes.\n");
    return -1; 
  }

  if ( ENV(this_player()) == ENV(mi_invocacion) )
  {
    tell_object(this_player(),"Para qu� convocar a una criatura que "
    "ya se encuentra junto a t�?\n");
    return -1; 
  }  
  
  if (this_player()->query_gp() < coste) {
    tell_object(this_player(),"No posees suficiente poder mental para "
    "convocar a la criatura a tu lado.\n");
    tell_room(ENV(this_player()), this_player()->QCN+" intenta convocar "
    "a su lado a "+mi_invocacion->query_name()+" pero no lo consigue.\n",this_player());
    return -1;
  }
  
  tell_room(ENV(mi_invocacion), mi_invocacion->QCN+" es rodeado por un "
  "fuego imp�o conforme se sumerge entre los planos para viajar junto "
  "a su leg�timo invocador.\n");
  mi_invocacion->move(environment(this_player()));
  tell_room(ENV(this_player()), mi_invocacion->QCN+" surge entre "
  "chorros de fuego imp�o, junto a su invocador.\n");
  
  this_player()->adjust_gp(-coste);
  
  return 1;  
}

int do_sigueme()
{
  if (this_player() != mi_player)
  {
    tell_object(this_player(),"No gozas de ning�n poder sobre �sta "
    "criatura, por lo tanto, ignora tus ordenes.\n");
    return -1; 
  }
  if ( (ENV(this_player())) != (ENV(mi_invocacion)) )
  {
    tell_object(this_player(),"La criatura no se encuentra presente "
    "aqu�, por lo que no es capaz de percibir tus ordenes.\n");
    return -1; 
  }
  tell_object(this_player(),"La criatura obedece tus ordenes y "
  "te sigue.\n");
  mi_invocacion->do_command("seguir "+this_player()->query_name());  
  return 1;  
} 

int do_protegeme()
{
  if (this_player() != mi_player)
  {
    tell_object(this_player(),"No gozas de ning�n poder sobre �sta "
    "criatura, por lo tanto, ignora tus ordenes.\n");
    return -1; 
  }
  if ( (ENV(this_player())) != (ENV(mi_invocacion)) )
  {
    tell_object(this_player(),"La criatura no se encuentra presente "
    "aqu�, por lo que no es capaz de percibir tus ordenes.\n");
    return -1; 
  }
   tell_object(this_player(),"La criatura obedece tus ordenes y "
  "te protege.\n");
  mi_invocacion->do_command("proteger "+this_player()->query_name());  
  return 1;  
} 

int do_ataca(string str)
{
  object ob;

  if (this_player() != mi_player)
  {
    tell_object(this_player(),"No gozas de ning�n poder sobre �sta "
    "criatura, por lo tanto, ignora tus ordenes.\n");
    return -1; 
  }
  
  if ( (ENV(this_player())) != (ENV(mi_invocacion)) )
  {
    tell_object(this_player(),"La criatura no se encuentra presente "
    "aqu�, por lo que no es capaz de percibir tus ordenes.\n");
    return -1; 
  }
  
  if (!str)
  {
    tell_object(this_player(),"Atacar a qui�n?\n");
    return -1; 
  }

  if(interactive(this_player())) 
    str = (string)this_player()->expand_nickname(str);  
  
  mi_invocacion->do_command("matar "+str);
  tell_object(this_player(),mi_invocacion->query_cap_name()+" ataca con toda su maligna ira a tus enemigos!\n");

  ob = present(str,environment(this_player()));
  if (ob)
  {
    ob->attack_by(mi_invocacion);
    ob->attack_by(this_player());
  } 
  return 1;
}

int do_dismiss()
{
  if ( (ENV(this_player())) != (ENV(mi_invocacion)) )
  {
    tell_object(this_player(),"La criatura no se encuentra presente "
    "aqu�, por lo que no es capaz de percibir tus ordenes.\n");
    return -1; 
  }
  
  tell_room(environment(mi_invocacion), 
  mi_invocacion->query_cap_name()+" asiente y se prepara "
  "para abandonar el plano material."
  "\n\n"+mi_invocacion->query_cap_name()+" "
  "estalla en miles de part�culas brillantes, que se "
  "difuminan en el aire lenta, lentamente...\n");
  mi_player->adjust_xp(mi_invocacion->query_xp());
  mi_invocacion->dest_me();
  mi_player->remove_static_property("criatura_invocada");
  this_object()->dest_me();
  return 1;
}
