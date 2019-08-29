#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Habitacion de trabajo de %^BOLD%^CYAN%^Duriel%^RESET%^.");
  
  set_long("Es en esta habitacion donde Duriel piensa sus creaciones, hay una mesa peguenyita y una silla de madera. Cuando Duriel termina de pensar suele subir al balcon y ejecutar sus pensamientos desde alli, hay una cama donde duerme y descansa cuando es necesario.\n\n"); 

  set_light(80);
  add_exit("fuera","/w/duriel/casa/pasillo2.c");
  
  add_exit("dentro","/w/duriel/casa/lavabo.c");
  

    
  add_item(({"cama"}),
            "Es una enorme cama con unas sabanas de %^RED%^Wargo %^RESET%^que tienen pinta de abrigar muchisimo.\n\n"
            "Estiras los brazos y te lanzas sobre la cama.\n\n\n"
            "SALES REBOTADO Y TE PEGAS UN MAMPORRO CONTRA LA PARED! Una voz dice, esta cama es solo para Duriel!!!!!! Ni se te ocurra estirarte porque la ensucias!!.\n");
  
  add_item(({"silla"}),
            "Es una comoda silla de madera con mosaicos en las patas.\n");

  add_item(({"mesa"}),
            "Esta es la mesa donde Duriel tiene sus papeles con los planos de sus proximas creaciones, parece que ahora esta trabajando en una tal..... Ciudad de Hielo.\n");
}