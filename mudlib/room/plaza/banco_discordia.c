inherit "/std/bank.c";
void setup() { 
set_short("%^BOLD%^YELLOW%^Banco de la %^RESET%^RED%^Discordia%^RESET%^");

  set_long(query_short()+"\n"+"Estamos en el banco del campo de la Discordia, aqui es donde "
  "los bravos combatientes depositan sus ahorros que no quieren perder, aunque solo los m�s "
  "fuertes consiguen volver a por ellos.\n");


// Por ahora la opcion de cerrar la cuenta no esta disponible
//        "\n     %^RESET%^<%^MAGENTA%^Cerrar%^RESET%^> ----> para cancelar tu cuenta"
   add_sign("Ves una placa en la pared","\n     %^RESET%^<%^YELLOW%^Balance%^RESET%^> ---> para ver cuanto te queda en la cuenta\n     %^RESET%^<%^YELLOW%^Sacar%^RESET%^> -----> para sacar dinero\n     %^RESET%^<%^YELLOW%^Crear%^RESET%^> -----> pare crear tu cuenta\n     %^RESET%^<%^YELLOW%^Ingresar%^RESET%^> --> para ingresar dinero\nEl porcentaje que se lleva esta entidad es del 2%.\n\n","placa","placa"); 
   set_light(50);
   set_percentage(98);
   add_exit("fuera","/room/plaza/campo_discordia_23.c","door");
return(0);
}