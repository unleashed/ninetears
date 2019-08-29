// 12/ 98

inherit "/obj/monster";

object ob;

void setup() {
      set_name("armand");
      add_alias("vampiro");
      set_al(-100);
      set_short("Armand");
      set_race("human");
      set_language("common");
      set_level(45+random(5));
      set_max_hp(500);
      set_wimpy(10);
      set_gender(1);
      add_alias("guardian");
      set_random_stats(16, 18);
      set_long("es el amo del castillo. es muy, muy "
         "antiguo y parece muy fuerte.\n");
      adjust_money(5,"gold");
      add_clone("/w/aokromes/tluz",1);
      add_clone("/w/aokromes/espada",2);
      init_equip();
} /* setup() */

void init()
{
   ::init();
   add_attack_spell(85, "lightning bolt", ({"/std/spells/wizard/lightning.c",
   "cast_spell", 0}));
   add_attack_spell(15, "vampiric touch", ({"/std/spells/wizard/vamp_touch.c",
  "cast_spell", 0}));
   add_action ("curioso","mirar");
   add_action ("curioso","look");
}

void heart_beat()
{  
  object *lista;  // Para guardar la lista de atacantes.
  if(TO->query_hp() < 15)
  {
    lista = TO->query_attacker_list();
    ob = clone_object("/d/antenora/drakull/pbaja/armand",1);  // Clonamos el bicho
    ob->move(environment(TO));   // Lo movemos donde esta el objeto Armand actual
    if(sizeof(lista) > 0)        // Hay al menos un atacante
       TO->set_protector(ob);    // Lo ponemos a proteger al actual Armand
  }
    ::heart_beat();
}

int curioso(string str)
{
  TO->attack_by(TP); // El NPC supone que esta siendo atacado por el jugador
  return 1;           // que le mira.
}
