#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("pirata");
    set_short("Pirata");
    set_gender(2);
    set_level(12+random(4));
    set_random_stats(12,4);
    set_long("Una mujer pirata con aire ausente, se mueve con aire desgarbado "
    "y muy poco femenino. Una interesante cicatriz le corre desde la base "
    "del cuello hasta la comisura de la boca pasando cerca de la oreja. Te mira "
    "sin interes."
    "\n");
   set_al(300);
    load_chat(20, ({
        1,":murmura para si.",
        1,"'Sabes alguna manera de escapar de esta odiosa isla ?",
        1,"'Tienes por ahi algo de beber ?",
        1,"'Maldita sea la tormenta que nos arrojo a esta isla."
    })
    );
    load_a_chat(100, ({
        1,"'Bah! los peces luchan mejor que tu.",
        1,"Pirata te desprecia.",
        1,"'Voy a moler tus huesos para hacerme un caldito!",
        1,"Pirata te escupe."
    }));
    new("/baseobs/armours/leather")->move(this_object());
   new(OBJ+"boots")->move(this_object());
    new("/baseobs/weapons/short_sword")->move(this_object());
    new(OBJ+"baccy.c")->move(this_object());
    adjust_money(2+random(2),"gold");
   this_object()->init_equip();
}




