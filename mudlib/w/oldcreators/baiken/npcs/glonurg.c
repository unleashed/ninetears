// Glonurg. Guild Master de los Barbaros
// Paris Feb'99

int combo(object* chu);
inherit "/obj/monster";

void setup()
{
   set_name("glonurg");
   set_short("Glonurg OjoTuerto");
   set_main_plural("hermanos de Glonurg");
   
   add_plural("guerreros");
   add_plural("orcos");
   add_plural("hermanos");
   
   set_guild_ob("/std/guilds/warriors/barbarian");
   set_gender(1);

   set_str(29); /* 28 == 18/00 */
   set_cha(20);
   set_con(18);
   set_dex(17);
   set_int(10);
   set_wis(9);
   
   
   set_long("Reconocido como el mas Salvaje de todos los orcos que jamas se han "
            "visto en los reinos Glonurg sirvio a las ordenes del Senyor de Golthur "
            "durante sus mas gloriosas campanyas y, aun a pesar de ser un orco de "
            "rango inferior, llego al rango de Capitan. Ahora sirve a su senyor "
            "entrenando a los Orcos de los gloriosos Ejercitos de Golthur Orod.\n");
            
   add_clone("/baseobs/weapons/scimitar.c",2);
   add_clone("/d/oficios/guerreros/barbaros/items/cadena",1);

   this_object()->init_equip();
   set_level(71);
   set_max_hp(1200);
   set_max_gp(300+random(200));
   set_gp(300);
    set_align(230);
   adjust_tmp_damage_bon(7);
   
   add_property("magical",100);
   add_property("air",70);
   add_property("fire",70);
   add_property("acid",70);
   add_property("cold",70);
   add_property("electrical",70);
   do_command("guild on");
}

void init()
{
   //add_attack_spell(40, "berserk", ({"/std/commands/strike","strike", 0}));
   set_heart_beat(1);
   ::init();
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
 "/std/commands/strike"->do_command(chu,TO);
 return 1;
}
void attack_by(object mec)
{
  if(!random(6))
   do_command("guild @[%^RED%^Ojo%^BLUE%^Tuerto%^RESET%^]: "+mec->query_cap_name()+" esta atacando nuestro guild!!");
  ::attack_by(mec);
}
         

int query_res(){ return 45; } 
