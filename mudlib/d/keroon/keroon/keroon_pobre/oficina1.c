// Valar 17/12/02


   inherit "/std/cuartel";


void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Oficina Capitan Primero%^RESET%^");

   set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Oficina Capitan Primero%^RESET%^.\n\n"
      "   Estas en las oficinas del Capitan Primero. El mobiliario de la oficina es minimo y "
      " apenas se compone de una mesa y una silla. En un rincon puedes ver un cajon lleno de "
      "algo que parecen ser armas, aunqye estan bajo llave y no se pueden usar.\n\n");

   add_item("paredes","Las paredes contienen las imagenes de las personas mas buscadas "
                      "por sus fechorias.\n");
   add_item("suelo","El suelo esta sucio y pegajoso, con numerosas manchas de sangre, sin "
                    "duda por las numerosas peleas que aqui se montan.\n");
                       	              

   add_smell(({"habitacion","ambiente","aire"}),"El ambiente esta enrarecido, por "
      "lo visto aqui no saben lo que es el jabon ni un servicio de limpieza. Ni siquiera"
      "ves una papelera.\n");

   add_taste(({"muros","paredes","pared"}),"Agghh, que asco. Solo a t� se te ocurriria ponerte "
      "a chupetear una pared\n");

   add_sound(({"habitacion","entorno"}),"Los prisioneros no paran de quejarse, oyes mucho "
      "tumulto por el arriba y ruidos de pisadas que hacen crujir el techo.\n");

//   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c",1+random (6));
   
   
   add_clone("/d/keroon/keroon/keroon_pobre/npcs/capitan_keroon.c");
   
   set_zone("Keroon");
  
  add_exit("oeste","/d/keroon/keroon/keroon_pobre/oficina.c","door");
  
  
}
