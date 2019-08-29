//Pagan's trap   November 11, 1996
#include "tweaks.h"
inherit "/d/gremios/hechizos/trapbase.c";
 
#define LOCKOUT "trap"
void setup()
{
	::setup();
   item = "caja";
  set_spell_name("Trampa de Granizo");
  set_school("Wizthief");
  set_help_desc("Este hechizo materializa una trampa de granizo.\n");
  set_gp_cost(10);
  trap  = "/d/gremios/hechizos/wizthief/trampas/snowball.c";
  trap_target = 2; 
}
