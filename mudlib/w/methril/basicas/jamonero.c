// Vilat 24.10.2002
// Las armas heredan siempre "/obj/weapon" . De momento que yo sepa no hay especializaciones
inherit "/obj/weapon";

void setup() {
	// set_base_weapon() sirve para inicializar el arma segun uno basico. Gracias a esta funcion nos evitamos tener que definir por
	// nosotros mismos el material, el coste monetario, el danyo...
	// Los tipos de armas basicos se pueden encontrar en "/table/weapon_table.c"
	set_base_weapon("cuchillo");
	// Todo esto es igual que en los npcs asi que se supone que ya lo sabeis
	set_name("cuchillo");
	set_short("Cuchillo %^BOLD%^J%^RED%^amonero%^RESET%^");
	set_long(query_short()+"\nUn largo cuchillo con la hoja MUY afilada, de los que se usan para cortar el jamon serrano.\n");
	add_alias("jamonero");
	set_main_plural("Cuchillos %^BOLD%^J%^RED%^amoneros%^RESET%^");
       	add_plural("cuchillos");
	add_plural("jamoneros");
	}
