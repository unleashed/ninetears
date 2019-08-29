#include "../path.h"
inherit "/obj/monster";
 
 void setup() {
       set_name("turista");
       set_race("human");
       set_short("Turista");
       set_main_plural("turistas");
       add_plural("turistas");
       set_level(8+random(5));
       set_wimpy(0);
       set_random_stats(14, 17);
       set_gender(1);
       set_str(17);
       set_dex(17);
       set_long(query_short()+"\n\n Vemos a un humano de mediana estatura, es uno de los muchos "
	                          "turistas que vienen a ver las maravillas de las playas de faeleen, "
							  "van vestidos con ropas buenas y bonitas.\n\n");
       
       adjust_money(random(5),"oro");
       load_chat(30,
          ({
           1,"'Que bonito es este lugar.\n",
           1,":se tambalea un poco al pisar mal.\n",
         }));
    add_clone(OBJ+"pantalon.c",1);
	add_clone(OBJ+"camisa.c",1);
    init_equip();
 } 