
#include "tweaks.h"
inherit SPELLS+"baseres.c";

void create()
{
    SP_NAME = "Major Electrical Resistance";
    TYPE = "electrical";
    save_type = "magical";
    chant_message = "marj zappius rissas";
  ::create();  }



