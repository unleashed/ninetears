#include "../path.h"
inherit "/obj/monster";
void setup()
{
set_name("cocinera");
set_short("Sherna, la cocinera");
set_gender(2);
add_alias(({"sherna", "cocinera"}));
set_race("human");
set_wimpy(0);
set_random_stats(15, 17);
set_str(17);
set_level(16+random(3));
set_long("\n Ves a Sherna una gran cocinera que es la"
      " duenya de esta pequenya taberna ,Ella esta manchada de"
      " grasa y esta muy despeinada. \n\n");
adjust_money(random(15), "oro" );
load_chat(45,
        ({
        1,"' Que quiere tomar?",
        1,"' Espero no tener que hecharle a patadas.",
        1," Sherna recoge algunos platos.",
        }));
   add_clone(OBJ+"machete.c",1);
   add_clone(OBJ+"capa_pretyus.c",1);
   init_equip();
   }
