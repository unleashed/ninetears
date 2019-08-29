inherit "std/room.c";

void setup() {
	set_short("%^BOLD%^BLACK%^Celestial Fortaleza de Sakalzor: %^WHITE%^Salon Central.\n");
	set_long("   Este es el centro de la fortaleza, desde aqui se puede acceder a el "
	"nivel superior. Las paredes y columnas del salon forman una exquisita coleccion "
	"de armas y escudos de todo tipo. Encima de las escaleras cuelga el estandarte con "
	"el escudo de armas de la dinastia de Niclaus, un Latigo de Fuego.\n");
	add_item(({"armas","escudos"}),"  Una gran cantidad de armas y escudos en perfecto "
	"estado, algunas son autenticas obras de artesania y otras parecen desprender un "
	"fuerte poder magico.\n");
	set_light(50);
	add_exit("noreste","/w/niclaus/workroom/trono.c","corridor");
	add_exit("sur","/w/niclaus/workroom/fort002.c","corridor");
	add_exit("noroeste","/w/niclaus/workroom/pruebas.c","corridor");
}