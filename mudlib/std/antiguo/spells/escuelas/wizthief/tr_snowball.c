//Pagan's trap   November 11, 1996
#include "tweaks.h"
inherit "/std/spells/trapbase.c";
 
#define LOCKOUT "trap"
void setup()
{
	::setup();
   item = "box";
  set_spell_name("Snowball Swarm Trap");
  set_school("Wizthief");
  set_help_desc("This spell sets a snowball swarm trap. ");
  set_gp_cost(10);
  trap = SPELLS+"snowball.c";
  trap_target = 2; 
}
