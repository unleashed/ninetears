#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Balcon%^RESET%^.");
  
  set_long("Un magnifico balcon con una barandilla de Hielo en el que se ve todo el mundo que Deucalion creo, hay una vista magnifica.\n\n"); 

  set_light(80);
  add_exit("abajo","/w/duriel/casa/finaldelpasillo.c");
  
 
  
    
  
}