#include "invocaciones.h"

inherit "/std/object";

#define STUN_SHADOW "/d/gremios/comandos/shadows/invocar_stun.c"

void setup_stun(int damage, object mugger, object target);
int inicio(string que)
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
  "energ�a para abrir un portal al Plano Abismal, "
  "perdiendo totalmente la consciencia.\n\n");

  setup_stun(4, yo, yo);
  
  tell_room(ENV(yo), yo->QCN+" cierra sus ojos y comienza a "
  "concentrarse, cayendo inconsciente. Una maldad infinita emana "
  "de su contorno, deduces que no se avecina nada positivo.\n\n",yo);
  
  call_out("turno2", 4);
  
  return 1;
}

int turno2()
{
  object yo;
  
  if (!yo) yo=this_player();
    
  tell_object(yo, "Una serie de brillantes puntos blancos comienzan "
  "a reunirse en el aire delante de t�, dando forma a la puerta "
  "entre los planos.\n\n");
  
  tell_room(ENV(yo), "Una serie de brillantes puntos blancos "
  "comienzan a girar en torno a "+yo->QCN+", dando forma a una "
  "puerta entre planos.\n\n",yo);
 
  call_out("turno3", 6);
  
  return 1;
}

int turno3()
{
  object yo;
  
  int coste, mi_nivel, su_thac0;
  int invocacion_pv, invocacion_pg;
  int bonus_sab;
  
  string INVOCACION;
  
  object invocacion, shadow, ob;
  
  if (!yo) yo=this_player();
  
  if (yo->query_timed_property("MALDICION_INVOCAR")) 
  {
    tell_room(ENV(yo), "Una enorme garra sale de la puerta y "
    "golpea a "+yo->QCN+".\n\n",yo);
    tell_object(yo, "Una enorme garra procedente de la puerta te "
    "golpea y te hace caer de bruces!\n\nUna voz gutural "
    "retumba en tu mente: Todav�a no hemos olvidado tu "
    "reciente traici�n!!! No vuelvas a molestarnos!!!\n\n");
    yo->adjust_hp(-(30+random(15)));
    return 0;
  }
  if (yo->query_alineamiento()[1] == 1)
  {
    tell_room(ENV(yo), "Una enorme garra sale de la puerta y "
    "aprieta a "+yo->QCN+" hasta la muerte.\n\n",yo);
    tell_object(yo, "Una enorme garra procedente de la puerta "
    "te coge y te aprieta hasta que pierdes el conocimiento...\n\n"
    "Una voz retumba en tu mente: C�mo un adalid del bien ha osado "
    "invocarnos!!! Ahora lo pagar�s con tu vida!!!\n\n%^RED%^BOLD%^"
    "La garra aprieta hasta m�s no poder, y tu cuerpo revienta por "
    "la presi�n.%^RESET%^\n\n");
    yo->do_death();
    return 0;
  }
  
  mi_nivel = yo->query_level();
  
  if (mi_nivel < 12) {
    tell_room(ENV(yo), yo->QCN+" no recibe respuesta alguna de "
    "la puerta dada su inexperiencia, y �sta se cierra.\n\n",yo);
    tell_object(yo, "Dada tu inexperiencia en las malignas artes "
    "de la invocaci�n, no recibes respuesta alguna, y la puerta "
    "se cierra sin m�s.\n\n");
    return 0;    
  } else if (mi_nivel < 26) { // Demonio Dretch (12-25)
    coste=20;
    INVOCACION=DRETCH;
    su_thac0 = -20;
    invocacion_pv=1;
    invocacion_pg=1;
  } else if (mi_nivel < 36) { // Demonio Hezrou (26-35)
    coste=40;
    INVOCACION=HEZROU;
    su_thac0 = -30;
    invocacion_pv=1;
    invocacion_pg=1;
  } else if (mi_nivel < 44) { // Demonio Bebilith (36-43)
    coste=60;
    INVOCACION=BEBILITH;
    su_thac0 = -35;
    invocacion_pv=1;
    invocacion_pg=1;
  } else if (mi_nivel < 52) { // Demonio Glabrezu (44-51)
    coste=80;
    INVOCACION=GLABREZU;
    su_thac0 = -40;
    invocacion_pv=2;
    invocacion_pg=1;
  } else if (mi_nivel < 66) { // Demonio Balor (52-65)
    coste=100;
    INVOCACION=BALOR;
    su_thac0 = -55;
    invocacion_pv=2;
    invocacion_pg=2;
  } else { // Balor Dunkel'heit (66+)
    coste=250;
    INVOCACION=DUNKELHEIT;
    su_thac0 = -70;
    invocacion_pv=3;
    invocacion_pg=2;
  }
  if(yo->query_gp() < coste)
  {
    tell_object(yo, "Tus piernas comienzan a temblar: eres "
    "incapaz de mantener la concentraci�n, y la puerta "
    "se cierra.\n\n");
    tell_room(ENV(yo), yo->QCN+" comienza a flaquear y desiste "
    "en su intento de invocar.\n\n",yo);
    return 0;
  }
  if(yo->query_static_property("criatura_invocada"))
  {
    tell_object(yo, "Una voz retumba en tu mente: Es muy "
    "ambicioso por tu parte querer controlar a dos "
    "criaturas!!!\n\nLa puerta se cierra sin que hayas "
    "tenido apenas oportunidad de hacer nada.\n\n");
    tell_room(ENV(yo), yo->QCN+" es avergonzado por su ambici�n "
    "mientras que el portal se cierra con una risa demon�aca "
    "haciendo un eco infinito.\n",yo);
    return 0;
  }  
  
  bonus_sab=(yo->query_wis()-15)*(yo->query_level()/2);

  if (bonus_sab < 0)
    bonus_sab = -(yo->query_level());

  yo->adjust_gp(-coste);
  
  if(!file_exists(INVOCACION))
  {
    tell_object(yo, "Invocar el qu�?\n");
    return 0;
  }
  
  yo->add_static_property("criatura_invocada",1);
  
  invocacion=clone_object(INVOCACION);
  invocacion->move(environment(yo));
  invocacion->set_propietario(yo);
  invocacion->set_max_hp(roll(yo->query_level(),invocacion_pv)+bonus_sab);
  invocacion->set_max_gp(roll(yo->query_level(),invocacion_pg)+bonus_sab);
  ob=clone_object(OBJECT);
  ob->move(yo);
  ob->setup_invocacion(yo,invocacion,invocacion_pv,invocacion_pg);
  invocacion->set_hp(invocacion->query_max_hp());
  invocacion->set_gp(invocacion->query_max_gp());
  invocacion->set_level(yo->query_level());
  invocacion->set_thac0(su_thac0);
  
  tell_room(ENV(yo), "El Plano Abismal escucha las suplicas de "+
  yo->QCN+" y envia un "+invocacion->query_short()+" para ayudarle "
  "a destruir a sus enemigos.\n\n",yo);
  write("Un "+invocacion->query_short()+" responde a tu llamada "
  "y entra al Plano Material.\n\n");
  
  return 1;
}

