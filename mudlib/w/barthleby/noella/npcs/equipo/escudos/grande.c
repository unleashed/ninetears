//PUSA inherit "/obj/armour";
inherit "/obj/shield";
int query_shield () { return 1; }
void setup()
{
//  set_base_armour("large shield");
  set_base_shield("grande");
  set_name("escudo grande");
  set_short("escudo grande");
  set_long("    Es un gran escudo de metal y madera, que cubre la parte superior "
  "del cuerpo. Bastante pesado, otorga una buena protecci�n a su "
  "usuario aunque no resulta extremadamente manejable.\n");
  set_main_plural("escudos grandes");
  add_alias("escudo");
  add_alias("grande");
  add_plural("escudos");
  add_plural("grandes");
  set_genero(0);
} 
