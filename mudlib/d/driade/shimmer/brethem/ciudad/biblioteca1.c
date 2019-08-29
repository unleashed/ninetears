/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/storeroom";

void setup()
{
	set_short("%^BOLD%^RED%^Biblioteca de Brethem%^RESET%^");
	set_long("%^BOLD%^RED%^Biblioteca de Brethem%^RESET%^\n\n"
                 "Aqui e donde se guardan los libros de la ciudad, es una gran sala con unas cuantas "
                 "mesas rodeadas de cientos de estanterias cargadas de libros de todo tipo, la mayor "
                 "parte de ellos cargados de polvo por el paso del tiempo y el olvido en el que fueron "
                 "cayendo. Zaen el bibliotecario hojea un gran libro maldiciendo unas palabras "
                 "sentado en su mesilla.\n\n");



	add_exit("fuera", BRETHEM + "callebiblioteca", "door");
	set_light(80);
}

void reset()
{
	call_out("af_reset", 0);
}

void af_reset()
{
   int i, j;
   object ob;
        

   clone_object(BRETHEM + "npcs/zaen.c")->move(this_object());

   clone_object(BRETHEM + "items/libro_historia_brethem.c")->move(this_object());

   i = sizeof(find_match("antiguos", this_object()));
   for (;i<2;i++)
   {
     ob=clone_object(BRETHEM + "items/libro_antiguo.c")->move(this_object());
   }
   i=sizeof(find_match("viejos", this_object()));
   for (;i<3+random(2);i++)
   {
      ob=new(BRETHEM + "items/libro_viejo.c")->move(this_object());
   }
   i=sizeof(find_match("niubis", this_object()));
   for (;i<3+random(2);i++)
   {
      ob=new(BRETHEM + "items/libro_niubi.c")->move(this_object());
   }
}
