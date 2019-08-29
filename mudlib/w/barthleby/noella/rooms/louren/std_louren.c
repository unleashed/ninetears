/* Archivo base a partir del que se generan las descripciones de Louren */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No puedes ver nada con esta oscuridad, tan solo sabes que est�s en Louren.\n\n");
   add_item(({"casas", "casa"}),"Construcciones relativamente peque�as de paredes de " +
        "adobe y techos de paja, conforman el conjunto de viviendas de este lugar.\n");
   add_item(({"laurel", "laureles"}),"Resulta sorprendente el tama�o que estos arbustos " +
        "llegan a alcanzar aqu�, asi como la forma en que mantienen su " +
        "extraordinaria frescura durante todo el a�o.\n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(50);
   set_zone("louren");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LOUREN */

void long_desc_mercado()
{

string *descripciones1 = ({
      "Es un peque�o pueblo formado por cinco o seis casas cuyos habitantes viven de "
         "sus campos y el comercio. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "El verde oscuro e intenso, y el olor de los laureles "
         "frescos y frondosos presentes en la zona en grandes cantidades, hace que las "
         "visitas a este lugar resulten agradables"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
