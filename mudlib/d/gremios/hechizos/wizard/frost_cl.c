
#include "tweaks.h"
inherit SPELLS+"areabas.c";

void create()
{
    SP_NAME = "frost cloud";
    GP_COST = 6;
    TYPE = "cold";
    SIZE_OF_DICE =  6;
    save_type = "cold";
    ADJ_COST;
    maxlevel = 10;
    chant_message = "Majos areos frozeous";
    ::create();
}


