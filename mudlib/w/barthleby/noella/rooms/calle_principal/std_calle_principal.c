/* Archivo base a partir del que se generan las descripciones de la calle principal de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No distingues nada en esta oscuridad.\n\n");
   //add_item(({"itemA", "itemB"}), "Descripci�n bla, bla, bla.\n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(70);
   set_zone("noella");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LA CALLE PRINCIPAL DE NOELLA, YCKULL */

void long_desc_calleYckull()
{

string *descripciones1 = ({
      "Est�s ante la calle m�s grande e importante de Noella. Atraviesa la ciudad por "
         "el centro de la misma de norte a sur. La ancha calle est� completamente "
         "adoquinada; sus adoquines estan colocados de forma que se distingue claramente "
         "el dibujo de miles de lenguas b�fidas. "
      /*" ",
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "La calle est� densamente transitada a "
         "todas horas, ser�a prudente evitar la parte central para no ser arrollado por "
         "ning�n caballo o carro"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
/* DESCRIPCIONES DE LA CALLE PRINCIPAL DE NOELLA, DELAMARTH */

void long_desc_calleDelamarth()
{

string *descripciones1 = ({
      "Delamarth 'Destino al Horror' fue el nombre dado por los elfos al camino sobre "
         "el que fue constru�da esta calle. Cuenta la leyenda que al final la misma se "
         "encontraba la morada de Guima, un horrible monstruo que vigilaba el camino. "
      /*" ",
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "Guima hac�a una pregunta diferente cada vez a quien se le cruzaba, y solo los "
         "que daban una respuesta acorde con la que el monstruo cre�a cierta, lograban "
         "salvarse de caer en sus fauces"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
