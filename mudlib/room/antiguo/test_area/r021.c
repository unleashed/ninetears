inherit "/std/room.c";

void setup()

{
    set_short("Zona de %^BOLD%^%^GREEN%^PRUEBAS%^RESET%^");
     set_long("En esta zona habra gremios, monstruos, objetos, etc, "+
      "que esten en fase de pruebas, para saber si funcionan como deben "+
      "y si tienen errores, tanto logicos como de dopin'.\n\n");

    set_light(50);

add_exit("norte", "/room/test_area/r02","door");
add_exit("sudeste", "/room/test_area/guild_ladrones", "door");
}
