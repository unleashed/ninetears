inherit "/obj/armour"; 

void setup()  
{ 
  set_base_armour("boots");
  set_name("botas altas");
  set_short("%^BOLD%^%^Botas%^RESET%^ %^BOLD%^WHITE%^Altas%^RESET%^");
  set_main_plural("Pares de %^BOLD%^%^Botas%^RESET%^%^BOLD%^WHITE%^Altas%^RESET%^");
  add_alias("par de botas");
  add_alias("botas");
  add_alias("altas");
  add_plural("pares de botas");
  add_plural("botas");
  add_plural("botas altas");
  set_long("Son un par de botas altas de cuero blanco,con un tac�n de aguja "
  	"de 23 cent�metros, te resulta dif�cil creer que alguien puede andar "
  	"con ellas. Las botas cubren hasta debajo de las rodillas, conjuntar�an "
  	"muy bien con un vestido de cuero blanco.Parece que son botas de "
  	"vestir,pero para quien sepa moverse con ellas le vendr�an muy bien "
  	"para el combate, ya que obsequian movilidad a la persona que las usa. "
  	"Estas botas realzan las piernas de las mujeres que las llevan.\n");
 } 