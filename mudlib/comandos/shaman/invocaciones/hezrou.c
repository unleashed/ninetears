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
  set_name("demonio hezrou");
  set_short("Demonio Hezrou");
  add_alias(({"demonio","hezrou"}));
  set_main_plural("Demonios Hezrou");
  add_plural(({"demonios","hezrou"}));
  set_long("Los Hezrou son unos Tanar'ri de tama�o moderado, "
  "de brillantes ojos rojos y de poderosos brazos terminados en "
  "garras dobles. Posee un denso pelaje a lo largo de pecho y "
  "espalda que le proporciona una presencia aterradora.\n");
  set_gender(1);
  add_timed_property("recien_invocado",1,10);
  set_heart_beat(1);
  set_alineamiento(-1,-1);
  set_str(18);
  set_dex(17);
  set_con(17);
  set_wis(12);
  set_int(12);
  set_cha(14);
}
int unarmed_attack(object target, object me)
{
  int i;
  object *att;
  att=(object *)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(3,8);
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(3,8);
  if (!random(5))
  {
    monster::unarmed_attack(att[random(sizeof(att))],me);
    set_damage_dice(4,6);
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
