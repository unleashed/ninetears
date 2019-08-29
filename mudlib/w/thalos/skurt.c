inherit "/obj/monster";

void setup() {
     set_name("skurt");
     set_race("goblin");
     set_guild("warriors/warrior.c");
     set_gender("male");
     set_random_stats(14, 19);
     set_level(25+random(8));
     set_short("Skurt");
     set_long("\nEs Skurt, el mayordomo de Thalos, si necesitas cualquier "
               "cosa mientras esperas a su senyor no tienes, mas que"
               "pedirselo, peor no le pidas tonterias o probaras su furia.\n");
     adjust_money(random(15), "platinum");
     set_aggressive(0);
          load_chat(30,
         ({
               1, "'Deseais alguna cosa, senyor?",
               1, ":mira disimuladamente que haces.",
               1, ":te mira con desconfianza.",
               1, ":no creo que mi amo tarde mucho en atenderle,senyor.",
               1, "'Puedo ayudaros en algo, senyor.",
          }));
      
      add_clone("/baseobs/weapons/scimitar",2);
      add_clone("/baseobs/armours/helmet",1);
      add_clone("/baseobs/armours/fullplate",1);
      ::init_equip();
           
}/*setup*/


void attack_by(object atacante)
{
      return ::attack_by(atacante);
}
