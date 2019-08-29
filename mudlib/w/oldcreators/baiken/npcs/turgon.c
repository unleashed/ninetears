// Oneex 12-1-98
// Trugoncito, vigilante del guild de los guerreros drow.	

#include "/d/oficios/guerreros/drowwarrior/path.h"
inherit "/obj/monster";

void event_enter(object ob, string message)
{
   if(ob->is_player() && ob->query_race_name() != "Drow" && !ob->query_death())
      TO->atacar(ob);   
   
}


void event_fight_in_progress(object ob1, object ob2)
{
  if(ob1->query_name() == "turgon")
     call_out("atacar",1, ob2);
  if(ob2->query_name() == "turgon")
     call_out("atacar",1, ob1);
  ::event_fight_in_progress(ob1,ob2);
}

int ataque = 0;
void atacar(object quien)
{
   object ob, *obs;
   int i, j;

   if (ataque == 0)
   {
     do_command("'Ahora moriras por tu osadia.");
     tell_room(environment(TO),"De pronto unos Guardias Drow surgen de la "
     "nada mediante un movimiento rapido, dispuestos a proteger a Turgon.\n\n");
  
     for(i=0;i<3;i++)
     {
       ob = new("/d/oficios/guerreros/drowwarrior/npcs/guardia.c");
       ob->move(environment(TO));
       obs=find_match("all", environment(TO));
       
       for(j=0;j<sizeof(obs);j++)
       {
          if(obs[j]->query_name() != "guardia" && 
             obs[j]->query_name() != "turgon")
                ob->attack_ob(obs[j]);
       }
     }
     ataque=1;
    }
   attack_ob(quien);
}

void setup()
{
   set_name("turgon");
   set_short("turgon");
   set_al(10000);
   set_gender(1);
   set_main_plural("Turgones");
   add_alias("guerrero");
   add_alias("caballero");
   add_plural("guerreros");
   add_alias("drow");
   set_race("Drow");
   set_level(70+random(10));
   set_max_hp(1220+random(300)+random(200));
   set_max_gp(500);
   set_gp(query_max_gp());
   set_guild("warriors/drowwarrior");
   set_guild_ob("/std/guilds/warriors/drowwarrior");
   set_thac0(5+random(5));
   set_wimpy(0);
   set_random_stats(16, 20);
      
   set_str(28); /* 28 == 18/00 */
   set_dex(20);
   set_cha(19);
/* Prohibidos los set_kill_xp
   set_kill_xp(10000);
*/
   
   set_long("Turgon, el capitan de los guerreros drow. Su nombre es temido "
            "en todas las regiones, su habilidad en las artes de la guerra "
            "es conocida por todos, asi como su crueldad con sus enemigos, "
            "si osas enfrentarte con el no esperes ningun tipo de compasion.\n");
   set_aggressive(0);
   
   add_property("fire", 70,);
   add_property("acid", 70);
   add_property("cold", 70);
   add_property("electrical", 70);
   add_property("slashing",35);
   add_property("poison", 30);
   add_property("nodisarm",1);
   add_clone("/d/stonefall/items/city/e_adam",1);
   add_clone("/d/oficios/guerreros/drowwarrior/weapon/venganza", 1);
   add_clone("/d/oficios/guerreros/drowwarrior/armour/cota_stone", 1);
   add_clone("/d/oficios/guerreros/drowwarrior/armour/piwafwi", 1);
   add_clone("/baseobs/armours/great_helm", 1);
   this_object()->init_equip();
}

void init()
{
   add_attack_spell(100, "surge",
   ({"/std/commands/surge","surge", 1}));
   add_attack_spell(100, "slice",
   ({"/std/commands/slice","slice", 1}));
   ::init();
}

void do_death(object att) 
{ 
	object *snarf; 
	int i; 
 
	snarf=query_attacker_list(); 
 
	for(i=0;i<sizeof(snarf);i++) 
	{ 
          write_file("/d/oficios/guerreros/drowwarrior/npcs/matar_turgon.txt", snarf[i]->query_name()+ 
	  " ha matado a Turgon: "+ctime(time())+".\n"); 
	} 
       ::do_death(att); 
}
