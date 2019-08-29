inherit "/obj/monster";

#include "path.h"
object ob,ob1;
void setup()
{
    set_name("Wild Man");
    set_long("This is one of the men and women belonging to the tribe of the "
             "%^YELLOW%^Sunshine%^RESET%^, located in the north part of the Savannah.  The members of this "
              "tribe only wear a very thiny part of vegetale armour.  Their "
              "faces are tatooded with the symbol od the tribe, a king under "
              "the morning sunshine.\n");

    set_main_plural("Wild Men");
    add_alias(({"wild","man"}));
    add_plural("men");

    set_level(3);
    set_race("human");

    set_con(20);
    set_gender(1+random(1));

    adjust_money(1,"silver coins");
    
    ob=clone_object("/baseobs/weapons/spear.c");
    ob1=clone_object("/baseobs/armours/leather");
    ob1->move(this_object() );
    ob->move(this_object() );

    init_command("equip");

    load_chat(40, ({
      1,"@wanders around looking for something to eat\n",
      1,"@talks to you in a unknown laguage\n",
      1,"' oghlia ciomio stay tou ?",
      1,"'sepana ganarae debreias contrra lsacse enaglanions",
    }));

    load_a_chat(70,({
      1,"@exclaims:  Hueberree klaim hende !!",
      1,"@yells : Sapanm ex lox nmejorex quex obsrlebado !!!",
      1,"@makes an obscene sign so explicit you can even understand it",
    }));

}
