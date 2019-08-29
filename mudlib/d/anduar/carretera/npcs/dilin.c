#include "path.h"

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("dilin");
      set_short("Dilin Dalin Delen");
      set_al(60);
      set_gender(1);
      add_alias("dilin");
      add_alias("dalin");
      add_alias("delen");
      set_race_ob("/std/races/halfling");
      set_guild_ob("/std/guilds/bribon.c");
      set_wimpy(0);
      set_random_stats(14, 18);
      set_str(18);
      set_con(18);
      set_dex(16);
      set_cha(15);
      set_level(15+random(8));
      set_long("Es Dilin Dalin Delen, el duenyo de este lugar que los humanos "
      "insisten en llamar tienda pero que los halflins conocen como La casa "
      "donde la gente deja todo lo que otra gente pierde.\n");
      adjust_money(random(5), "platinum");
      set_aggressive(0);
      load_chat(30,
         ({
               1, "'Hola amigo, tal vez se te ha perdido algo?",
               1, ":se asegura que sus cerraduras estan bien cerradas.",
               1, ":mira hacia tus bolsillos.",
               1, ":cierra un candado medio abierto.",
               1, "'Buscas algo amigo? tal vez hayas perdido algo.",
          }));
      
      add_clone("/baseobs/weapons/short_sword",1);
      add_clone("/baseobs/armours/leather",1);
      add_clone("/baseobs/armours/helmet",1);
      ::init_equip();
           
}/*setup*/
