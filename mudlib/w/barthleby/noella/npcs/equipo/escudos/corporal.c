//PUSA inherit "/obj/armour";
inherit "/obj/shield";
int query_shield () { return 1; }
void setup()
{
//  set_base_armour("large shield");
  set_base_shield("corporal");
  set_name("escudo corporal");
  set_short("escudo corporal");
  set_long("    Es un gran escudo de metal y madera, que llega de los pies a "
  "la cabeza. Enormemente pesado, otorga una increible protecci�n a su "
  "usuario, en detrimento de su peso y manejabilidad.\n");
  set_main_plural("escudos corporales");
  add_alias("escudo");
  add_alias("corporal");
  add_plural("escudos");
  add_plural("corporales");
  set_genero(0);
} 
