/* Invocar de Shamanes. Xerxes Dic. 2002 */
#include "invocaciones.h"

inherit "/std/object";

int invocar(string que)
{
  object yo;
  
  if (!yo) yo=this_player();

  if(sizeof(yo->query_attacker_list()))
  {
    notify_fail("No es una buena idea invocar una criatura "
    "durante el fragor de la batalla.\n");
    return 0;
  }

  tell_object(yo, "Cierras tus ojos y comienzas a concentrar "
  "energ�a para abrir un portal al Plano del Abismo.\n");
  
  call_out("turno2", 2, que);
}

int turno2(string que)
{
  object yo;
  
  if (!yo) yo=this_player();
    
  tell_object(yo, "Una serie de brillantes puntos blancos comienzan "
  "a reunirse en el aire delante de t�, dando forma a una puerta "
  "entre los Planos.\n");
  
  call_out("turno3", 2, que);
}

int turno3(string que)
{
  object yo;
  
  int coste, nivel_minimo;
  int invocacion_pv, invocacion_pg;
  int bonus_sab;
  
  string INVOCACION;
  
  object invocacion, shadow, ob;
  
  if (!yo) yo=this_player();
  if (yo->query_timed_property("MALDICION_INVOCAR")) 
  {
    notify_fail("Una enorme garra procedente del portal te "
    "golpea y te hace caer de bruces!\n\nUna voz gutural "
    "retumba en tu mente: Todav�a no hemos olvidado tu "
    "reciente fracaso!!! No vuelvas a molestarnos!!!\n");
    yo->adjust_hp(-(10+random(15)));
    return 0;
  }
  if (yo->query_alineamiento()[1] == 1)
  {
    notify_fail("Una enorme garra procedente del portal "
    "te coge y te aprieta hasta que pierdes el conocimiento...\n\n"
    "Una voz retumba en tu mente: C�mo un adalid del bien ha osado "
    "invocarnos!!! Ahora lo pagar�s con tu vida!!!\n\n%^RED%^BOLD%^"
    "La garra aprieta hasta m�s no poder, y tu cuerpo revienta por "
    "la presi�n.%^RESET%^\n");
    yo->do_death();
    return 0;
  }  
  switch(que)
  {
    case "diablillo":
      nivel_minimo=10;
      coste=5;
      INVOCACION=WEASEL;
      invocacion_pv=4;
      invocacion_pg=4;
      break;
    default:
      coste=-1;
      break;
  }  
  if(yo->query_level() < nivel_minimo || coste == -1)
  {
    notify_fail("No hay ninguna criatura as� que quiera oir "
    "tu llamada, y el portal se cierra.\n");
    return 0;
  }
  if(yo->query_gp() < coste)
  {
    notify_fail("Tus piernas comienzan a temblar: eres "
    "incapaz de mantener la concentraci�n, y el portal "
    "se cierra.\n");
    return 0;
  }
  if(yo->query_static_property("criatura_invocada"))
  {
    notify_fail("Una voz retumba en tu mente: Es muy "
    "ambicioso por tu parte querer controlar a dos "
    "criaturas!!!\n\nEl portal se cierra.\n");
    return 0;
  }  
  
  bonus_sab=(yo->query_wis()-15)*yo->query_level();

  if (bonus_sab < 0)
    bonus_sab = -(yo->query_level());

  yo->adjust_gp(-coste);
  
  if(!file_exists(INVOCACION))
  {
    notify_fail("Invocar el qu�?\n");
    return 0;
  }
  
  yo->add_static_property("criatura_invocada",1);
  
  invocacion=clone_object(INVOCACION);
  invocacion->move(environment(yo));
  invocacion->set_my_player(yo);
  invocacion->set_max_hp(roll(yo->query_level(),invocacion_pv)+bonus_sab);
  invocacion->set_max_gp(roll(yo->query_level(),invocacion_pg)+bonus_sab);
  invocacion->set_thac0(yo->query_thac0() -yo->query_level() -bonus_sab);
  ob=clone_object(OBJECT);
  ob->move(yo);
  ob->setup_invocacion(yo,invocacion,invocacion_pv,invocacion_pg);
  invocacion->set_hp(invocacion->query_max_hp());
  invocacion->set_gp(invocacion->query_max_gp());
  
  tell_room(ENV(yo), "El Plano del Abismo escucha las suplicas de "+
  yo->QCN+" y envia un "+invocacion->query_short()+" para ayudarle "
  "a destruir a sus enemigos.\n");
  write("Un enorme "+invocacion->query_short()+" responde a tu llamada "
  "y aparece en el Plano Material para ayudarte.\n");
  return 1;
}

string help()
{
  return
    "Nada en absoluto";
    "\n";
}
