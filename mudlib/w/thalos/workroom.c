#define CREATOR "thalos"

inherit "/std/room.c";

void setup()
{
   set_short("%^BOLD%^Entrada a la gruta de %^RED%^Thalos%^RESET%^");

   set_long("\n%^BOLD%^Entrada a la gruta de %^RED%^Thalos%^RESET%^.\n\n"
      "Estas en el interior de una montanya, mas exactamente en una gruta,"
      " el aire es humedo y sofocante, como iluminacion encuentras un grupo"
      " de teas engarzados en las paredes cada diez metros, tienes cuidado"
      " de no tropezar con las estalagmitas y estalactitas que adornan la"
      " gruta, empiezas a pensar en los millones de toneladas de roca que"
      " hay encima de tu cabeza, y  te pones enfermo, desechas esas ideas"
      " claustrofobicas y continuas tu camino""\n\n");
   

   set_light(60);
   
   
   add_smell(({"habitacion","gruta","aire","room"}),"El aire esta viciado debido sin duda a la poca"
      " ventilacion del lugar.\n");
   
   add_sound(({"room","gruta","habitacion"}),"Solo oyes el sonido del agua goteando por las parades,"
   "a medida que forman las estalactitas y estalagmitas.\n");
     
  add_exit("norte","/w/thalos/salon.c","path");
  add_exit("comun","/w/common","door");
  add_exit("mud","/room/entryroom.c","door");
  "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door"); 
}

