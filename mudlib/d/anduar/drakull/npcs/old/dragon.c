inherit "/baseobs/monsters/dragon.c";

void setup() {

  set_name("boris, el gran dragon verde");
  add_alias("dragon");
  set_max_hp(2500);
  set_age(12);
  set_color("green");
  create_dragon();
  set_breath_type("magical");
  set_breath_damage(250);
  set_breath_chance(50);
  set_breath_mess("\nEl dragon abre la boca y una gigantesca llamarada te cubre "
	"completamente!!\n\n");
  set_target_mess("\nTus ropas arden bajo la llarada magica\n\n");
  set_short("boris el dragon");
  set_long("\nEs un gran dragon verde, tan alto como una montanya, sus garras "
	"parecen ser capaces de estropear la mejor de las armaduras, sus ojos "
        "te miran con un odio indescriptible, tal vez.\n\n"); 
  add_property("redundant", 1);
}
