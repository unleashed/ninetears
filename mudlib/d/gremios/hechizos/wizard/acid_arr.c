
#include "tweaks.h"
inherit SPELLS+"bas_arow.c";

void create()
{
    SP_NAME = "Acid Arrow";
    GP_COST = 6;
    SPELLTYPE  = "offensive";
    TYPE = "acid";
    save_type = "acid";
    LEVELS_PER_ARROW = 1;
    LEVELS_PER_BONUS = 6;
    SIZE_OF_DICE = 5;

    ::create();
}


