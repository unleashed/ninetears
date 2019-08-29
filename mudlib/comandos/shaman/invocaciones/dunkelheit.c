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
  set_name("dunkelheit");
  set_short("%^RED%^BOLD%^Dunkelheit%^RESET%^, Se�or del Plano Abismal");
  add_alias("dunkelheit");
  set_main_plural("Varios %^RED%^BOLD%^Dunkelheit%^RESET%^, Se�ores del Plano Abismal");
  add_plural(({"varios","dunkelheits"}));
  set_long("Dunkelheit es el Se�or de los Balor del Plano Abismal, y "
  "por consiguiente el m�s poderoso de entre ellos. Se trata de una "
  "criatura �nica, que seguramente ha venido al Plano Material por "
  "maligna bendici�n a alg�n invocador, ya que rara vez suele perder "
  "el tiempo en �ste plano: suele estar muy ocupado martirizando "
  "y torturando a criaturas tan poderosas que tu imaginaci�n no "
  "ser�a capaz de concebir. Ahora esta aqu� para sembrar el "
  "caos y el horror.\n");
  set_gender(1);
  add_timed_property("recien_invocado",1,10);
  set_heart_beat(1);
  set_alineamiento(-1,-1);
  set_str(45);
  set_dex(21);
  set_con(25);
  set_wis(30);
  set_int(32);
  set_cha(40);
}
int unarmed_attack(object target, object me)
{
  int i;
  object *att;
  att=(object *)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(6,10);
  monster::unarmed_attack(att[random(sizeof(att))],me);
  set_damage_dice(6,10);
  if (!random(3)) {
    monster::unarmed_attack(att[random(sizeof(att))],me);
    set_damage_dice(6,12);
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
