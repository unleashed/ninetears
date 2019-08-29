#include "../path.h"

inherit "/obj/civil";

void setup()
{
  set_level(8+random(4));
  switch(random(8)) {
    case 0:
      set_name("ladron goblin");
      set_short("Ladron goblin");
      add_alias(({"ladron","goblin"}));
      set_main_plural("Ladrones goblins");
      add_plural(({"ladrones","goblins"}));
      set_race("goblin");
      set_long("     Un escurridizo aprendiz de las sombras, que "
      "busca incesantemente cualquier bolsillo debil que asaltar, "
      "o cualquier espalda en la que hundir su daga.\n");
       add_clone(OBJ+"dagagoblin.c",1);
      add_clone("/baseobs/armours/cape.c",1);
      set_random_stats(10,12);
      set_dex(18);
      adjust_money(random(15),"silver");      
      init_equip();
      break;
    case 1:
      set_name("aprendiz de armas");
      set_race("goblin");
      set_short("Aprendiz de las Armas");
      add_alias(({"goblin","aprendiz","guerrero"}));
      set_main_plural("Aprendices de las Armas");
      add_plural(({"goblins","aprendices","guerreros"}));
      set_long("     Jovenes y energeticos, asi son las generaciones "
      "de goblins entrenadas para el Arte de la Guerra. Comienzan sus "
      "entrenamientos de jovenes en las Barracas de Penumbra, y al "
      "alcanzar cierta capacidad de raciocinio son enviados en misiones "
      "por los tuneles y la superficie.\n");
      set_habilidad("doble arma",60);
      set_habilidad("filo",40);
      add_clone("/baseobs/weapons/broad_sword.c",2);
      set_random_stats(12,15);
      set_str(28);
      init_equip();
      break;
    case 2:
      set_name("anciano");
      set_race("goblin");
      set_short("Anciano");
      add_alias("goblin");
      set_main_plural("Ancianos");
      add_plural("goblins");
      set_long("    Un cansado y marchito goblin que pasea por las "
      "calles de su ciudad. Antiguamente fue un miembro productivo "
      "de la sociedad, pero la edad pasa factura a todos los seres "
      "de Driade, y ahora este ha de andar con cuidado de que ningun "
      "ladronzuelo acabe con su vida por un par de monedas.\n");
      adjust_money(random(10),"copper");
      set_random_stats(5,10);
      break;
    case 3:
      set_name("aprendiz de los espiritus");
      set_race("goblin");
      set_short("Aprendiz de los Espiritus");
      add_alias(({"aprendiz","espiritus","goblin"}));
      set_main_plural("Aprendices de los Espiritus");
      add_plural(({"aprendices","espiritus","goblins"}));
      set_long("     Un joven goblin que acaba de iniciar sus "
      "estudios como Shaman. Pronto estara listo para llevar a "
      "cabo labores de apoyo en ofensivas contra los seres del bien.\n");
      set_random_stats(10,12);
      adjust_money(random(10),"copper");
      add_clone("/baseobs/weapons/twohanded_staff.c",1);
      init_equip();
      set_wis(18);
      break;
    case 4:
    case 5:
      set_name("shaman");
      set_race("goblin");
      set_short("Shaman");
      add_alias(({"shaman","goblin"}));
      set_main_plural("Shamanes");
      add_plural(({"shamanes","goblins"}));
      set_long("     Este goblin ha dedicado toda su vida al "
      "estudio de las artes shamanicas, que estan fuertemente "
      "arraigadas en el modo de vida de los goblins.\n");
      set_random_stats(14,16);
      adjust_money(random(10),"silver");
      add_clone("/baseobs/weapons/twohanded_staff.c",1);      
      init_equip();
      set_wis(21);
      set_level(10+random(4));
      add_attack_spell(40, "columna de fuego", 
      ({"/d/gremios/hechizos/esferas/combate/columna_fuego.c", 
      "cast_spell",0,0}));
      break;
    case 6:
    case 7:
      set_name("guerrero goblin");
      set_race("goblin");
      set_short("Guerrero Goblin");
      add_alias(({"guerrero","goblin"}));
      set_main_plural("Guerreros Goblin");
      add_plural(({"guerreros","goblins"}));
      set_long("     Un guerrero de las filas goblinoides, que "
      "pasa el tiempo matando congeneres en tiempos de paz.\n");
      set_random_stats(14,16);
      adjust_money(random(10),"silver");
      set_habilidad("doble arma",90);
      switch(random(3)) 
      {
        case 2:
          add_clone(OBJ+"largagoblin.c",2);
          break;
        case 1:
          add_clone("/baseobs/weapons/hand_axe.c",2);
          break;
        case 0:
          add_clone("/baseobs/weapons/mace.c",2);      
          break;
      }
      init_equip();
      set_str(28);
      set_level(10+random(4));
      break;
  }
  set_alineamiento(0,-1);
  set_ciudadania("penumbra");
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
