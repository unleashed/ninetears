/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/storeroom";

void setup()
{
	set_short("El Almacen de la Tienda de Samand");
	set_long("Aqui es donde se guardan las provisiones de la tienda del Alquimista Samand.\n");
	add_exit("abajo", BRETHEM + "alquimia1.c", "door");
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
        
   i = sizeof(find_match("azul", this_object()));
   for (;i<3;i++)
   {
     ob=clone_object(BRETHEM + "items/pocion_azul")->move(this_object());
   }
   i = sizeof(find_match("roja", this_object()));
   for (;i<4;i++)
   {
     ob=clone_object(BRETHEM + "items/pocion_roja")->move(this_object());
   }
   i=sizeof(find_match("dorada", this_object()));
   for (;i<20+random(10);i++)
   {
      ob=new(BRETHEM + "items/pocion_dorada")->move(this_object());
   }
   i=sizeof(find_match("fuerza", this_object()));
   for (;i<18+random(8);i++)
   {
      ob=new(BRETHEM + "items/barra_medio")->move(this_object());
   }
}
