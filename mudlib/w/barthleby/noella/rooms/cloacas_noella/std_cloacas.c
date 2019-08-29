/* Archivo base a partir del que se generan las descripciones de las cloacas de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/underground.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No distingues nada en esta oscuridad.\n\n");
   //add_item("loquesea","Descripcion bla, bla, bla. \n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(10);
   set_zone("cloacas");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LAS CLOACAS */

void long_desc_cloacas()
{

string *descripciones1 = ({
      "En realidad este oscuro corredor no fue dise�ado en un principio para cumplir la "
         "funcion de cloacas, sino que se trataba de un paso interior de una antigua muralla "
         "sobre la que est� constru�da la actual. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "Su tama�o hace presuponer que fue constru�da por una raza de peque�a estatura. "
         "Hoy d�a, todas las aguas fecales de la ciudad vienen a reunirse aqu�"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
/* DESCRIPCIONES DE LAS CATACUMBAS */

void long_desc_catacumbas()
{

string *descripciones1 = ({
      "En un principio este corredor parece excavado en la tierra, pero cuanto mas te "
         "acostumbras a la escasa iluminaci�n, m�s f�cil te resulta distinguir unas piedras "
         "cuadradas incrustadas en las paredes; ",
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "Apostar�as tu vida a que tras esas piedras se "
         "encuentran los restos de antiguos moradores de la ciudad"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
