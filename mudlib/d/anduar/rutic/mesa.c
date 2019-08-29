inherit "/obj/monster";

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
object kender,asesino;
void init()
{
   call_out("kender",0);
   ::init();
}  


int kender() 
{
object *target;
int i;
target = all_inventory(load_object("/d/anduar/rutic/saco9.c"));
 
  for (i=0;i<sizeof(target);i++)
  {   
    if(target[i]->query_npc() && target[i]->query_short()=="kender")  
    { 
    	 TO->attack_ob(target[i]);
    	 kender=target[i];
    }   
  } 
call_out("kender",3);
} 
 
void setup()
  {
  set_name("mesa animada");
  set_short("mesa animada");
  add_alias("mesa");
  set_main_plural("mesas animadas");
  add_plural("mesas");
  add_adjective("animada");
  set_long("Es una mesa de madera que parece tener vida propia.\n");
/*
  set_gender(2);
    set_random_stats(19,20);
  set_cha(7);
  set_str(30+random(10));
  set_guild_ob("/std/guilds/warriors/battles");    //cambiado
  set_al(0);
  set_level(24+random(10));
  set_max_hp(roll(query_level(),query_con()));
  set_max_gp(400);
  set_gp(400);*/
	set_max_hp(80);
} 

valid_attack()

{
  return([
      "knee"  :({AN+" golpea brutalmente con una de sus patas a "+DN+".\n",
                 "Golpeas brutalmente con una de tus patas a "+DN+".\n",
                 AN+" te golpea brutalmente con una de sus patas.\n"}),
      "punch"  :({AN+" carga contra "+DN+" dandole un gran golpe.\n",
                 "Cargas contra "+DN+".\n",
                 AN+" carga contra ti y recibes un gran impacto.\n"}
),
      "kick"  :({AN+" da una tremenda patada a "+DN+".\n",
                 "Das una tremenda patada a "+DN+".\n",
                 AN+" te da una tremenda patada.\n"})]);
}


void do_death(object ob)
{
object *target;
int i;
target = all_inventory(load_object("/d/anduar/rutic/saco9.c"));
 
  for (i=0;i<sizeof(target);i++)
  {   
    if(target[i]->query_npc() && target[i]->query_short()=="kender")  
    { 
target[i]->salvado(asesino);
    }   
  } 
    return(::do_death());
}
void attack_by(object atacante)
{
if (atacante->query_short()!="kender")
	{asesino=atacante;}
::attack_by(atacante);
	
}
