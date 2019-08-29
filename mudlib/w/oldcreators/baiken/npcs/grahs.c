/* Gurthang Mayo'01
 * Lvls Reducidos.... sino es mu power. Paris Jun'01
 */
 
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
        tell_room(ENV(TO),"Grahs "+caster->QCN+" se mueve en "
                          "pos de su Amo.\n", caster);
        tell_object(caster,"Grahs llega a tu lado para ayudarte "
                           "en todo cuanto necesites.\n");
        contador = 0;
    }
  contador ++;
  call_out("mueve",2);
}
*/

void setup()
{
  set_name("grahs");
  set_short("Grahs Espiritu Guerrero");
  set_main_plural("Varios Espiritus Guerreros");
  add_alias("espiritu");
  add_alias("guerrero");
  add_plural("espiritus");
  add_plural("guerreros");
  set_long("Una figura inmaterial, translucida, que aturde solo de mirarla. Grahs fue "
	"antanyo uno de los guerreros orcos mas salvajes que hubo. Se dice que en su lucha "
	"entraba desarmado y era capaz de vencer a cualquiera desarmado.\n");
  set_level(10);
  set_random_stats(16,18);
  set_str(20+random(8));
  set_cha(random(3));
  set_max_hp(130);
  set_max_gp(300);
  set_race("Orco");
   set_guild("fighter");
  set_guild_ob("/std/guilds/warriors/fighter");
  adjust_tmp_damage_bon(6);
  set_heart_beat(1);      
  set_alignment(150);
  set_align(150);
   set_thac0(-120);
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
}

int query_total_thac0() {return -150;}
int set_seguir(int i)  { return seguir=i; }
int set_proteger(int i){ return proteger=i; }
int query_seguir()     { return seguir; }
int query_proteger()   { return proteger; }
object query_owner()   { return caster; }
int query_contador()   { return contador; }


int do_death(object ob, object * obs)
{
/*
  if (ob == caster)
    caster->ATP("BICHO_MATADO", 1, 1000000);
  else
    caster->add_timed_property("BICHOSACAO",1,70+random(TO->query_level()));
*/
  return ::do_death(ob,obs);
}


void heart_beat()
{
  ::heart_beat();
}

