inherit "/std/bank.c";
void setup() { 
set_short("%^BOLD%^WHITE%^Habitacion del %^BOLD%^RED%^Baul%^RESET%^.");

  set_long("%^BOLD%^WHITE%^Habitacion del %^BOLD%^RED%^Baul%^RESET%^.\nAqui es donde %^BOLD%^RED%^"
	"Leviathan %^RESET%^guarda sus objetos mas preciados, su famoso baul, aquel que las leyendas"
	" cuentan que contiene riquezas infinitas, dignas del mismisimo Dios del Mal.\n");

   set_light(50);
   add_exit("fuera","/w/leviathan/workroom.c","door");
return(0);
}
