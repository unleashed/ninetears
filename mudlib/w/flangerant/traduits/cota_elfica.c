
/* The example armour.. */

inherit "/obj/armour"; 

void setup()  
  { 
  /* THIS HAS TO BE THE FIRST LINE !!!! */
  set_base_armour("cota_elfica");  /* Will set up most of the armour for you */

  set_name("cota elfica");   /* The name is an identifier **/ 

  set_short("Cota elfica");        /* What the players see */ 

  set_main_plural("cotas elficas"); /* What the the players see if there
                                           are more than one of that armour */
  add_alias("cota");
  add_plural("cotas");
  set_long("Una exquisita cota de mallas, cuyas piezas est�n especialmente "
           "enlazadas para dar una mayor protecci�n. El metal empleado para su"
           " construcci�n hace que sea increiblemente ligera.\n");
 
} 
