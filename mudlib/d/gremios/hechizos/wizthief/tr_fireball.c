//Pagan's trap   November 11, 1996
#include "tweaks.h"
inherit "/d/gremios/hechizos/trapbase.c";
 
#define LOCKOUT "trap"
void setup()
{
	::setup();
   item = "caja";
  set_spell_name("Trampa de bola de fuego");
  set_school("Wizthief");
  set_help_desc("Este hechizo materializara una trampa de bola de fuego.\n");
  set_gp_cost(10);
  trap  = "/d/gremios/hechizos/wizthief/trampas/fireball.c";
  trap_target = 2; 
}



