
#include "path.h"
inherit "/obj/monster";
void setup()
{
    set_name("wizard");
    set_short("Taramath");
    add_alias("wizard");
    add_alias("taramath");
    set_long("Tall, and slender, with flowing copper-colored hair, Taramath seems "
      "very young to wield the kind of power for which she is "
      "renowned. Clothed in a deep blue, figure-hugging gown "
      "she smiles serenely at you as she waits to discover "
      "why you have chosen to disturb her at this time. "
      "\n\n");

    set_level(30+random(20));
    set_random_stats(30,20);
   set_cha(50);
    set_gender(2);
    set_max_gp(300);
    set_gp(300);
    set_max_hp(800);
    set_hp(800,this_object());
    set_al(-250);
    set_ethics(250);
    add_property("poison",75);
    add_property("electrical",75);
    add_property("fire",50);
    add_property("cold",75);
    add_property("acid",50);
    add_property("air",200);
    add_property("magical",100);
   add_clone(WEAPON+"staff.c",1);
   add_clone(ARMOUR+"wiz_cloak.c",1);
    init_equip();
}
void init()
{
    add_attack_spell( 33, "horrid wilting",
      ({"/std/spells/wizard/horrid_wilting.c","cast_spell",0}));
   add_attack_spell(40,"air arrow",
      ({"/std/spells/wizard/air_arrow.c","cast_spell",0}));
    add_attack_spell(20,"fumble",
      ({"/std/spells/wizard/fumble.c","cast_spell",0}));
    add_attack_spell(20,"dispell magic",
      ({"/std/spells/wizard/dispell_magic.c","cast_spell",0}));
    add_attack_spell( 10, "mirror",
      ({"/std/spells/wizard/mirror.c","cast_spell",3}));
    ::init();
}
int do_death()
{
   object scroll = clone_object(OBJ+"fr_arrow_learnable.c");
   scroll->move(this_object());
   ::do_death();
}


