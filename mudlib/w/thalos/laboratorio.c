#define CREATOR "thalos"

inherit "/std/room.c";


void setup()
{
   set_short("%^BLACK%^BOLD%^Laboratorio de %^RED%^Thalos%^RESET%^");
   
   set_long("\n%^BLACK%^BOLD%^Laboratorio de %^RED%^Thalos%^RESET%^.\n\n"
    "Estas en la habitacion donde Thalos dedica horas enteras a sus creacciones,"
    " por todos lados encuentras marmitas, calderas, probetas, restos de diversos"
    " seres,sin duda utilizados en macabros experimentos, compuestos quimicos..."
    "Asi que decides quedarte quieto y no moverte mucho por lo que pudiera pasar.""\n\n");
      
   set_light(80);
   add_item("restos","Ves un masa sanguilonente que no puedes ni quieres identificar\n");
   
   add_exit("puerta","/w/thalos/salon.c","door");

}
