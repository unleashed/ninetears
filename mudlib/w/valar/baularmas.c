#define CREATOR "valar"
inherit "/std/vaults/vault_room.c";
void setup() { 
::setup();
set_save_file("baul1.c");


{
   set_short("%^B_RED%^Baul de las Armas%^RESET%^");

   set_long("\n%^B_RED%^Baul de las Armas%^RESET%^.\n\n"
      "   Esta es la sala en la que Valar guarda todas las armaduras que se encuentra "
      " en sus andauras por todo el mud.\n\n");

   // sets the level of light in the room.   "help light" for details
   set_light(20);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("baul","un baul de hierro reforzado con tiras de mithril para una mejor "
      "seguridad.\n");
           
   //Here are the exits from your room
   //add_exit(direction, destination, type)
   //direction - What they must type to leave that direction
   //destination - The room they will be moved to
   //type - The exit type, can be "path","corridor","door"...
   //Read /doc/roomgen/exit_type_help for more info.

  add_exit("fuera","/w/valar/dormitorio.c","door");
  }}