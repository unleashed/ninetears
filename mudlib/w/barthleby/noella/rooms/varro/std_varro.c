/* Archivo base a partir del que se generan las descripciones de Varro */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No puedes ver nada con esta oscuridad.\n\n");
   //add_item("loquesea", "Descripci�n.\n");
   //add_smell(({"smellA","smellB","smellC"}),"Descripci�n bla, bla, bla.\n");
   set_light(30);
   set_zone("varro");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE VARRO */

void long_desc_varro()
{

string *descripciones1 = ({
      "Nadie recuerda ya el objeto que estas minas pudieron haber tenido, ni el n�mero de "
         "trabajadores desaparecidos. Se dice que las desapariciones coincidieron con la llegada "
         "de las criaturas de arcilla. Lo que es seguro, es que desde la llegada de la m�s grande "
         "de todas, la que se hace llamar a si misma Barthaur-Rog, nadie ha vuelto a trabajar en "
         "la zona. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "Te resulta m�s y m�s dificil andar en la arcilla",
      "Tus pies se hunden cada vez m�s a medida que avanzas"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
