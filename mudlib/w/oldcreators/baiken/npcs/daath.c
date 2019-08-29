// Dimmak, sep 99, Aokromes Abril 2001
inherit "/obj/monster";
void setup()
{
  set_name("daath");
  add_alias("antipaladin");
  set_short("Daath");
  set_long("Uno de los primeros seguidores de Tarhilon y Nuggler, en la lucha "
  "por imponer en el mundo la fe en Oskuro. Sus anyos de experiencia le hacen "
  "un enemigo terrible, aunque por su rostro demacrado, parece que no esta en "
  "sus mejores anyos. No compartio el afan destructor de Tarhilon, ni el de "
  "poder de Nuggler, lo cual le relego a un segundo plano a los ojos de su "
  "dios, Oskuro. Pero aun asi, domina grandes poderes, y deberias tener "
  "cuidado al enfrentarte con el.\n");
  set_main_plural("Personas parecidas a Daath");
  set_race("human");
  set_race_ob("/std/races/human");
  set_str(28); // 18/00
  set_dex(20);
  set_con(20);
  set_int(20+random(21));
  set_wis(20+random(21)); // Para ke se salve de las punyaladas
  set_cha(20+random(21));
  set_language("common");
  set_gender(1);
  set_aggressive(0);
  set_alignment(500);
  set_wimpy(0);
  set_guild_ob("/std/guilds/warriors/antipaladin");
  set_level(35+roll(3,11));
  set_max_hp(query_level()*query_con());
  set_gp(query_max_gp());
  adjust_money(random(query_level())+1,"platinum");
  adjust_tmp_damage_bon(1+random(query_level()/4)); // Lo matan TODOS... 
  add_property("nodisarm",1);
  add_property("no_pobredumbre",1);
  add_clone("/baseobs/weapons/bastard_sword.c",1);
  add_clone("/baseobs/armours/fullplate.c",1);
  add_clone("/baseobs/armours/great_helm.c",1);
  add_clone("/baseobs/armours/large_shield.c",1);
  init_equip();
}
 
void init()
{
   add_attack_spell(33+roll(3,11),"charge",({"/std/commands/charge","charge",1}));
    add_attack_spell(33+roll(3,11),"disarm",({"/std/commands/desarmar","disarm",1}));
/*
   add_attack_spell(90,"plegaria",({"/std/commands/prayer.c","cast_spell",3}));
   add_attack_spell(90,"bendicion",({"/std/commands/bless.c","cast_spell",3}));
*/
   ::init();
}
 
int query_res(){ return 33+roll(3,11);}
void event_enter(object ob, string mess)
{
if (TP->query_property("bando") !=2 || TP->query_property("renegado") == 1)
   {
     do_command("say Por la gloria de Oskuro!! moriras!!!!!!");
     this_object()->attack_ob(ob);       
   }
   else
   {
    if (TP->query_guild_name() == "Antipaladin")
    {
    do_command("say Bienvenido al campo de batalla senyor.");
    }
 }
 ::event_enter(ob, mess);
}
