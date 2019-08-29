#include "../path.h"
inherit "/obj/monster";
 
 void setup() {
       set_name("habitante");
       set_race("human");
       set_short("habitante de Grandhum");
       set_main_plural("habitantes");
       add_plural("habitantes");
       set_level(8+random(5));
       set_wimpy(0);
       set_random_stats(14, 17);
       set_gender(1);
       set_str(17);
       set_dex(17);
       set_long(
        "Habitante de Grandhum."   
       "\n\n Es un habitante del poblade de Grandhum, son muy tranquilos,"
    " su unico hobby son las telas, y los famosos campos con la planta,"
    "unica de estos campos, la Pretyus.\n\n");
       
       adjust_money(random(3),"plata");
       load_chat(30,
          ({
           1,"'Grandhum es muy tranquilo,te lo aconsejo para vivir.\n",
           1,"'No me gustan las guerras,me gustan las telas..\n",
         }));
    add_clone("/baseobs/weapons/daga.c",1);
    add_clone(OBJ+"capa_pretyus",1); 
    init_equip();
 } 