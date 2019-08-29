#include "../../path.h"

inherit "obj/monster";

void setup()
{
  set_name("Nosferatu");
  add_alias("no muerto");
  add_alias("nosferatu");  
  add_alias("vampiro");  
  set_short("Nosferatu, el vampiro");
  set_long("Estas delante de un vampiro encargado de velar por la seguridad y paz del cementerio.\n");
  set_random_stats(20,40);
  set_cha(100);
  set_level(40+random(25));
  set_max_hp(1000);
      set_hp(1000);
  set_max_gp(700);
      set_gp(700);
  set_main_plural("nosferatus");
  set_race("undead");
  set_align(0);
  set_gender(1);
  adjust_money(random(50), "platino");
  load_chat(100,
            ({
              1,":se relame sus sanguilonentos colmillos.\n",
              1,"'Nunca llegaras ante el amo.. aqui acaba tu vida.\n",
              1,"'Abandona toda esperanza y unete a nosotros!!!!\n",
              1,"'Tal vez si eres suficientemente fuerte el amo te despertara, cuando acabe contigo!!!!\n",
            }));
  add_known_command("slice");
  add_known_command("surge");
  add_attack_spell(20, "toque vampirico",({"/d/gremios/hechizos/mago/toque_vampirico", "cast_spell",1,0}));
  TO->add_clone("/baseobs/weapons/bastard_sword",2);
  this_object()->init_equip();
  set_aggressive(1);
  
}


void event_enter()
{
   say(TO->query_name()+" dice: Por mi amo y tu dulce sangre!!!! Por fin un reto decente!!! Muere!!!.\n");
   TP->attack_by(TO);
}



void init()
{
 ::init();
 add_attack_spell(55,"surge",({"/d/gremios/comandos/surge.c","surge",0}));
 add_attack_spell(70,"slice",({"std/commands/slice.c","slice",1}));
 add_attack_spell(20, "toque_vampirico", ({"/d/gremios/hechizos/wizard/toque_vampirico.c","cast_spell", 2}));

}

