/* Archivo base a partir del que se generan las descripciones del mercado de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No puedes ver nada con esta oscuridad.\n\n");
   add_item(({"puesto","puestos","tienda","tiendas"}),"Numerosos tenderetes con techos de " +
        "tela o al aire libre inundan esta gran plaza. Mercaderes de casi todas las " +
        "razas conocidas se reparten los puestos del lugar, lo que produce inevitables " +
        "y frecuentes disputas.\n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(70);
   set_zone("mercado");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DEL MERCADO */

void long_desc_mercado()
{

string *descripciones1 = ({
      "Ante ti se encuentra el lugar, junto con las tabernas, m�s concurrido de la "
         "ciudad, puedes encontrar casi cualquier cosa que deses en alguno de sus puestos, "
         "a veces, incluso se ven objetos �nicos de dudosa procedencia. ",
      "El mercado de Noella se caracteriza por la dudosa procedencia tanto de los mercaderes "
         "como de sus productos. Si observas con atenci�n te dar�s cuenta de que los "
         "vendedores de armas no tienen pinta de herreros, ni los due�os de las panader�as "
	 "parecen panaderos, etc... Es m�s dir�as que todos parecen ser coleccionistas, "
	 "coleccionistas de lo ajeno, por supuesto. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "En este lugar son frecuentes los empujones ante los puestos fruto del �mpetu que "
         "demuestran algunos clientes por hacerse con la ganga del d�a",
      "Deber�as tener cuidado de no tropezar, pues no es extra�o que se caiga alg�n cliente "
         "o que alguien le ayude a caerse a tu monedero"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
