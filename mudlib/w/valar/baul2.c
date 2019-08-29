#define CREATOR "valar"

inherit "/std/vaults/vault_room.c";
void setup() { 
	::setup();
   	set_save_file("baul2.c");

	set_short("%^B_BLUE%^Baul de las Armaduras%^RESET%^");

   	set_long("\n%^B_BLUE%^Baul de las Armaduras%^RESET%^.\n\n"
      	"   Esta es la sala en la que Valar guarda todas las armaduras que se encuentra "
      	" en sus andauras por todo el mud.\n\n");

   
   	set_light(20);

   	add_item("baul","un baul de hierro reforzado con tiras de mithril para una mejor "
      "seguridad.\n");
           
   	add_exit("fuera","/w/valar/dormitorio.c","door");
      
}
