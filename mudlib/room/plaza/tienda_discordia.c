//Kryger 2003//
inherit "/std/tienda";

void setup() 
{
	set_short("%^BOLD%^RED%^Tienda de %^BLUE%^Tano%^RESET%^.");
	set_long(query_short()+"\n Esta es la �nica tienda del campo de la discordia, aqui podemos encontrar "
	"variedad en equipo de aventurero, las paredes al igual que la taberna estan decoradas con restos "
	"de armaduras que en alguna era fueron lujosas y buenas.\n\n");
	set_dependiente("/room/plaza/tano_discordia.c");
	add_suministro("/baseobs/armaduras/armadura_de_cuero",random(5));
	add_suministro("/baseobs/armaduras/brazaletes",random(5));
	add_suministro("/baseobs/armaduras/capa",random(5));
	add_suministro("/baseobs/armaduras/guantes",random(5));
	add_cartel("placa");
	add_exit("fuera","/room/plaza/campo_discordia_28.c","standard");
}