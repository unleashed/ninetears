#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Lavabo%^RESET%^.");
  
  set_long("Un Enorme lavabo que se usa como todos... para hacer sus necesidades.\n\n"); 

  set_light(80);
  add_exit("fuera","/w/duriel/casa/habitacion_duriel.c");

    
  add_item(({"retrete"}),
            "Un retrete en que en el fondo hay restos de %^RED%^caca%^RESET%^.\n");
           
            
  add_item(({"banyera"}),
            "Una banyera enorme de marmol.\n");
            
 
           
}
