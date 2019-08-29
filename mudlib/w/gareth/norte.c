#define CREATOR "Gareth"
inherit "/std/room.c";

void setup() {
   	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Galeria de arte%^RESET%^");
   	set_long(query_short()+"\n Despues del largo descenso llegas a otra sala de forma rectangular, tambien iluminada por antorchas. En las paredes hay colgados cuadros de variados tamanyos, pero todos tienen imagenes grotescas de personas mutiladas y con deformidades. Al fondo de la habitacion hay una pequenya fuente.\n\n");
   	
   	add_item("cuadros","Los cuadros tienen imagenes grotescas, en todos predomina la sangre. Sientes que te entran ganas de vomitar al mirarlos, sera mejor que apartes la vista.\n");
   	add_item("fuente","Una fuente construida en la pared, cae un chorro de agua cristalina.\n");
   	
  	add_smell(({"habitacion","sala","aire"}),"No huele a nada, pero el aire esta muy frio.\n");
   	add_sound(({"habitacion","sala","aire"}),"Escuchas el relajante sonido del agua de la fuente al caer.\n");
	
   	add_exit("recibidor","/w/gareth/workroom","corridor");   		
   		}
   	   	
void init() {
	::init();
	add_action("beber_fuente","beber"); }
int beber_fuente(string str) {
   	if(str == "fuente") {
	tell_object(TP,"Bebes el agua fresca y limpia de la fuente, y sientes que se te renuevan las fuerzas.\n");
	tell_room(TO,this_player()->query_cap_name()+" bebe de la fuente y se cura.\n",TP);
	TP->adjust_hp(999999999); 
	TP->adjust_gp(999999999);
		return 1;
   		}
		}