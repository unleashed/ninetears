//Kryger 2002//
inherit "/std/tienda";

void setup() 
{
	set_short("%^BOLD%^BLUE%^Carniceria%^RESET%^");
	set_long(query_short()+"\n\n Esta es la �nica Carniceria del pueblo, aunque con ella se bastan "
	"para abastecer a todo el pueblo, es un establecimiento peque�o, apenas para que entren diez personas"
	"y esta decrorado con pieles de los animales que le traen del matadero, tambi�n vemos un mostrador al "
	"fondo, desde alli sera donde nos atiendan piensas.\n\n");
	set_dependiente("/d/faeleen/npc/carnicero_ormerod.c");
	prohibir_venta();
	add_suministro("/d/faeleen/obj/cordero_ormerod",random(5));
	add_suministro("/d/faeleen/obj/vaca_ormerod",random(5));
	add_suministro("/d/faeleen/obj/salchichas_ormerod",random(5));
	add_suministro("/d/faeleen/obj/jamon_ormerod",random(5));
	add_cartel("placa");
	add_exit("norte","/d/faeleen/rooms/ormerod/pueblo/pueblo_ormerod_5.c","standard");
}