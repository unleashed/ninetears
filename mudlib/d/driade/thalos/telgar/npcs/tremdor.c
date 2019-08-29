// Barman 
// Thalos 11-8-97

#include "../path.h"
inherit "/obj/monster";

void setup()
{
      object objeto;
      set_name("Tremdor");
      set_short("Tremdor el barman");
      set_al(250);
      set_gender(1);
      add_alias("tremdor");
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
      set_long("Tremdor es el barman del %^BOLD%^Enano desmembrado%^RESET%^."
         " Este duergar fue antanyo uno de los mejores guerreros de su pueblo,"
         " pero una herida en un combate lo dejo cojo, obligandole a cambiar"
         " de oficio. En uno de sus brazos puedes ver el tatuaje de un enano"
         "desmembrado, posiblemente esa sea la razon del nombre de su taberna" 
         " Esta muy ocupado intentando mantener el orden en el bar. Pero"
         " te servira lo que pidas.\n");
      adjust_money(random(100), "silver");
      set_aggressive(0);
      load_chat(30,         ({
               1, "'Oye tu, hay atras tengo habitaciones si quieres descansar.",
               1, "'Oye tu, que quieres tomar?.",
               1, ":empieza a frotar las jarras de cerveza con un panyo sucisimo.",
               1, ":grita : El que vuelva a decir que mis bebidas estan aguadas"
                  " me lo cargo."
          }));
  add_known_command("bash");
  add_known_command("rabia");
  TO->add_clone("/baseobs/weapons/battle_axe.c",2);
  this_object()->init_equip();
  
}/*setup*/
void init()
{
 ::init();
 add_attack_spell(55,"bash",({"/d/gremios/comandos/bash.c","bash",0}));
 add_attack_spell(70,"rabia",({"std/commands/rabia.c","rabia",1}));
}
void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_keeron", 1, 600);
   return ::attack_by(atacante);
}
