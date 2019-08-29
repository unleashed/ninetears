inherit "/std/room.c";

void setup()

{
    set_short("%^GREEN%^Castillo sobre la Nada: Pasillo%^RESET%^");
     set_long("%^GREEN%^Castillo sobre la Nada: Pasillo%^RESET%^\n\n"+
      "  Te encuentras en un lugubre pasillo que conduce hacia unas "+
      "escaleras que probablemente te lleven al piso de arriba.\n\n" +
	"Parece que algun sonido proviene de arriba.\n\n");

    set_light(40);
add_item("pasillo","Ves un pasillo estrecho y algo tenebroso, no te imaginas" + 
	" a donde puede llevar.\n");
// para estas cosas habria q usar un handler q controlase todo
// como q los guardias ataken todos los magos tb y q se kite aki
// el sonido si drakull esta muerto

	// NO RULA
	/*if (sizeof(find_match("/room/castillo_drakull/npcs/drakull.c"->
	query_main_plural(), "/room/castillo_drakull/castillo01.c")))*/
add_sound(({"default", "arriba", "sonido"}), "Escuchas aterradamente roces metalicos, como si alguien estuviera afilando cuchillas.");
add_exit("arriba","/room/castillo_drakull/castillo01","door");
add_exit("fuera","/room/castillo_drakull/entrada","door");
}
