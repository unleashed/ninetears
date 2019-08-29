#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Pasillo%^RESET%^.");
  
  set_long("Estas en un largo pasillo, ves diversas puertas a lo largo al igual que muchas columnas de hielo.\n\n"); 

  set_light(80);
  add_exit("norte","/w/duriel/casa/pasillo3.c");
  
  add_exit("sur","/w/duriel/casa/pasillo.c");
  
  add_exit("dentro","/w/duriel/casa/habitacion_duriel.c");
  

    
}