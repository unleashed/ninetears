inherit "/std/vaults/vault_room";
#include "path.h"
#include "config.h"

void setup ()
{
::setup();
set_guild_owner( ({GUILDNAME}) );
//set_saqueable(1);       // saq. con opts por defecto
set_short ("%^GREEN%^Baul Casero%^RESET%^.");
set_long("%^GREEN%^Baul Casero%^RESET%^.\n\nNo sabes la suerte "
" que tienes al poner acceder al exclusivo baul del poderoso inmortal "
" Sharka que gracias a sus extraordinarios poderes creo este recinto\n"
"\n     %^RESET%^<%^MAGENTA%^Depositar%^RESET%^> ---> para depositar equipo"
"\n     %^RESET%^<%^MAGENTA%^Recuperar%^RESET%^> -> para recuperar equipo"
"\n     %^RESET%^<%^MAGENTA%^Listar%^RESET%^> -----> para ver los objetos del baul"
"\n\n");
add_item("baul","Es un gran cofre de madera tallada ricamente y con refuerzos de metal.");
set_light (60);

add_exit("sur","/w/sharka/casa/despacho.c","door");
}

/*int clean_up()
{
return 1;
}*/
