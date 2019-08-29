// Aokromes 99
inherit "/obj/monster";


void setup()
{
set_name("zombie del general d'krua trabl");
    set_short("zombie del general D'Krua Trabl");
   set_main_plural("zombies de generales");
   add_plural("zombies");
   add_alias("zombie");
   add_alias("guardian");
   add_alias("guardia");
   add_alias("humano");
   set_race_ob("/std/races/undead");
   set_guild_ob("/std/guilds/warriors/antipaladin");
   set_long("Ante ti se trata del zombie, de un antiguo general de Anduar el "
   "cual parece haber pasado por un doloroso proceso que lo ha dejado en un "
   "estado de no-vida. Su aspecto es el de un humanoide bastante deteriorado "
   "con una mirada realmente demoniaca. Sus dedos tienen unas unyas enormes "
   "que hacen de garras y seguramente doleran bastante, a saber quien los ha "
   "traido a este remoto lugar.\n");
   add_property("undead", 1);
   add_property("nodisarm",100);
   set_al(2700);
   set_random_stats(16,21);
   set_cha(18+random(10));
   set_str(34+random(5));
   set_con(35);
   set_level(45+random(5));
    set_gender(1);
   set_aggressive(3);
   add_move_zone("torre");
   add_clone("/baseobs/weapons/long_sword.c",1);
   add_clone("/baseobs/armours/med_shield",1);
   add_clone("/baseobs/armours/chainmail",1);
   ::init_equip();

   load_chat(50, 
   ({ 1, "'En un pasado defendi Anduar ha vida o muerte, pero perdi.",
      2, "'Si no quieres ser lo que soy Corre!!",
      1, "'Ahora Oskuro es mi unico senyor, no los dirigentes de Anduar!",
      1, ":se fija en ti.",
      1, ":te ensenya el filo de su espada.",

   }));
   load_a_chat(60,
   ({ 1, "'OOOaaaaaarrrRRrrkK!!",
      2, "'MMuuuUueeeree!!",
   }));

}
