/* Archivo base a partir del que se generan las descripciones de la prision de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/room.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No puedes ver nada con esta oscuridad.\n\n");
   add_item(({"muros","muro","pared","paredes"}),"Son unos muros de granito realmente gruesos que " +
        "hacen imposible e impensable el tratar de derribarlos.\n");
   //add_smell(({"smellA","smellB","smellC"}),"Descripci�n bla, bla, bla.\n");
   set_light(50);
   set_zone("prision");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LA PRISION DE NOELLA */

void long_desc_prision()
{

string *descripciones1 = ({
      "Increiblemente gruesos muros de granito conforman lo que se refiere al exterior y "
         "paredes de esta prisi�n. Muchos han sido los que han visto pasar los �ltimos d�as de su "
         "vida comtemplando sus paredes, y raras han sido las excepciones de los que han cumplido "
         "condena o logrado escapar. ",
      "Los muros de granito que forman el esqueleto de Gorband te resultan casi m�s imponentes "
         "desde dentro que desde fuera. Mientras caminas por su interior piensas en lo desagradable "
         "que ser�a acabar aqu�, ni como reo, ni como guardia. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "La prisi�n est� enteramente construida sobre el Trabasir, consiguiendo "
         "as� que tenga un �nico acceso posible",
      "Puedes sentrir el paso de las aguas del Trabasir bajo la prisi�n. Resulta ir�nico "
         "que hayan constru�do la prisi�n sobre algo que inspire un gran sentimiento de libertad,"
	 "como inspiran los r�os"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
/* DESCRIPCIONES DE LA PRISION DE NOELLA, BLOQUE_A*/

void long_desc_bloque_A()
{

string *descripciones1 = ({
      "Est�s pudri�ndote en una de las celdas del bloque A de Gorband Ab-Trabasir. El sonido "
         "de las aguas del r�o y alguna que otra rata que se deja ver de vez en cuando son tu "
         "�nica compa�ia. ",
      "Est�s pudri�ndote en una de las celdas del bloque A de Gorband Ab-Trabasir. El sonido "
         "de las aguas del r�o y alguna que otra rata que se deja ver de vez en cuando son tu "
         "�nica compa�ia. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "Con frecuencia llegas a pensar que las ratas se rien de ti, tal vez sea "
         "ese el primer s�ntoma de que te encuentras al borde de la locura",
      "Con frecuencia llegas a pensar que las ratas se rien de ti, tal vez sea "
         "ese el primer s�ntoma de que te encuentras al borde de la locura"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
/* DESCRIPCIONES DE LA PRISION DE NOELLA, BLOQUE_B*/

void long_desc_bloque_B()
{

string *descripciones1 = ({
      "Est�s pudri�ndote en una de las celdas del bloque B de Gorband Ab-Trabasir. El sonido "
         "de las aguas del r�o y alguna que otra rata que se deja ver de vez en cuando son tu "
         "�nica compa�ia. ",
      "Est�s pudri�ndote en una de las celdas del bloque B de Gorband Ab-Trabasir. El sonido "
         "de las aguas del r�o y alguna que otra rata que se deja ver de vez en cuando son tu "
         "�nica compa�ia. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "Con frecuencia llegas a pensar que las ratas se rien de ti, tal vez sea "
         "ese el primer s�ntoma de que te encuentras al borde de la locura",
      "Con frecuencia llegas a pensar que las ratas se rien de ti, tal vez sea "
         "ese el primer s�ntoma de que te encuentras al borde de la locura"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
