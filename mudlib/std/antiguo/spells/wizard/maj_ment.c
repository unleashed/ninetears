
#include "tweaks.h"
inherit SPELLS+"baseres.c";

void create()
{
    SP_NAME = "Major Mental Resistance";
    TYPE = "mental";
    save_type = "magical";
    chant_message = "marj psyche rissas";
  ::create();  }



