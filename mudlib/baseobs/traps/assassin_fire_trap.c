#include "path.h"
inherit "/baseobs/traps/atrap.c";
void setup()
{
   ::setup();
   set_short("unarmed fire trap");
   add_alias("fire trap");
   mytrap = TRAP+"firetrap";
}
