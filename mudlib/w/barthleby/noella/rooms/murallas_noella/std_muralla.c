/* Archivo base a partir del que se generan las descripciones de las murallas de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/room.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   add_item(({"antorcha", "altorchas","l�mpara","l�mparas","lampara","lamparas"}),"Numerosas antorchas y lamparas de " +
        "aceite iluminan toda la calle de la parte interior de la muralla.\n");
   add_item(({"columna", "columnas"}),"Grandes, fuertes y redondas columnas sirven como apoyo al " +
        "paso entre las almenas.\n");
   add_smell(({"aire","grasa","aceite"}),"El quemarse de antorchas y lamparas produce un profundo " +
         "olor a grasa y aceite quemados que permanece en el aire bajo la estructura abovedada.\n");
   set_light(70);
   set_zone("muralla");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LAS MURALLAS DE NOELLA */

void long_desc_muralla()
{

string *descripciones1 = ({
      "Te encuentras en la calzada interior de las murallas. ",
      "Est�s en la calzada interior de las murallas de Noella. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "Numerosas antorchas y l�mparas de aceite recorren las partes m�s elevadas "
         "de la muralla iluminando tanto la calle como la poderosa estructura "
         "interior de la muralla al mismo tiempo que inundan el aire con un "
         "fuerte olor a grasa y aceite quemados que resulta muy agradable para "
         "algunas de las criaturas que frecuentan la zona",
      "Se trata de una calle muy singular, pues parte de la muralla se encuentra "
         "sobre tu cabeza. La parte posterior del paso entre las almenas "
         "resulta ser una estructura abovedada que consigue cubrir por completo "
         "la calle, terminando en unas enormes columnas que le dan su "
         "estabilidad. Te preguntas si se habra construido as� para resguardar "
         "los puestos de los mercaderes en las epocas de lluvias o por motivos defensivos"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
