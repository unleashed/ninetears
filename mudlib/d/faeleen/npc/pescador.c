#include "../path.h"
inherit "/obj/monster";
 
 void setup() {
       set_name("pescador");
       set_race("human");
       set_short("Pescador");
       set_main_plural("pescadores");
       add_plural("pescadores");
       set_level(8+random(5));
       set_wimpy(0);
       set_random_stats(14, 17);
       set_gender(1);
       set_str(17);
       set_dex(17);
       set_long(query_short()+"\n\n Es un pescador grande y fuerte, va vestido con ropa "
	                          "de pesca, y lleva aparejos por todos lados, vemos que lleva "
							  "una gran ca�a, parece que es experto en el tema.\n\n");
       
       adjust_money(random(10),"plata");
       load_chat(30,
          ({
           1,"'Hoy escasea un poco el pescado.\n",
           1,"'Ja Ja Ja, si quiere buen pescado valla a Rongrond, alli tenemos el mejor de la regi�n.\n",
         }));
    add_clone(OBJ+"ca�a.c",1); 
    init_equip();
 } 