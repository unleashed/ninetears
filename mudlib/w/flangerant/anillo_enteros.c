inherit "/obj/armour"; 

void setup()  
  { 
   
   set_base_armour("anillo"); 
   set_name("chiste_malo");    
   set_short("Anillo de los %^CYAN%^enteros%^RESET%^");        
   add_alias("entero");
   add_alias("anillo");
   add_plural("anillos");
   add_plural("enteros");
   set_main_plural("Anillo de los %^CYAN%^enteros%^RESET%^");
   set_long(" Uno de los chistes mas malos que se hayan hecho nunca. "
            "No es uno de los anillos de el se�or de los anillos.\n");
   add_timed_property("electrical",100,900000000);
   set_enchant(50);

 }
 
