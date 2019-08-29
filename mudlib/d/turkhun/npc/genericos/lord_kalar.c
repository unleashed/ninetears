// Lord Kalar tendero de Anduar
// Oneex 27-5-97
#include "/d/turkhun/path.h"

#define TIEMPO 5000
inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("lord kalar");
      set_short("Lord Kalar");
      set_al(60);
      set_gender(1);
      add_alias("kalar");
      add_alias("lord");
      add_alias("human");
      set_race_ob("/std/races/human");
      set_guild_ob("/std/guilds/warriors/fighter.c");
      set_wimpy(0);
      set_random_stats(14, 18);
      set_str(18);
      set_con(18);
      set_dex(16);
      set_cha(15);
      set_level(10+random(8));
      set_long("Es Lord Kalar, el duenyo de la tienda con mas "
               "prestigio de la region. Si quieres algo que se pueda "
               "comprar seguro que el te lo vendera.\n");
      adjust_money(random(5), "platinum");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Deseais comprar o vender algo, senyor?",
               1, ":mira unos pedidos.",
               1, ":te mira con desconfianza.",
               1, ":va hacia el almacen y repone las estanterias.",
               1, "'Puedo ayudaros en algo, senyor.",
          }));
      
      add_clone("/baseobs/weapons/short_sword",1);
      add_clone("/baseobs/armours/leather",1);
      add_clone("/baseobs/armours/helmet",1);
      ::init_equip();
           
}/*setup*/


void attack_by(object atacante)
{
   atacante->add_timed_property("enemigo_turkhun", 1, TIEMPO);
   return ::attack_by(atacante);
}
