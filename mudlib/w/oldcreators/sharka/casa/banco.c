#include "path.h"

inherit "/std/bank.c";
void setup()

{
set_short("%^GREEN%^Banco Casero%^RESET%^.");

set_long("%^GREEN%^Banco Casero%^RESET%^.\n\nNo sabes la suerte "
" que tienes al poner acceder al exclusivo banco del poderoso inmortal "
" Sharka que gracias a sus extraordinarios poderes creo este recinto\n"
"\n     %^RESET%^<%^MAGENTA%^Balance%^RESET%^> ---> para ver cuanto te queda en la cuenta"
"\n     %^RESET%^<%^MAGENTA%^Recuperar%^RESET%^> -> para sacar dinero"
"\n     %^RESET%^<%^MAGENTA%^Crear%^RESET%^> -----> pare crear tu cuenta"
// Por ahora la opcion de cerrar la cuenta no esta disponible
//  "\n     %^RESET%^<%^MAGENTA%^Cerrar%^RESET%^> ----> para cancelar tu cuenta"
"\n     %^RESET%^<%^MAGENTA%^Depositar%^RESET%^> -> para ingresar dinero"
"\n\n");


set_light(50);
add_exit("este","/w/sharka/casa/despacho.c","door");
return(0);
}
