#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("pirate");
    set_short("Pirate");
    set_gender(2);
    set_level(12+random(4));
    set_random_stats(12,4);
    set_long("A scruffy and somewhat depressed looking pirate, she still looks "
    "pretty mean. She has an interesting scar running down her left cheek from "
    "just below the eye to the side of her mouth. She sneers at you. "
    "\n");
   set_al(300);
    load_chat(20, ({
        1,":growls",
        1,"'You don't know a way off this scummy little island, do you ?",
        1,"'Have you got anything to drink ?",
        1,"'Damn that storm that marooned us here."
    })
    );
    load_a_chat(100, ({
        1,"'I've fought better fish than you.",
        1,"Pirate sneers.",
        1,"'I'll boil your bones to make soup little island scum !",
        1,"Pirate spits on you."
    }));
    new("/baseobs/armours/leather")->move(this_object());
   new(OBJ+"boots")->move(this_object());
    new("/baseobs/weapons/short_sword")->move(this_object());
    new(OBJ+"baccy.c")->move(this_object());
    adjust_money(2+random(2),"gold");
   this_object()->init_equip();
}




