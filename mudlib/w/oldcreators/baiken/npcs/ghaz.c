//Gurthang Mayo'01
inherit "/obj/monster";
#include "no_muerto.c";
#define QCN query_cap_name()
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
object caster;
int seguir = 0, proteger = 0;
int contador = 0;


/*
void mueve()
{
  if(seguir && contador > 2)
    if(ENV(caster)!=ENV(TO))
    {
        TO->move(ENV(caster));
        tell_room(ENV(TO),"Ghazghkull "+caster->QCN+" se mueve en "
                          "pos de su Amo.\n", caster);
        tell_object(caster,"Ghazghkull llega a tu lado para ayudarte "
                           "en todo cuanto necesites.\n");
        contador = 0;
    }
  contador ++;
  call_out("mueve",2);
}
*/


void setup()
{

  set_name("ghazghkull");
  set_short("Ghazghkull Espiritu Guerrero");
  set_main_plural("Varios Espiritus Guerreros");
  add_alias("espiritu");
  add_alias("guerrero");
  add_plural("espiritus");
  add_plural("guerreros");
  set_long("Este espiritu, proveniente de las mas internas esferas del "
           "inframundo, tiene un gran poder y ejerce una gran influencia sobre la "
           "materia fisica, cosa que no pueden controlar otros Demonios. El Demonio "
           ",de color indefinido, es grande, muy grande, y su forma material es de una "
           "gran y poderosa musculatura.\n");

  set_random_stats(17,18);
  set_str(20+random(8));
  set_level(25+random(15));
  set_max_hp(500);
  set_max_gp(500);
  set_race("espiritu");
  set_guild("fighter");
  set_guild_ob("/std/guilds/warriors/fighter");
  adjust_tmp_damage_bon(8);
  add_clone("/baseobs/weapons/bastard_sword",2);
  add_clone("/baseobs/armours/chainmail",1);
  add_clone("/baseobs/armours/great_helm",1);
  set_alignment(200);
  set_align(100);
      
}


void set_owner(object protegido)
{
  caster = protegido;
}

int unarmed_attack(object target,object me)
{
      object *att;
      att=(object *)me->query_attacker_list();
      monster::unarmed_attack(att[random(sizeof(att))],me);
      monster::unarmed_attack(att[random(sizeof(att))],me);
}

valid_attack()
{
return([
   "knee"  :({AN+" golpea a "+DN+" en un brazo dejandolo blanco, sin vida.\n",
           "golpeas a "+DN+" en un brazo dejandolo blanco, sin vida.\n",
            AN+" te golpea en un brazo, dejandotelo insensible, como sin vida.\n"}),
   "punch"  :({AN+" atraviesa "+DN+" con su brazo etereo.\n",
            "atraviesas "+DN+" con tu brazo.\n",
             AN+" te atraviesa el pecho con su brazo etereo sintiendo que parte de tu vida se va.\n"}),
   "kick"  :({AN+" golpea a "+DN+" en una pierna.\n",
            "golpeas a "+DN+" en una pierna.\n",
            AN+" te golpea en una pierna dejandotela insensible.\n"})]);
}                                        
                                                                                                
void init()
{
  ::init();
  set_heart_beat(1);
}
int set_seguir(int i)  { return seguir=i; }
int set_proteger(int i){ return proteger=i; }
int query_seguir()     { return seguir; }
int query_proteger()   { return proteger; }




void heart_beat()
{
  ::heart_beat();
}
