// Aokromes 99
inherit "/obj/monster";


void setup()
{
set_name("zombie");
   set_short("zombie de guardian de Anduar");
   set_main_plural("zombies de guardianes de Anduar");
   add_plural("zombies");
   add_alias("zombie");
   add_alias("guardian");
   add_alias("guardia");
   add_alias("humano");
   set_race_ob("/std/races/undead");
   set_guild_ob("/std/guilds/warriors/antipaladin");
   set_long("Ante ti tienes una criatura realmente espantosa. Se trata de "
   "un alto y fuerte zombie, que parece que en pasado fue un guardian de la "
   "ciudad de Anduar. Su aspecto es el de un humanoide bastante deteriorado "
   "con una mirada realmente demoniaca. Sus dedos tienen unas unyas enormes "
   "que hacen de garras y seguramente doleran bastante, a saber quien los ha "
   "traido a este remoto lugar.\n");
   add_property("undead", 1);
   set_al(2700);
   set_random_stats(16,21);
   set_cha(8+random(10));
   set_str(34+random(5));
   set_con(25);
   set_level(40+random(5));
   set_gender(1+random(2));
   set_aggressive(3);
   add_move_zone("torre");
add_clone("/baseobs/weapons/long_sword.c",1);
   add_clone("/baseobs/armours/med_shield",1);
   add_clone("/baseobs/armours/chainmail",1);
   ::init_equip();

   load_chat(50, 
   ({ 1, "'Ourk, queeyey, haacceeeiiihsh, aaquuuiii?",
      2, "'FFooueeeerraaa, dee aaquuii!!",
      1, "'Oyeeeee, tuuuuu! Maaasss vaaaaleee queeee reespeetees laaa leeeey!",
      1, ":se fija en ti.",
      1, ":te ensenya el filo de su espada.",
      1, "'Oyeeeee, tuuuu nooo eeeraaas eeel quuueee roooobooo laaa "
         "seeemaaanaaa paaasaaadaaa?",

   }));
   load_a_chat(60,
   ({ 1, "'OOOaaaaaarrrRRrrkK!!",
      2, "'MMuuuUueeeree!!",
   }));

}
