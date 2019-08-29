#include "path.h"
inherit BASE;

int query_kill_xp() { return 0; }
void setup()
{
	set_name("spectre");
	set_main_plural("spectres");
	set_short("Spectre");
   set_long("Nothing more than a moaning patch of air with a bad attitude, this fiend has returned to "+
       "life to visit woe on the living.\n");
	set_guild("fighter");
	set_level(16);
	set_al(20);
   set_str(25);
   set_int(20);
   set_wis(2);
   set_dex(5);
   set_con(25);
   set_cha(2);
  set_thac0(15);
   set_max_gp(200);
   set_gp(200);
  set_kill_xp(0);
   set_aggressive(1);
   add_property("undead",1);
  add_property("magical",100);
  add_property("fire",-10);
  add_property("cold",110);
}
void init()
{
   add_attack_spell(30,"slience",({ "/std/spells/wizard/silence.c","cast_spell",1}));
}
