//El yelmo del se�or de la guerra, por Karn-Daragh

inherit "/obj/armour"; 

void setup()  
{ 
 	set_base_armour("yelmo_grande");
	set_name("yelmo del guerrero");
	set_short("%^BOLD%^Yelmo del %^BLACK%^Guerrero%^RESET%^");  
	set_long("	Un magn�fico yelmo que cubre toda la cabeza. Hecho de un poderoso "
	         "y resistente aliaje, proporciona a su portador una defensa incomparable, y"
	         " la bendici�n de Karn-Daragh otorga adem�s proteccion contra los viles trucos"
	         " m�gicos, que no son dignos de emplearse en las batallas de honor. La parte "
	         "delantera es de un color gris claro y tiene forma de calavera, de formas angulosas"
	         ", la parte posterior es negra y completamente lisa, y en la parte superior dos"
	         " enormes cuernos de marfil culminan el aterrador objeto.\n");
	add_alias("yelmo");
	add_alias("guerrero");
  	set_main_plural("%^BOLD%^Yelmos del %^BLACK%^Guerrero%^RESET%^"); 
  	add_plural("yelmos del guerrero");
  	add_plural("yelmos");
  	add_plural("guerreros");
 	set_enchant(5);
 	add_timed_property("acid",100,999999999999999999);
 	add_timed_property("air",100,999999999999999999);
 	add_timed_property("fire",100,999999999999999999);
 	add_timed_property("disease",100,999999999999999999);
 	add_timed_property("poison",100,999999999999999999);
 	add_timed_property("electrical",100,999999999999999999);
 	add_timed_property("death",100,999999999999999999);
  	add_timed_property("stone",100,999999999999999999);
  	add_timed_property("cold",100,999999999999999999);
  	add_timed_property("death",100,999999999999999999);
  	add_timed_property("magic",100,999999999999999999);
  	add_timed_property("psionic",100,999999999999999999);
  	add_timed_property("missil",100,999999999999999999);
  	add_timed_property("water",100,999999999999999999);
  	add_timed_property("str",10,9999); 	
  	add_property("no_steal",1);
  	add_timed_property("messon","La ansia de Sangre te domina al ponerte tu yelmo.\n",9999);
        add_timed_property("messoff","Te sientes debil y torpe al quitarte tu yelmo.\n",9999);
  	reset_drop();
}