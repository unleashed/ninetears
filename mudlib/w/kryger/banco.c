inherit "/std/bank.c";
void setup() { 
set_short("%^GREEN%^Banco de Avalon%^RESET%^.");

  set_long("%^GREEN%^Banco de Avalon%^RESET%^.\n\n      Aqui es donde "
	"los usureros de Avalon disponen de libertad para traficar con el dinero de "
	"los contibuyentes y quedarse incluso con el si asi les es menester \n"
	"\n     %^RESET%^<%^MAGENTA%^Balance%^RESET%^> ---> para ver cuanto te queda en la cuenta"
        "\n     %^RESET%^<%^MAGENTA%^Recuperar%^RESET%^> -> para sacar dinero"
        "\n     %^RESET%^<%^MAGENTA%^Crear%^RESET%^> -----> pare crear tu cuenta"
// Por ahora la opcion de cerrar la cuenta no esta disponible
//        "\n     %^RESET%^<%^MAGENTA%^Cerrar%^RESET%^> ----> para cancelar tu cuenta"
        "\n     %^RESET%^<%^MAGENTA%^Depositar%^RESET%^> -> para ingresar dinero"
	"\n\n");



   set_light(50);
   add_exit("fuera","/room/visitas.c","door");
return(0);
}
