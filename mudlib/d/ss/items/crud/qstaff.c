inherit "obj/weapon";

  /* This is the old setup, forget this for now.
   * Keep this ti get the special stuff later. */

  /*

void setup() {
  new_weapon(6000);
  add_immune("blunt");
  set_damage_chance(10);
  add_attack("poke",    0, 60, 30, 10, 0, "blunt");
  add_attack("bash",    0, 60, 40, 0, 0, "blunt");
  set_weap_skill("fighting.combat.melee.blunt");
  set_weight(8);
  set_two_hands(1);
  adjust_money(80, "silver");
  set_name("quarterstaff");
  add_adjective("wooden");
  add_alias("staff");
  set_short("quarterstaff");
 set_main_plural("quarterstaffs");
  add_plural("maces");
  set_long("Just a plain wooden quarterstaff.\n");
  set_read_mess("Broken from a tree by Ducky, the God of Ducks.\n");
  }
  */

  /* This the new setup. It has no real weapon setuo stuff,
   * just object setup such as names. No money either */

  void setup()
    {
    set_base_weapon("quarterstaff");
    set_name("quarterstaff");
    add_adjective("wooden");
    add_alias("staff");
    set_short("quarterstaff");
    set_main_plural("quarterstaffs");
    add_plural("quarterstaffs");
    set_long("Just a plain wooden quarterstaff.\n");
    }
