//PUSA inherit "/obj/armour";
inherit "/obj/shield";
int query_shield() { return 1; }

void setup()
{
//  set_base_armour("medium shield");
  set_base_shield("mediano");
  set_name("escudo mediano");
  set_short("escudo mediano");
  set_main_plural("escudos medianos");
  add_alias("escudo");
  add_alias("mediano");
  add_plural("escudos");
  add_plural("medianos");
  set_long("    Es un escudo de tama�o medio en forma de cu�a. Con grabados y dibujos, es el "
     "escudo m�s com�n.\n");
  set_genero(0);
} 
