
#include "tweaks.h"
inherit SPELLS+"areabas.c";

void create()
{
    SP_NAME = "electrical flare";
    GP_COST = 8;
    TYPE = "electrical";
    SIZE_OF_DICE =  5;
    save_type = "electrical";
    maxlevel = 16;
    chant_message = "Majos areos zappeous";
    ::create();
}


