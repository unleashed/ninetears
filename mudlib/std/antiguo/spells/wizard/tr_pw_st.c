//Pagan's trap   November 11, 1996
#include "tweaks.h"
inherit "/std/spells/trapbase.c";
 
#define LOCKOUT "trap"
void setup()
{
	::setup();
   item = "box";
  set_spell_name("Power Word Stun Trap");
  set_school("Wizthief");
  set_help_desc("This spell sets a power word stun trap. ");
  set_gp_cost(10);
  trap = SPELLS+"pw_stun.c";
  trap_target = 1; 
}
