inherit "/obj/weapon";

void setup()
{
//  set_base_weapon("dirk");
  set_base_weapon("estilete");
  set_name("punyal");
  set_short("pu�al");
  add_alias("pu�al");
  set_long("    Es un arma parecida a una peque�a daga, pero con forma un poco "
     "distinta, aunque del mismo peso. Utilizada habitualmente "
     "para apu�alar.\n");
  set_main_plural("pu�ales");
  add_plural("punyales"); // parece que sino no funciona
  add_plural("pu�ales")
  set_genero(0);
}
