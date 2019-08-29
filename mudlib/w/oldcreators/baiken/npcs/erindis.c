/* Editado por Lummen 25-8-97 */

inherit "/obj/monster";
#include "../../path.h"

int llamado=0;

int dispell()
{
tell_room(ENV(TO),"Erindis traza un arco con su brazo y el aura que le rodeaba desaparece.\n");
TO->add_property("invulnerable_hechizos",0);
llamado=0;
call_out("espejo",2);
return 1;
}
int espejo()
{
if (!TO->query_mirror_spell() && !TO->query_property("invulnerable_hechizos")){
"/std/spells/bard/mirror.c"->cast_spell(TO->query_name(),TO,0);
}
return 1;
}

void heart_beat()
{ 
if (TO->query_property("invulnerable_hechizos") && !llamado)
{
tell_room(ENV(TO),"Erindis pronuncia las palabras: baliis desaferum trus.\n");
llamado=1;
call_out("dispell",2);
}
 ::heart_beat(); 
}

 
void init()
{
add_attack_spell(50,"intoxicate",({"/std/spells/bard/intoxicate.c","cast_spell",0,0}));
add_attack_spell(40,"stun",({"/std/spells/bard/pw_stun.c","cast_spell",1,0}));
add_attack_spell(40,"cono",({"/std/spells/wizard/conecold.c","cast_spell",0}));
 ::init();
}
 // y = objetivo   0: un atacante
 //                1: todos los atacantes
 //                2: all
 //                3: sobre si mismo
 // z = silencio   0: normal
 //                1: modo silencioso



setup()
  {
  set_name("erindis");
  set_short("%^MAGENTA%^Erindis el trobador%^RESET%^");
  add_alias("bardo");
  set_main_plural("%^MAGENTA%^Bardos%^RESET%^");
  add_plural("bardos");
  add_adjective("trobador");
  set_long("Esta sentado en un pequenyo taburete recitando para si mismo "
     "unos versos, que probablemente haya compuesto en algunos de sus viajes "
     "o en alguna de sus muchas aventuras.\n"
     "Esta ante ti uno la persona indicada para proporcionarte "
     "los conocimientos necesarios para ser un bardo, el te ensenyara "
     "aquello que necesitaras saber."
     "\n");
  set_gender(1);
  set_race("human");
  set_random_stats(19,20);
  set_cha(25);
  set_con(18);
  set_str(30);
  set_guild_ob("/std/guilds/rogues/bard");
  set_guild("bard");
  set_level(65);
  set_al(-1000);
  set_thac0(-100);
  adjust_money(random(15)+10,"platinum");
  set_max_hp(roll(query_level(),query_con())+100+random(100));
  set_max_gp(20000);

  add_property("nodisarm",1);
  add_property("no_pobredumbre",1);
add_timed_property("mirror",200,900000000);
  add_timed_property("fire",50,900000000);
  add_timed_property("cold",50,900000000);
  add_timed_property("air",50,900000000);
  add_timed_property("poison",50,900000000);
  add_timed_property("electrical",50,900000000);
  add_timed_property("magical",50,900000000);
  add_timed_property("acid",50,900000000);
  add_timed_property("stone",50,900000000);
  
  add_clone("/d/oficios/bardos/items/espada.c",2);
  add_clone(items+"mcloak.c",1);
  add_clone(items+"leather.c",1);
  add_clone(items+"amuleto_bardos.c",1);
  this_object()->init_equip();
 
} /* setup */
void attack_by(object nano)
{
object *target;
int i;
string str;

str="%^BOLD%^(El Guildmaster)%^RESET%^ Chicos, me ataca "+nano->query_cap_name()+" venid a ayudarme!!";
if (!nano->query_property("Inform_guild_bard")){
"/global/do_chat"->do_channel("bardo",str,"Erindis");   	
nano->add_timed_property("Inform_guild_bard",1,90);
}

if (!TO->query_mirror_spell() && !TO->query_property("invulnerable_hechizos")){
"/std/spells/bard/mirror.c"->cast_spell(TO->query_name(),TO,0);
}
    ::attack_by(nano);

}
void do_death(object ob)
{
string str;

str="%^BOLD%^(El Guildmaster) %^RED%^Agghhh%^RESET%^";
"/global/do_chat"->do_channel("bardo",str,"Erindis");   	
	
ob = TP;
write_file("/d/oficios/bardos/logs/erindis.txt",""+TP->query_cap_name()+" "+ctime(time())+"\n");
return(::do_death());
}
