#include "path.h"
inherit BASE;
int query_kill_xp() { return 0; }
void setup()
{
	set_name("wraith");
	set_main_plural("wraiths");
	set_short("Wraith");
   add_alias("wraith");
   set_long("A misty shape reaches out for you, unpleasant memories roil up in your mind as this undead things tries to drag you down.\n");
   set_max_gp(200);
   set_gp(200);
   set_level(10);
	set_guild("cleric");
	set_level(5);
	set_al(20);
   set_str(15);
   set_int(2);
   set_wis(18);
   set_dex(25);
   set_con(25);
   set_cha(2);
  set_thac0(15);
  set_kill_xp(0);
   set_aggressive(1);
   add_property("undead",3);
  add_property("fire",-10);
  add_property("cold",110);
}
void init()
{
   add_attack_spell(30,"cause wounds",({ "/std/spells/cleric/cause_lt.c","cast_spell",1}));
   add_attack_spell(50,"cure wounds",({ "/std/spells/cleric/cure_cr.c","cast_spell",3}));
   ::init();
}
