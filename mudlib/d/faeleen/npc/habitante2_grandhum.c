#include "../path.h"
inherit "/obj/monster";
 
 void setup() {
       set_name("habitante");
       set_race("human");
       set_short("habitante de Grandhum");
       set_main_plural("habitantes");
       add_plural("habitantes");
       set_level(4+random(4));
       set_wimpy(0);
       set_random_stats(14, 17);
       set_str(17);
       set_dex(17);
       set_gender(2);
       set_long(
      "Habitante de Grandhum."    
     "\n\n Es una habitante del poblade de Grandhum, son muy tranquilos,"
    " su unico hobby son las telas, y los famosos campos con la planta,"
    "unica de estos campos, la Pretyus.\n\n");
       
       adjust_money(random(5),"plata");
       load_chat(30,
          ({
           1,"'Mis hijos viven aqui porque es una ciudad segura.\n",
           1,"'Si no eres pacifico,Vete !\n",
         }));
    add_clone("/baseobs/weapons/daga.c",1);
    add_clone(OBJ+"capa_pretyus.c",1);   
    init_equip();
 } 