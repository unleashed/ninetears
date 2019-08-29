// Soldado de la orden sagrada (C) 1999 Aokromes
#include "path.h"
inherit "/obj/monster";

void setup() {
      set_name("Soldado de la orden sagrada");
      add_alias("soldado");
      add_alias("soldados");
      add_alias("guardian");
      add_alias("guardianes");
      add_alias("sagrada");
      set_genero(1);
      set_short("Soldado de la orden");
      set_main_plural("Soldados de la orden");
      set_race("human");
      set_random_stats(16, 18);
      set_level(20);
      set_max_hp(250);
      set_str(38);
      set_cha(18);
      add_clone(OBJETOS+"twohanded_sword.c",1);
      add_clone(OBJETOS+"placa",1);
      add_clone("/baseobs/armours/cloak",1);
      set_long("Un rudo soldado de la orden sagrada, hombres como este que "
        "se entrena duramente mantienen a diario el orden en este ancestral "
        "castillo para mantenerlo a salvo de los multiples bribones que moran "
        "esta isla.\n");
      adjust_money(({random(50), "silver", random(10), "gold"}));
      this_object()->init_equip();
} /* setup() */
