/* Archivo base a partir del que se generan las descripciones de los callejones de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("Est�s en uno de los callejones de Noella pero no distingues nada en esta oscuridad.\n\n");
   add_item(({"casa", "casas"}), "Casas de piedra y adobe se encuentran a ambos lados de " +
        "la calle. Todas sus puertas y ventanas parecen estar cerradas.\n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(10);
   set_zone("noella");
   add_sound("pasos","Te paras a escuchar y consigues distinguir lo que parece ser el sonido de "
    "unos pasos. Parece como si cada vez estuviese m�s cerca el causante de tales sonidos.\n");

}
/* DESCRIPCIONES DE LOS CALLEJONES DE NOELLA EXCEPTO LA CALLE DEL LELE */

void long_desc_callejones()
{

string *descripciones1 = ({
      "Est�s en uno de los m�ltiples callejones de esta ciudad. Es un lugar que carece "
         "de iluminaci�n artificial exceptuando la que procede de las calles principales "
         "que comunica. ",
      "Los efectos de las sombras que las luces de las calles principales proyectan sobre "
         "estos oscuros callejones no hacen m�s que inspirarte una terrible sensaci�n de "
         "inseguridad. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "No acostumbra a ser un lugar frecuentado por criaturas de la superficie "
         "salvo por aquellas que conocen la ciudad como la palma de su mano. Deber�as mantener "
         "ojos bien abiertos",
      "Las criaturas de la suboscuridar acostumbran a moverse por estos callejones durante "
         "sus visitas a la ciudad. No ser�a extra�o que te topases con alguna o que alguno "
	 "de sus pu�ales se topase con tu espalda por casualidad"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
