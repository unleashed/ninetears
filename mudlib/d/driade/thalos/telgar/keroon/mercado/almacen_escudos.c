// Made by Thalos 

#include "../../path.h"

inherit "/std/storeroom";

void setup()
{
	set_short("El Almacen de la Tienda de yelmos y escudos de Taruzun");
	set_long("Aqui e donde se guardan las provisiones de la Tienda de yelmos y escudos de Taruzun.\n");
	add_exit("abajo", MERCADO + "keroon_134.c", "door");
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
        
   i = sizeof(find_match("cotas", this_object()));
   for (;i<3;i++)
   {
     ob=clone_object(NPCS + "equipo/cota_guardia")->move(this_object());
   }
   i = sizeof(find_match("armaduras", this_object()));
   for (;i<4;i++)
   {
     ob=clone_object(NPCS + "equipo/armadura_capitan")->move(this_object());
   }
   i=sizeof(find_match("picos", this_object()));
   for (;i<20+random(10);i++)
   {
      ob=new(NPCS + "equipo/pico")->move(this_object());
   }
   
}
