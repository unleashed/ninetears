
inherit "/std/spells/wizard/shield_spell.c";


void create() {
   SP_NAME      = "Shield of fire";
   GP_COST      = 10;
   SP_LEVEL     = 8;
   TYPE         = "cold";
   SUB_TYPE     = "fire";
   chant_message= "rizzaz armoum protestus";
   ::create();
}
