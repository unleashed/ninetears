inherit "/std/bank.c";
//Banko de Keroon by Valar :P

void setup() { 
  
  set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Banco%^RESET%^");

  set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Banco%^RESET%^\n\n"
  
  "Te encuentras en el magestuoso banco de Keroon. Puedes ver como el lujo y la "
  "ostentacion si que se han detenido para realizar la creacion de este banco sin "
  "escatimar en gasto alguno. Puedes ver las mejores medidas de seguridad protegiendo "
  "el dinero y vigilando atentamente a todo el que entra.\n"
  	"\n"  
	"\n     %^BOLD%^Balance%^RESET%^> ---> para ver cuanto te queda en la cuenta"
        "\n     %^BOLD%^Recuperar%^RESET%^> -> para sacar dinero"
        "\n     %^BOLD%^Crear%^RESET%^> -----> pare crear tu cuenta"
        // Por ahora la opcion de cerrar la cuenta no esta disponible
//      "\n     %^RESET%^<%^MAGENTA%^Cerrar%^RESET%^> ----> para cancelar tu cuenta"
        "\n     %^BOLD%^Depositar%^RESET%^> -> para ingresar dinero\n\n");



   add_exit("fuera","d/keroon/keroon/mercado/keroon_194.c","door");
   
return(0);
}
