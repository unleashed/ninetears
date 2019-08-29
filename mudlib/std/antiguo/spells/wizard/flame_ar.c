
#include "tweaks.h"
inherit SPELLS+"bas_arow.c";

void create()
{
    SP_NAME = "Flame Arrow";
    GP_COST = 6;
    SPELLTYPE  = "offensive";
    TYPE = "fire";
    save_type = "fire";
    LEVELS_PER_ARROW = 1;
    LEVELS_PER_BONUS = 5;
    SIZE_OF_DICE = 4;
    ::create();
}


