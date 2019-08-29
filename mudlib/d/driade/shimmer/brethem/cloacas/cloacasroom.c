/* ESTE ES EL ARCHIVO BASE A PARTIR DEL CUAL SE GENERAN LAS DESCRIPCIONES DE LAS ROOMS, NPCS Y DEMAS DE LAS CLOACAS DE BRETHEM */


/* By Shimmer */

#define CREATOR "shimmer"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "../../path.h"

inherit "/std/underground.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()   
{
//   set_dark_long("Esta todo muy oscuro y solo sabes que te encuentras en la ciudad de Brethem.\n\n");
   add_item("suelo", "Una capa de fango cubre el suelo llegandote a la altura de los tobillos.\n");   
   add_smell(({"cloaca", "aire", "tunel"}), "Un olor nauseabundo impregna el tunel produciendote nauseas.\n");
   set_light(0);
   set_zone("cloacas");
   add_sound(({"cloacas", "tunel"}), "Puedes oir el debil chapoteo de algunas alimanyas moviendose en la oscuridad\n");

}

/* DESCRIPCIONES PARA LAS CLOACAS */

void long_desc()
{

string *descripciones1 = ({"Estas en un tunel oscuro y humedo bajo la ciudad de Brethem, ",
 "Un gran tunel se abre ante ti, no puedes ver mas alla de un par de metros de lo oscuro que esta, ",
 "Ante ti se abre un amplio tunel, estas en las cloacas bajo la ciudad de Brethem, "});
 string descripcion1;

 string *descripciones2 = ({"el suelo esta cubierto de una espesa capa de fango y el olor es insoportable, por "
        "momentos te cuesta respirar. ",
 "caminas sobre un suelo embarrado y un olor insoportable te llena mareandote, las paredes estan cubiertas de un "
        "musgo en el que resbalas al intentar apoyarte. ",
 "del techo cuelgan largos hierbajos que te dificultan los movimientos, mientras que las paredes estan cubiertas "
        "de un verde musgo resbaladizo. "});
 string descripcion2;

 string *descripciones3 = ({"Notas como pequenyas alimanyas te pasan por delante en la oscuridad",
 "Algunas alimanyas escondidas en la oscuridad te miran atemorizadas y notas sus chillidos",
 "Te da la impresion de que estas siendo observado por algunas alimanyas ocultas en la oscuridad"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}



/* CREA NPCS PARA LAS CLOACAS */

void crea_npcs()
{
   int cual, j;

   n=random(4);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(CLOACASBRE+"npcs/rata", 1);
                 break;
         case 1: add_clone(CLOACASBRE+"npcs/murcielago", 1);
                 break;
         case 2: add_clone(CLOACASBRE+"npcs/serpiente", 1);
                 break;
         case 3: add_clone(CLOACASBRE+"npcs/rata", 1);
                 break;
         case 4: add_clone(CLOACASBRE+"npcs/serpiente", 1);
                 break;
         case 5: add_clone(CLOACASBRE+"npcs/murcielago", 1);
                 break;
         case 6: add_clone(CLOACASBRE+"npcs/rata", 1);
                 break;
         case 7: add_clone(CLOACASBRE+"npcs/murcielago", 1);
                 break;
      }
   }
}


void destruye_npcs()
{
}

