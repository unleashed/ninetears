inherit "/std/tienda";

void setup() 
{
	set_short("%^BOLD%^RED%^Tienda de Rongrond%^RESET%^");
	set_long(query_short()+"\n\n Esta es la �nica tienda de Rongrond, aqui se pueden comprar los productos "+
	"conseguidos aqui por sus habitantes, la decoracion es rural, m�s t�pica marina, se nota la influencia "+
	"de las dos principales fuentes de ingresos del pueblo, la pesca y el vino. Al fondo de la tienda "+
	"hay un mostrador.\n\n");
	set_dependiente("/d/faeleen/npcs/vendedor_rongrond.c");
	add_suministro("/d/faeleen/obj/salmon_rongrond",random(5));
	add_suministro("/d/faeleen/obj/trucha_rongrond",random(5));
	add_suministro("/d/faeleen/obj/vino_blanco_rongrond",random(5));
	add_suministro("/d/faeleen/obj/vino_tinto_rongrond",random(5));
	add_cartel("placa");
	add_exit("fuera","/d/faeleen/rooms/rongrond/pueblo/pueblo_rongrond_11.c","standard");
}