#include "path.h"

inherit BASE;
int query_kill_xp() { return 0; }
void setup()
{
	set_name("lich");
	set_main_plural("liches");
	set_short("Liche");
   add_alias("liche");
   set_long("You can see nothing but a dark cloak like area with glowing eyes that follow you as you move.\n");
	set_guild("wizard");
	set_level(15);
	set_al(200);
   set_str(10);
   set_int(19);
   set_wis(2);
   set_dex(15);
   set_con(25);
   set_cha(2);
   set_aggressive(1);
  set_thac0(15);
  set_kill_xp(0);
   set_max_gp(100);
   set_gp(100);
  add_property("magical",100);
  add_property("fire",-10);
  add_property("cold",110);
   add_property("undead",5);
}
void init()
{
   add_attack_spell(30,"stinking cloud",({ "/std/spells/wizard/scloud.c","cast_spell",1}));
   add_attack_spell(50,"fumble",({ "/std/spells/wizard/fumble.c","cast_spell",1 }));
   ::init();
}
