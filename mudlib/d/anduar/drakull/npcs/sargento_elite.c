// Sargento de la orden plateado (C) 1999 Aokromes
#include "path.h"
inherit "/obj/monster";

void setup() {
      set_name("Sargento de la orden plateado");
      add_alias("sargento");
      add_alias("sargentos");
      add_alias("guardian");
      add_alias("guardianes");
      add_alias("plateado");
      set_genero(1);
      set_short("Sargento plateado");
      set_main_plural("Sargentos plateados");
      set_race("human");
      set_random_stats(16, 18);
      set_level(20);
      set_max_hp(300);
      set_str(38);
      set_cha(18);
      add_clone(OBJETOS+"twohanded_sword.c",1);
      add_clone(OBJETOS+"placa",1);
      add_clone("/baseobs/armours/cloak",1);
      set_long("Un rudo sargento de los que se encargan de dirigir a todos "
        "los soldados que vigilan este increible castillo, sus ojos denotan "
        "un mal humor y la tipica antipatia que caracteriza a estos bruscos "
        "hombres.\n");
      adjust_money(({random(50), "silver", random(10), "gold"}));
      this_object()->init_equip();
} /* setup() */
