/* Archivo base a partir del que se generan las descripciones de Sabardes */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No puedes ver nada con esta oscuridad.\n\n");
   add_item(({"ru�nas","ruinas"}),"Unas pocas piedras invadidas por los arbustos es todo lo que queda " +
        "de las casas que hubo en este lugar, pero parece que dos construcciones " +
        "adyacentes permanecen en un considerable buen estado.\n");
   //add_smell(({"smellA","smellB","smellC"}),"Descripci�n bla, bla, bla.\n");
   set_light(40);
   set_zone("sendas");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE SABARDES */

void long_desc_sabardes()
{

string *descripciones1 = ({
      "Hace tiempo esto fue una aldea bastante habitada considerando su tama�o y "
         "situaci�n. Pero la cercan�a de la ciudad hizo que los m�s jovenes fuesen "
         "abandonando el lugar paulatinamente, lo que conllevo un envejecimiento de la "
         "poblaci�n y finalmente la desparici�n de esta. ",
      "Te encuentras en un lugar que en su d�a fue muy valorado por magos, hechizeros "
         "y alquimistas debido a la gran abundancia de extra�as plantas y hierbajos "
         "que serv�an de reactivos para pociones y hechizos. Aunque hace ya tiempo que "
         "todo eso fue olvidado. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "Observando las ru�nas puedes hacerte una idea de como era el lugar en el pasado",
      "Las ru�nas del lugar traen a tu mente la imagen de una vida llena de paz y "
         "tranquilidad que debieron haber llevado sus habitantes en el pasado"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
