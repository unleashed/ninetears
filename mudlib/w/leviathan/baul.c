inherit "/std/vaults/vault_room.c";
void setup() { 
::setup();
set_save_file("baul.c");
set_short("%^BOLD%^WHITE%^Habitacion del %^BOLD%^RED%^Baul%^RESET%^.\n");

  set_long("%^BOLD%^WHITE%^Habitacion del %^BOLD%^RED%^Baul%^RESET%^.\n\nAqui es donde %^BOLD%^RED%^"+
	"Leviathan %^RESET%^guarda sus objetos mas preciados, su famoso baul, aquel que las leyendas "+
	"cuentan que contiene riquezas infinitas, dignas del mismisimo Dios del Mal.\n\n");

   set_light(50);
   add_exit("fuera","/w/leviathan/workroom.c","door");
return(0);
}
