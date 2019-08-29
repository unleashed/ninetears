inherit "/std/room.c";

void setup()

{
    set_short("Zona de %^BOLD%^%^GREEN%^PRUEBAS%^RESET%^");
     set_long("En esta zona habra gremios, monstruos, objetos, etc, "+
      "que esten en fase de pruebas, para saber si funcionan como deben "+
      "y si tienen errores, tanto logicos como de dopin'.\n\n");

    set_light(50);

add_exit("oeste","/room/test_area/r01","door");
add_exit("sur", "/room/test_area/r021","door");
add_exit("este", "/room/test_area/guild_magos_guerreros", "door");
}
