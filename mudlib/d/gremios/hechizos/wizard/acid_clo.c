
#include "tweaks.h"
inherit SPELLS+"areabas.c";

void create()
{
    SP_NAME = "acid cloud";
    GP_COST = 9;
    TYPE = "acid";
    SIZE_OF_DICE =  6;
    save_type = "acid";
    ADJ_COST;
    maxlevel = 13;
    chant_message = "Majos areos corrosiv";
    ::create();
}


