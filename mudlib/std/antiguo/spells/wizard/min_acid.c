
#include "tweaks.h"
inherit SPELLS+"baseres.c";

void create()
{
    SP_NAME = "Minor Acid Resistance";
    chant_message = "mior coroslez rissas";
    TYPE = "acid";
    save_type = "magical";
    GP_COST = 6;
    level = 3;
    base_save = 25;
    base_div = 2;
    base_duration = 50;
    dur_mult = 10;

  ::create(); }