void setup_stun(int damage, object mugger, object target)
{
  object shad;
  target->add_timed_property("passed out",1,damage);
  target->add_timed_property("steal at will",1,damage);
  target->add_timed_property("stun_on",1,damage);
  if ( !interactive(target) )
    call_out("wake_up", damage, target, mugger);
  
  shad = clone_object(STUN_SHADOW);
  shad->setup_shadow(target);
}
 
void wake_up(object who, object me)
{
  if ( who && me )
    who->attack_by(me);
}

string help()
{
  return "\n\n"
  "     %^RED%^El Imp�o Arte de la Invocaci�n%^RESET%^\n"
  "     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^RESET%^\n\n"
  "Sintaxis: invocar\n"
  "Coste: Aumenta junto con la experiencia del shaman\n\n"
  "La invocaci�n es el arte innato de los shamanes para "
  "establecer contacto con el Plano Abismal. Mediante dicho "
  "favor son capaces de convocar una criatura que les ayudar� "
  "para aniquilar a sus enemigos.\n\nEl poder y el tipo de "
  "criatura invocada mejorar� cuanto mayor sea la experiencia "
  "del shaman, y cuanta m�s sabidur�a acumule en su alma.\n\n"
  "Los comandos b�sicos de las invocaciones son:\n"
  "<sigueme>              Hace que la criatura te siga\n"
  "<protegeme>            Hace que la criatura te proteja\n"
  "<ataca [victima/s]>    Hace que la criatura ataque\n"
  "<despedir >            Devuelve a la criatura al Plano Abismal\n"
  "<convocar>             Haciendo uso de la energ�a del Shaman,\n"
  "                       hace que la criatura vuelva junto a �l. Es\n"
  "                       un comando �til cuando la criatura no es\n"
  "                       capaz de acceder a determinados lugares\n"
  "                       Coste: 20 gps.\n";
}
