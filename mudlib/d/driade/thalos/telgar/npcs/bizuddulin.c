// Barman 
// Thalos 11-8-97

#include "../path.h"
inherit "/obj/monster";

void setup()
{
      object objeto;
      set_name("bizuddulin");
      set_short("Bizuddulin el barman");
      set_al(250);
      set_gender(1);
      add_alias("barman");
      add_alias("duergar");
      set_race_ob("/std/races/duergar");
      set_wimpy(0);
      set_random_stats(15, 19);
      set_str(25);
      set_dex(18);
      set_con(18); 
      set_cha(15+random(3));
      set_level(30+random(10));
      set_long("Bizuddulin es el barman del %^BOLD%^Duergar Feliz%^RESET%^."
         " Este duergar heredo la taberna de su padre Dulin, asi que desde"
         " muy pequenyo ha estado aconstumbrado a tratar con los clientes y"
         " los borrachos que visitaban la taberna"
         "Si quieres tomar algo no tienes mas que decirselo y te atendera.\n");
      adjust_money(random(100), "silver");
      set_aggressive(0);
      load_chat(30,         ({
               1, "'Oye tu, que quieres tomar?.",
               1, "'Oye tu, si no quieres nada vete de aqui.",
               1, ":empieza a frotar los vasos con un panyo sucisimo.",
               1, ":grita : El que vuelva a decir que mis comida esta rancia"
                  " me lo cargo."
          }));
  TO->add_clone("/baseobs/weapons/battle_axe.c",2);
  this_object()->init_equip();
  
}/*setup*/
void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keeron", 1, 600);
   return ::attack_by(atacante);
}
