//.oO JaDe Oo.  Mayo'02
inherit "/obj/armour"; 

void setup()  
  { 
   set_base_armour("completa");  
   set_name("ira de vingardtur");    
   set_short("%^BOLD%^%^MAGENTA%^I%^RESET%^%^MAGENTA%^ra %^RESET%^de %^BOLD%^%^BLACK%^
Vingardtur%^RESET%^");      
   add_alias("ira");
   add_alias("vingardtur");
   add_plural("iras");
   set_main_plural("%^BOLD%^%^MAGENTA%^I%^RESET%^%^MAGENTA%^ras %^RESET%^de %^BOLD%^%^BLACK%^
Vingardtur%^RESET%^"); 
   set_long("Ira de Vingardtur.\n"
            "A primera vista dir�as que esta armadura es una aut�ntica obra de arte, de color "
   	    "negro brillante con numerosos detalles de orfebreria, ribetes de mithril y peque�as "
   	    "gemas incrustadas finamente, hacen de esta armadura una pieza �nica. Pero no s�lo es "
   	    "bella, los materiales con los que ha sido forjada hacen que sea eficaz y a la vez "
   	    "liviana, permitiendo al portador total libertad de movimientos.\n");
   set_enchant(3);
 
} 
