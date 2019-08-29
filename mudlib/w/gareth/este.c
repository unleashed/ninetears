#define CREATOR "Gareth"
inherit "/std/room.c";

void setup() {
   	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Sala de estudio%^RESET%^");
   	set_long(query_short()+"\n Te encuentras en una pequenya sala de forma rectangular. Hay un escritorio y una silla de madera negra con inscripciones doradas. La habitacion esta iluminada por una lampara en el escritorio.\n\n");
   	
   	add_item("escritorio","Un escritorio de madera negra. Esta vacio.\n");
   	add_item("silla","Una silla grande y negra. Parece bastante comoda.\n");
   	add_item("lampara","Una pequenya lampara de aceite. Pese a su tamanyo ilumina perfectamente toda la habitacion.\n");
  	
  	add_smell(({"habitacion","sala","aire"}),"No huele a nada, pero el aire esta muy frio.\n");
   	add_sound(({"habitacion","sala","aire"}),"Todo esta en silencio.\n");
	
   	add_exit("recibidor","/w/gareth/workroom","corridor");   		
   		}
   	   	