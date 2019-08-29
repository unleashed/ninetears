#include "invocaciones.h"
#include "unarmed_combat.h"

inherit "/obj/monster";

object mi_player;

#include "shaman.h"

void set_propietario(object shaman)
{
  mi_player=shaman;
}
void setup()
{
  set_name("demonio balor");
  set_short("Gran Demonio %^RED%^BOLD%^Balor%^RESET%^");
  add_alias(({"demonio","balor"}));
  set_main_plural("Grandes Demonios %^RED%^BOLD%^Balor");
  add_plural(({"demonios","balor"}));
  set_long("El horror. Los Balor son las criaturas m�s poderosas "
  "del Plano Abismal. Esta mastod�ntica criatura de casi tres metros "
  "de altura, de un intenso color fuego, bien te "
  "reducir a pulpa con sus poderosos brazos provistos de garras "
  "tan grandes como tu cara. Son los verdaderos reyes del infierno "
  "conocido como Plano Abismal.\n");
  set_gender(1);
  add_timed_property("recien_invocado",1,10);
  set_heart_beat(1);
  set_alineamiento(-1,-1);
  set_str(30);
  set_dex(19);
  set_con(19);
  set_wis(14);
  set_int(14);
  set_cha(18);
}
int unarmed_attack(object target, object me)
{
  int i;
  object *att;
  att=(object *)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(5,10);
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(5,10);
  if (!random(3)) {
    monster::unarmed_attack(att[random(sizeof(att))],me);
    set_damage_dice(5,10);
  }
}

valid_attack()
{
  int two, four;
  two=random(2);
  four=random(4);
  return([
    "punch"  :({AN+" "+({"muerde","ara�a",})[two]+" a "+DN+
      " en "+({"el brazo","la pierna","la cabeza","el pecho",})[four]+
      ".\n",
      "You "+({"swat","slap",})[two]+" "+DN+
      " on the "+({"arm","leg","head","chest",})[four]+
      ".\n",
      AN+" te "+({"muerde","ara�a",})[two]+" en "+
      ({"el brazo","la pierna","la cabeza","el pecho",})[four]+".\n"}),
    "kick"   :({AN+" "+({"golpea","corta",})[two]+" a "+DN+
      " en "+({"el brazo","la pierna","la cabeza","el pecho",})[four]+
      ".\n",
      "You "+({"slash","rend",})[two]+" "+DN+
      " on the "+({"el brazo","la pierna","la cabeza","el pecho",})[four]+
      ".\n",
      AN+" te "+({"slashes","rends",})[two]+" en "+
      ({"el brazo","la pierna","la cabeza","el pecho",})[four]+".\n"}),
    "knee"   :({AN+" "+({"desgarra","muerde",})[two]+" a "+DN+" en "+
      ({"el brazo","la pierna","la cabeza","el pecho",})[four]+".\n",
      "You "+({"bite","mangle",})[two]+" "+DN+"'s "+
      ({"arm","leg","head","chest",})[four]+".\n",
      AN+" te "+({"desgarra","muerde",})[two]+" en "+
      ({"el brazo","la pierna","la cabeza","el pecho",})[four]+".\n"})
  ]);
}
