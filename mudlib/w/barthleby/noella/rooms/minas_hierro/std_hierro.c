/* Archivo base a partir del que se generan las descripciones de las minas de hierro de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No alcazas a ver nada de las minas con esta oscuridad.\n\n");
   //add_item(({"itemA","itemB"}),"Descripci�n bla, bla, bla.\n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(40);
   set_zone("mina_hierro");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LAS MINAS DE HIERRO */

void long_desc_hierro()
{

string *descripciones1 = ({
      "El aire est� impregnado de un polvillo rojo oscuro pero no llega a dificultar en exceso "
         "tu visi�n. El camino est� excavado directamente sobre la roca y tambien est� recuvierto "
         "con el polvillo, que toma un color mucho m�s intenso sobre las marcas de las huellas de "
         "los carros. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "A tu alrrededor puedes ver multitud de mineros extrayendo el �til mineral"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
