#include "../path.h"

inherit "/obj/civil";

void setup()
{
  set_name("comerciante duergar");
  set_short("Comerciante duergar");
  add_alias(({"comerciante","duergar"}));
  set_main_plural("Comerciantes duergar");
  add_plural(({"comerciantes","duergars"}));
  set_long("     Un sucio duergar de dientes negros que viene "
  "de su ciudad natal en busca de fortuna y riqueza.\n");
  set_race("duergar");
  set_level(10+random(5));
  set_random_stats(9,18);
  adjust_money(5,"gold");
  set_alineamiento(0,-1);
  add_clone(OBJ+"capaviaje.c",1);
  load_chat(30, ({
     1,"' Hoy es un mal dia para los negocios!",
     1,"' Tengo una mercancia de calidad exquisita.",
     1,"' Compren! Compren!",
  }));
  init_equip();
}
