inherit "/std/room.c";

void setup()

{
    set_short("Zona de %^BOLD%^%^GREEN%^PRUEBAS%^RESET%^");
     set_long("En esta zona habra gremios, monstruos, objetos, etc, "+
      "que esten en fase de pruebas, para saber si funcionan como deben "+
      "y si tienen errores, tanto logicos como de dopin'.\n\n");

    set_light(80);

add_exit("fuera","/room/test_area/entrada","door");
add_exit("este","/room/test_area/r02","door");
//add_exit("sur", "/room/test_area/r03","door");
add_exit("sudoeste", "/room/test_area/guild_clerigos_gestur", "door");
}
