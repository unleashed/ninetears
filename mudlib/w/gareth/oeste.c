#define CREATOR "Gareth"
inherit "/std/room.c";

void setup() {
   	set_short("%^BLACK%^%^BOLD%^Mazmorras de %^GREEN%^%^BOLD%^Gareth %^BLACK%^%^BOLD%^- Almacen%^RESET%^");
   	set_long(query_short()+"\n Desciendes las escaleras y llegas a una sala muy grande, toda llena de alimentos, armas y toda clase de objetos. Esta tenuemente iluminada por antorchas, aunque hay muchas apagadas. Sera mejor que no toques nada.\n\n");
   	
   	add_item("alimentos","Hay varias cajas llenas de alimentos para varias semanas.\n");
   	add_item("armas","Un pequenyo apartado donde Gareth guarda sus armas y armaduras viejas.\n");
   	add_item("objetos","Hay muchos objetos de toda clase: lamparas, plumas, pergaminos, y un monton de ropa de viaje.\n");
  	add_item("pared","La pared es de piedra lisa de color negro, aunque hay un pequenyo boton que sobresale.\n");
  	
  	add_smell(({"habitacion","sala","aire"}),"Hay un aroma muy raro en la sala, debido a la mezcla de los olores de todas las cosas.\n");
   	add_sound(({"habitacion","sala","aire"}),"Todo esta en silencio.\n");
	
   	add_exit("recibidor","/w/gareth/workroom","corridor");   		
   		}
   		
void init() {
	::init();
	add_action("pulsar_boton","pulsar"); }
int pulsar_boton(string str) {
   	if(str == "boton") {
	tell_object(TP,"Pulsas el boton y un pasadizo se abre al fondo de la habitacion.\n");
	tell_room(TO,this_player()->query_cap_name()+" pulsa el boton y se abre el pasadizo.\n",TP);
	add_exit("baul","/w/gareth/baul/baul.c","corridor");
	renew_exits();
      		return 1;
   		}
		}	
   		
   		