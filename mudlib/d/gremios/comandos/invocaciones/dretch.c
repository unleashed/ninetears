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
  set_name("demonio dretch");
  set_short("Demonio Dretch");
  add_alias(({"demonio","dretch"}));
  set_main_plural("Demonios Dretch");
  add_plural(({"demonios","dretch"}));
  set_long("Se trata de un demonio de color rojizo, de unos "
  "1'60 metros de altura. Posee unas horribles fauces provistas de "
  "afilados colmillos con los que muerde a sus v�ctimas. Tambi�n "
  "tiene un par de peque�as alas laterales, pero dudas mucho de "
  "que sea capaz de volar.\n");
  set_gender(1);
  add_timed_property("recien_invocado",1,10);
  set_heart_beat(1);
  set_alineamiento(-1,-1);
  set_str(18);
  set_dex(16);
  set_con(16);
  set_wis(10);
  set_int(10);
  set_cha(12);
}
int unarmed_attack(object target, object me)
{
  int i;
  object *att;
  att=(object *)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(2,10);
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(2,10);
  if (!random(6))
  {
    monster::unarmed_attack(att[random(sizeof(att))],me);
    set_damage_dice(3,4);
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
