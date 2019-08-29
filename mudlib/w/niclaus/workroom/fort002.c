inherit "std/room.c";

void setup() {
	set_short("%^BOLD%^BLACK%^Celestial Fortaleza de Sakalzor: %^WHITE%^Pasillo Principal.\n");
	set_long("   Te encuentras en medio de un pasillo amplio, con grandes columnas "
	"y diversidad de trofeos de toda clase colgados de las paredes. La sala esta bien "
	"iluminada gracias a las antorchas que rodean cada columna del pasillo. "
	"Por las paredes se desliza un suave torrente de sangre.\n");
	add_item("trofeos","  Observas detenidamente las cabezas de seres que jamas antes "
	"habias visto... se encuentran colgadas de la pared como si fueran trofeos de un "
	"cazador, las cabezas parecen no dejar de sangrar.\n");
	add_sound("habitacion","  Hay un silencio desesperante, solo roto por un ligero "
	"tintineo de algunas gotas de sangre que caen de la pared.\n");
	set_light(50);
	add_exit("sur","/w/niclaus/workroom/fort001.c","corridor");
	add_exit("norte","/w/niclaus/workroom/salon.c","corridor");
}