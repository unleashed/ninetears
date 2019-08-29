#define CREATOR "%^BOLD%^CYAN%^Duriel %^RESET%^"

inherit "std/room.c";

void setup()
{
  set_short("%^BOLD%^BLUE%^Casa %^RESET%^de %^BOLD%^CYAN%^Duriel%^RESET%^ : %^BOLD%^Pasillo%^RESET%^.");
  
  set_long("Estas en un largo pasillo, ves diversas puertas a lo largo al igual que muchas columnas de hielo, Hay un cuadro muy chillon en la pared.\n\n"); 

  set_light(80);
  add_exit("oeste","/w/duriel/casa/sala_estar.c");
  
  add_exit("norte","/w/duriel/casa/pasillo2.c");
  

    
  add_item(({"cuadro"}),
            "Es un fantastico cuadro del pintor Picassoton que debio pintar hace ya mucho tiempo por poder inmortalizarlo con su pintura.\n"
            "Es realmente magnifico... miras a tu alrededor y vas a cogerlo para llevartelo.\n"
            "Justo cuando estas descolgandolo te empiezan a pitar los oidos increiblemente fuerte y te viene un dolor de cabeza tremendo..... mejor dejalo como estaba.\n");

  
  
}
