// Lord bibliotecario (C) 1999 Aokromes

inherit "/obj/monster";

void setup() {
      set_name("Lord bibliotecario");
      add_alias("lord");
      add_alias("lords");
      add_alias("bibliotecario");
      add_alias("bibliotecarios");
      set_short("Lord bibliotecario");
      set_main_plural("Lords bibliotecarios");
      set_race("human");
      set_al(-100+random(201));
      set_random_stats(14, 18);
      set_level(50);
      set_max_hp(720);
      set_cha(18);
      set_gender(1);
      add_clone("/baseobs/armours/cloak",1);
      set_long("\nSus ojos denotan una gran sabiduria, a saber cuantos ayos "
         "ha vivido, su larga y cuidada barba blanca no es resultado de unas "
         "pocas decadas de vida\n");
      adjust_money(({random(50), "silver", random(5), "gold"}));
      this_object()->init_equip();

      load_chat(10,
         ({
             1, "'He visto grandes y ancestrales batallas crees acaso que soy"
                " joven?",
             1, "'Que has dicho?",
             1, "'El armageddon esta cerca ten cuidado ya que un gran mal "
                  " acecha.",
             1, "'Oculto en las profundidades del castillo un arcano poder se"
                  " oculta, no lo molestes.",
          }));
      load_a_chat(30,
         ({
             1, "'Muere patetico joven.",
             1, "'Conoceras los poderes con los cuales te estas enfrentando.",
             1, "'No sabes quien soy yo verdad?",
          }));

} /* setup() */

void init()
{
   add_attack_spell(100, "lightning bolt",({"/std/spells/wizard/lightning.c","cast_spell", 0}));
   ::init();
   command("protect plateado");    
   command("protect dorado");
}

void attack_by(object atacante)
{
TP->add_timed_property("lord_killer",450);
}
