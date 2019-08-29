// Bibliotecario (C) 1999 Aokromes

inherit "/obj/monster";

void setup() {
      set_name("Bibliotecario");
      add_alias("bibliotecario");
      add_alias("bibliotecarios");
      set_short("Bibliotecario");
      set_main_plural("Bibliotecarios");
      set_race("human");
      set_random_stats(12, 18);
      set_level(20);
      set_max_hp(320);
      set_cha(18);
      add_clone("/baseobs/armours/cloak",1);
      set_long("\nEs uno de los multiples bibliotecarios que guardan estos "
         "muros, se rumorea que muchos de ellos saben magia, aunque a penas "
         "la usen\n");
      adjust_money(({random(50), "silver", random(5), "gold"}));
      this_object()->init_equip();
} /* setup() */

void init()
{
   ::init();
   add_attack_spell(50, "lightning bolt",
({"/std/spells/wizard/lightning.c","cast_spell", 0}));
}
