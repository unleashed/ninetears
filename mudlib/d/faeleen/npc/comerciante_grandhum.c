#include "../path.h" 
inherit "/obj/monster";
 
 void setup() {
       set_name("comerciante");
       set_race("human");
       set_short("comerciante de Grandhum");
       set_main_plural("comerciantes");
       add_plural("comerciantes");
       set_level(8+random(5));
       set_wimpy(0);
       set_random_stats(14, 15);
       set_gender(1);
              set_long(
          "Comerciante de Grandhum."
    "\n\n Es un antiguo vendedor de armas, pero se ha arruinado, ya es muy viejo"
    "\n y la edad le esta traicionando en esta vida, te mira a los ojos"
     " como pidiendote ayuda.\n\n");
       
       adjust_money(random(9),"plata");
       load_chat(30,
          ({
           1,"'Me he arruinado, necesito ayuda.\n",
            }));
    add_clone(OBJ+"daga_afilada.c",1);
    add_clone("/baseobs/armours/helmet.c",1);
    add_clone("/baseobs/armours/leather.c",1);  
init_equip();
 } 