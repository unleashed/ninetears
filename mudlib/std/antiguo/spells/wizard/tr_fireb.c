//Pagan's trap   November 11, 1996
#include "tweaks.h"
inherit "/std/spells/trapbase.c";
 
#define LOCKOUT "trap"
void setup()
{
	::setup();
   item = "box";
  set_spell_name("Confusion Trap");
  set_school("Wizthief");
  set_help_desc("This spell will set a confusion trap. "
     "It's pretty useless, but great fun at parties.");
  set_gp_cost(10);
  trap  = "/std/spells/wizard/fireball.c";
  trap_target = 2; 
}



