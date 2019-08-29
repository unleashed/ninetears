/* Gurthang Mayo'01
 * Paris Was here Jun'01
 */
 
inherit "/obj/monster";
#include "/d/oficios/clerigos/shaman/comando/no_muerto.c";
#define QCN query_cap_name()
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
object caster;
int combo(object* chu);
int seguir = 0, proteger = 0;
int hp;
int contador = 0;


void setup()
{

  set_name("targahs");
  set_short("%^BOLD%^RED%^Targahs%^RESET%^ Espiritu del Caos");
  set_main_plural("Varios Espiritus Guerreros");
  add_alias("espiritu");
  add_alias("guerrero");
  add_plural("espiritus");
  add_plural("guerreros");
  set_long("Este es un espiritu sin paragnon, su poder dentro del Reino Demonio "
           "es tan fuerte que su unico enemigo natural son otros elementales "
           "de su misma raza. Su masa, informe y no declarada, es de un rojo "
           "fosforescente y transparente que lo hace claramente fisible "
           "a los ojos de los no iniciados.\nPidele que 'golpealo <quien>' para que "
           "use todo su poder sobre tus enemigos.\n");
  set_random_stats(16,18);
  set_str(30+random(8));
  set_cha(1);
  set_max_hp(1600);
  set_max_gp(1600);
  set_race("Espiritu");
  set_guild("barbarian");
  set_guild_ob("/std/guilds/warriors/barbarian");
  adjust_tmp_damage_bon(10);
  add_clone("/baseobs/weapons/scimitar",2);
  set_level(35+random(20));
  set_alignment(200);
  set_align(400);
}
int query_res() {return 25;}
int query_total_ac() {return -110;}


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
  set_heart_beat(1);
}


void heart_beat()
{
  if(sizeof(TO->query_attacker_list()))
    {
    combo(TO->query_attacker_list());
    }
  ::heart_beat();
}

int combo(object* lala)
{
   object chu = lala[random(sizeof(lala))];
     
     if(!random(3))
       "/std/commands/strike.c"->do_command(chu,this_object());
     if(!random(4))	   
   	   "/std/commands/desarmar.c"->disarm(chu->query_name()); 
   return 1;
}

     

