// Valar 17/12/02


   inherit "/std/cuartel";


void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Prision%^RESET%^");

   set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Prision%^RESET%^.\n\n"
      "   Estas en la prision del Cuartel de la Guardia  de Keroon, en una fria y humeda celda."
      "No puedes ver la luz del exterior porque no hay ninguna ventana hacia afuera.. "
      "La unica salida se encuentra hacia el sur, aunque parece que pasaras mucho tiempo "
      "aqui encerrado.\n\n");

   add_item("barrote","Ves un barrote un poco suelto, lo han debido de forzar muchas veces.\n");
   
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
   

   set_zone("Keroon");
  add_exit("este","/d/keroon/keroon/keroon_pobre/prision_keroon","door");
  
    
}
