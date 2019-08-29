inherit "/std/room";
#include "path.h"
#include "config.h"
object board;

void setup ()
{
set_short("%^GREEN%^Tablon Casero%^RESET%^.");

set_long("%^GREEN%^Tablon Casero%^RESET%^.\n\nNo sabes la suerte "
" que tienes al poner acceder al exclusivo tablon del poderoso inmortal "
" Sharka que gracias a sus extraordinarios poderes creo este recinto\n"
"\n\n     %^RESET%^<%^BOD%^WHITE%^Deja una nota con los fallos de la casa o sobre algun tema para que Sharka lo lea"
"\n\n     %^RESET%^<%^MAGENTA%^Leer + numero de nota%^RESET%^> ---> para leer una nota ya creada"
"\n     %^RESET%^<%^MAGENTA%^Escribir nota%^RESET%^> -> para escribir una nota"
"\n\n");
set_light (60);

add_exit("norte","/w/sharka/casa/despacho.c","door");
add_exit("sur","/w/sharka/casa/hall.c","door");
}


void reset ()
{
if (!board)
{
board = clone_object ("/obj/misc/board");
board-> move (this_object ());
board-> set_datafile (DATAFILE);
}
}

void dest_me ()
{
if (board)
board-> dest_me ();
::dest_me ();
}
