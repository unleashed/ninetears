inherit "/obj/armour";

void setup()  
{ 
//  set_base_armour("leather");
  set_base_armour("cuero");
  set_name("armadura de cuero");
  set_short("armadura de cuero");
  set_main_plural("armaduras de cuero");
  set_long("    La armadura est� hecha de cuero curtido, fuerte y r�gido, con aceite hirviendo "
     "y luego modelada en forma de coraza pectoral con protectores para los hombros.\n");
  add_alias("armadura");
  add_alias("cuero");
  add_plural("armaduras");
  add_plural("cueros");
  set_genero(1);
}
void query_value()
{
return 500;
}
