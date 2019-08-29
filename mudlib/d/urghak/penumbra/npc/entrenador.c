#include "../path.h"

inherit "/obj/civil.c";

void setup() {
  set_name("entrenador");
  set_short("Entrenador");
  add_alias(({"goblin","entrenador","guerrero"}));
  set_main_plural("Entrenadores");
  add_plural(({"goblins","entrenadores","guerreros"}));
  set_long("Entrenador\n\n     "
  	"Uno de los muchos entrenadores que estan aqui a cargo "
  	"de las Tropas de Penumbra.\n");
  set_gender(1);
  set_race("goblin");
  set_level(20);
  set_str(28);
  set_con(16);
  set_dex(18);
  set_wis(10);
  set_int(10);
  set_cha(14);
  set_alineamiento(0,-1);
  set_max_hp(100);
  set_ciudadania("penumbra");
  set_max_gp(100);
  add_clone(OBJ+"largagoblin.c",2);
  add_clone(OBJ+"mallagoblin.c",1);
  set_habilidad("doble arma", 70);
  set_habilidad("filo", 50);
//  set_move_zone("penumbra_sg");
  init_equip();
}

void event_enter(object enterer, string message)
{
  if (!enterer)
    return;
  if (enterer->query_dead())
    return;
  if (enterer->query_alineamiento()[1] == 1)
    this_object()->attack_ob(enterer);
  ::event_enter(enterer,message);
}
