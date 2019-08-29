#define CREATOR "Gareth"
inherit "/std/room.c";

void setup() {
	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Almacen%^RESET%^");
	set_long(query_short()+"\n Atraviesas la puerta y entras en una estancia con dos puertas que conducen a las distintas partes de la tienda.\n\n");

	add_item("puertas","Dos puertas de madera negra situadas una al lado de otra.\n");
	add_item("pared","La pared es de piedra lisa y negra.\n");

	add_smell(({"habitacion","sala","aire"}),"Hay un aroma muy raro en la sala, debido a la mezcla de los olores de todas las cosas.\n");
	add_sound(({"habitacion","sala","aire"}),"Todo esta en silencio.\n");

	add_exit("recibidor","/w/gareth/workroom","door");
	add_exit("herreria","/w/gareth/herreria","door");
	add_exit("tienda","/w/gareth/tienda","door");
}