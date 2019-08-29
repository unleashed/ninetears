
#include "tweaks.h"
inherit SPELLS+"bas_arow.c";

void create()
{
    SP_NAME = "Frost Arrow";
    GP_COST = 6;
    SPELLTYPE  = "offensive";
    TYPE = "cold";
    save_type = "cold";
    LEVELS_PER_ARROW = 1;
    LEVELS_PER_BONUS = 5;
    SIZE_OF_DICE = 4;
    ::create();
}



