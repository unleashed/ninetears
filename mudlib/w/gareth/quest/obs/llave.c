/*             Gareth 30.01.03
Llave para entrar a la cripta de la quest Khurgar */

inherit "/std/item"; 

void setup()  
{ 
 	set_name("llave oxidada");
	set_short("Llave oxidada");  
	set_long("Una vieja llave, de gran tama�o. El paso del tiempo "
		 "ha ido oxidandola poco a poco.\n");
	add_alias("llave");
	add_alias("oxidada");
  	set_main_plural("llaves oxidadas"); 
  	add_plural("llaves");
  	set_weight(5);
}