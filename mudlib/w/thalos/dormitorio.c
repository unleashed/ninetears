#define CREATOR "thalos"

inherit "/std/room.c";


void setup()
{
   set_short("%^GREEN%^Dormitorio de %^RED%^Thalos%^RESET%^");
   
   set_long("\n%^GREEN%^Dormitorio de %^RED%^Thalos%^RESET%^.\n\n"
   "En contraste con las otra habitaciones de la casa esta es bastante"
   " parca, solo tiene un cama y un pequenyo armario, por mas que miras"
   " no encuentras ningun otr otipo de decoracion""\n\n");
      
   set_light(60);
   add_item("mesa","Ves una mesa repleta de libros.\n");
   add_item("cama","Es la cama donde Thalos descansa cuando se siente agotado, observas una fina capa de polvo que te indica que no debe dormir muy amenudo.\n");
   add_item("armario","Ves un pequenyo armario que sin duda tiene la ropa  de Thalos\n");
  
   add_exit("oeste","/w/thalos/salon.c","path");

}
  