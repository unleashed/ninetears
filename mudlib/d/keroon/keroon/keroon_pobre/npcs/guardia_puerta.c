//thalos guardias de las puertas de keroon
//Valar estuvo aki trasteando :P
#include "../../../path.h"
// #include "duergar.c" --> Modificado por linea 5
inherit "/obj/guardian.c";  // --> Valar Updated

// Valar Update --> Adaptado las tiradas y lvl del monster + ciudadania
void setup()
{
  set_name("Guardia");
  add_alias("guardia");
  add_alias("guardian");
  set_short("Guardia de la puerta");
  set_long("Este guardia es el encargado de velar por la seguridad de las puertas de la ciudad de Keroon.\n");
  set_random_stats(17,19);
  set_str(19);/*para ajustar la fuerza a tu placer*/
  set_dex(17);/*lo mismo en dex...como ves es set_lo_que_seapara poner lo que a ti te guste.*/
  set_cha(100);
set_level(20+random(5));/*ponedlo depues de los stats..pa ke rule bien si no calcula la vida antes del nivel y puede salir con muy poca.*/

   set_ciudadania("Keroon");

  set_main_plural("guardianes");
  add_alias("guardias");
  
  add_alias("guardianes");
  set_align(0);
  set_gender(1);
  load_chat(100,
            ({
              1,":Limpia sus hachas con gran enfasis.\n",
              1,"'la vida es dura..quieres dejar de sufrir?\n",
              1,"'No queras pelear?, muchacho!!!!\n",
              1,"'Si me atacas, no te dejare salir vivo!!!!\n",
             }));//este  chat lo dice en medio del combate.
  add_known_command("bash");
  add_known_command("rabia");
        add_clone(ITEMSKEROONPOBRE +"hacha_guardia",2);
        add_clone(ITEMSKEROONPOBRE +"armadura_capitan",1);
        add_clone(ITEMSKEROONPOBRE +"yelmo_patrulla.c",1);
        add_clone(ITEMSKEROONPOBRE +"capa_capitan.c",1);
        add_clone(ITEMSKEROONPOBRE +"brazaletes_guardia.c",1);
        init_equip();
  set_aggressive(0);
 
}

//ya sabeis mirad los comandos ke hallan pa probarlos.
void init()
{
 ::init();
 add_attack_spell(55,"bash",({"/d/gremios/comandos/bash.c","bash",0}));
 add_attack_spell(70,"rabia",({"std/commands/rabia.c","rabia",1}));
}
void attack_by(object atacante)
{
   do_command("protect guardias");
   atacante->add_timed_property("guardias_keroon", 1, 600);
   ::attack_by(atacante);
}

