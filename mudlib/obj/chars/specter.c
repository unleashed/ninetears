#include "path.h"
inherit BASE;

int query_kill_xp() { return 0; }
void setup()
{
	set_name("espectro");
	set_main_plural("espectros");
	set_short("Espectro");
   set_long("Una masa animada de aire procedente de algun incauto explorador fallecido no muy lejos seguramente. \n");
	set_guild("fighter");
	set_level(26);
	set_al(20);
   set_str(25);
   set_int(20);
   set_wis(2);
   set_dex(50);
   set_con(25);
   set_cha(2);
  set_thac0(15);
   set_max_gp(300);
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
   add_attack_spell(30,"slience",({ "/d/gremios/hechizos/wizard/silence.c","cast_spell",1}));
}
