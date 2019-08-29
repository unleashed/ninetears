//Modificado para que este "acostumbrado" a hacer el rabia 2
//******************************
// Oneex 12-1-98
// Ishmar copio un pokito, pero solo 1, eh? :)
// A este tipo le vi a meter la armadura de campanya, pero que mientras la
// lleves, te de el bash.
#include "../path.h"
inherit "/obj/monster";
void event_enter(object ob, string mensaje, object donde)
{
   if (ob->query_dead())
   {
      this_object()->do_command("comfort "+ob->query_cap_name());
   }
   else
   {
      write(this_object()->query_cap_name()+" te saluda.\n");
      say(this_object()->query_cap_name()+" saluda a "+
          ob->query_cap_name()+".\n");
   }
   ::event_enter(ob, mensaje, donde);
}
 
void setup()
{
   set_name("raignok");
   set_short("Raignok");
   add_alias("raignok");
   set_gender(1);
   set_main_plural("El gemelo de Raignok que no se parece en nada a el.");
   add_alias("guerrero");
   add_alias("battlerager");
   add_plural("guerreros");
   add_alias("enano");
   set_race("Duergar");
   set_str(29);
   set_con(19);
   set_dex(18);
   set_cha(17);
   set_int(14);
   set_wis(15);
   set_race_ob("/std/races/duergar.c");
   set_level(80+random(15));
   set_max_hp(query_level()*16); //(15=11 por el query_dice+4 por la CON)
   set_gp(query_max_gp());
   set_guild("warriors/rager");
   set_guild_ob("/std/guilds/warriors/rager");
   set_wimpy(0);
      set_alignment(350);
   set_long("Raignok es el capitan de los Battle Ragers. Es un viejo duergar "
   "con una larga y densa barba, que muestra el pasar de los anyos. Fue uno "
   "de los primeros en entrenarse en este gremio, hara ya casi 240 anyos, "
   "cuando aun era un adolescente, y desde entonces, no paro de entrenar y "
   "entrenar, por lo que es muy temido y respetado en todo el continente. Lo "
   "mejor, seria dejarlo tranquilo y no molestarlo.\n");   
   set_aggressive(0);
   
   add_timed_property("fire", 70, 900000000);
   add_timed_property("acid", 70, 900000000);
   add_timed_property("cold", 70, 900000000);
   add_timed_property("electrical", 70, 900000000);
   add_timed_property("magical",70,900000000);
   add_property("nodisarm",1);
   add_clone(ROOMS+"items/yelmo_punzante",1);
   add_clone(ROOMS+"items/guanteletes_punzantes",1);
   add_clone(ROOMS+"items/armadura_punzante",1);
   if(!random(10))
   {
      add_clone(ROOMS+"weapons/hachaoneex_nueva",1);
      set_max_hp(query_max_hp()+roll(5,150));
      adjust_hp(query_max_hp(),TO);
      adjust_tmp_damage_bon(roll(5,7));
   }
   else
   add_clone(ROOMS+"weapons/hacha2manos_2",1);
   add_property("berserkergang", 400);
   init_equip();
}
 
void init()
{
   add_attack_spell(100, "rabia",
  ({"/std/commands/rabia","go_berserk", 1}));
   add_attack_spell(80, "bash",
   ({"/std/commands/bash","bash", 1}));
   ::init();
}
 
void do_death(object att) 
{ 
        object *snarf; 
        int i; 
 
        snarf=query_attacker_list(); 
 
        for(i=0;i<sizeof(snarf);i++) 
        { 
          write_file("/d/oficios/guerreros/battle/bendorf/npcs/matar_raignok.txt", snarf[i]->query_name()+ 
          " ha matado a Raignok: "+ctime(time())+".\n"); 
        } 
       ::do_death(att); 
}
int adjust_gp(int cuanto)
{
   return ::adjust_gp(0);
}
