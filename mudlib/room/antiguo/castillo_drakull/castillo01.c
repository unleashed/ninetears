inherit "/std/room.c";

void setup()

{
    set_short("%^GREEN%^Castillo sobre la Nada: Trono%^RESET%^");
     set_long("%^GREEN%^Castillo sobre la Nada: Trono%^RESET%^\n\n"+
      "Aunque parezca mentiraaaaaaaaa me pongo coloradaaa cuando "+
	"me miraaan, osea jo.\n\n");

    set_light(40);
add_item("trono","El trono de Drakull el Vampiro, hecho de oro macizo.\n");

add_exit("abajo","/room/castillo_drakull/castillo00","door");
modify_exit("abajo", ({"function", "go_salir"}));
add_clone("/room/castillo_drakull/npcs/drakull.c",1);
}

int go_salir()
{
	if (TP->query_dead())
		return 1;
	if (!random(5)) {
		return 1;
	}
	notify_fail("No consigues salir por la escalerilla.\n");
	return 0;
}
