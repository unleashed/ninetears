
#include "tweaks.h"
inherit SPELLS+"baseres.c";

void create()
{
    SP_NAME = "Major Cold Resistance";
    TYPE = "cold";
    save_type = "magical";
    chant_message = "marj frozeus rissas";
  ::create();  }


