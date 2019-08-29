#define CREATOR "Gareth"
inherit "/std/room.c";

void setup() {
   	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Observatorio Secreto%^RESET%^");
   	set_long(query_short()+"\n Escalas la trampilla y entras en una sala igual que la anterior, pero en el lugar de las escaleras hay unos grandes ventanales, desde donde se observan todas las tierras. En un rincon hay una gran estanteria llena de libros.\n\n");
   	
   	add_item("ventanales","Unas grandes ventanas desde donde se observa todo.\n");
   	add_item("estanteria","Una estanteria de madera negra y pulida llena de viejos libros. Tiene un rotulo arriba,seria conveniente leerlo.\n");
   	
  	add_smell(({"habitacion","sala","aire"}),"No huele a nada, pero el aire esta muy frio.\n");
   	add_sound(({"habitacion","sala","aire"}),"Escuchas los fuertes vientos golpeando en los ventanales.\n");
	add_sign("Un rotulo brillante.\n","NO TOCAR, PELIGRO","Rotulo","rotulo");
	
	add_exit("recibidor","/w/gareth/workroom","corridor");   		
   		}

   	   	
void init() {
	::init();
	add_action("coger_libro","coger"); }
int coger_libro(string str) {
   	if(str == "libros") {
	tell_object(TP,"Al tocar los libros un frio sobrenatural te entra por la mano y se te extiende por todo el cuerpo. Estabas avisado.\n");
	tell_room(TO,this_player()->query_cap_name()+" toca los libros y se activa la trampa.\n",TP);
	TP->adjust_hp(-99); 
		return 1;
		return notify_fail("Coger que?\n");
   		}
		}