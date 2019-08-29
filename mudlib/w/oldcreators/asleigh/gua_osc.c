inherit "/obj/armour"; 

void setup()  
{ 
  set_base_armour("glove");
  set_name("guantes oscuros");
  set_short("Guantes %^BOLD%^BLACK%^Oscuros%^RESET%^");
  set_main_plural("Guantes %^BOLD%^BLACK%^Oscuros%^%^RESET%^");
  set_long("Son un par de guantes negros que se ajustan perfectamente a tu mano, "
	  "parecen que se realizaron para un robo, seguramente los ladrones utilizan "
	  "guantes parecidos, dan una perfecta movilidad a la mano y a la mu�eca "
	  "pudiendo realizar numerosos trucos con ellos, podr�an pasar perfectamente "
	  "por unos elegantes guantes de vestir, la piel de la que estan hechos es "
	  "muy suave.Son muy c�modos.\n");
  add_alias("oscuro");
  add_alias("guantes");
  add_plural("guantes");
  add_plural("oscuros");
} 
