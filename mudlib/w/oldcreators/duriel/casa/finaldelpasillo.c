#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Final del Pasillo%^RESET%^.");
  
  set_long("Es aqui donde se termina el pasillo, hay unas escaleras que conducen arriba, te llama la atencion la extranya luz que proviene de alli.\n\n"); 

  set_light(80);
  add_exit("arriba","/w/duriel/casa/balcon.c");
  
  add_exit("sur","/w/duriel/casa/pasillo4.c");
  

    
  
}