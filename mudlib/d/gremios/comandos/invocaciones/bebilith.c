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
  set_name("demonio bebilith");
  set_short("Demonio Bebilith");
  add_alias(({"demonio","Bebilith"}));
  set_main_plural("Demonios Bebilith");
  add_plural(({"demonios","bebilith"}));
  set_long("Una gran bestia bipeda, de enormes fauces y poderosas "
  "garras. Son unos de los mas terribles enemigos en el Plano "
  "Abismal, donde caminan en peque�os grupos buscando seres m�s "
  "d�biles a los que martirizar hasta el fin de los d�as.\n");
  set_gender(1);
  add_timed_property("recien_invocado",1,10);
  set_heart_beat(1);
  set_alineamiento(-1,-1);
  set_str(26);
  set_dex(18);
  set_con(18);
  set_wis(12);
  set_int(12);
  set_cha(15);
}
int unarmed_attack(object target, object me)
{
  int i;
  object *att;
  att=(object *)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(4,8);
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(4,8);
  if (!random(5))
  {
    monster::unarmed_attack(att[random(sizeof(att))],me);
    set_damage_dice(4,8);
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
