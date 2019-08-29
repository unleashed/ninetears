/* By Shimmer adaptado By Thalos */

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "../../path.h"

inherit "/std/underground.c";

int n, init=0;

void base_desc()   
{
   add_item(({"puesto","puestos"}),"Es un puesto ambulante, hay tanta gente a su alrededor que no sientes mingun deseo de acercarte a el y ver que vende.\n"); 
   add_item("suelo", "El suelo esta formado por grandes bloques de granito, colocados de tal menra que resulta imposible distinguir donde acaba un bloque y donde empieza otro.\n");
   add_smell("aire","Un olor acre a multitudes, mezclado con el olor del cuero, de especias, frutas exoticas y otros productos traidos de lejanas tierras por los mercaderes.\n");               
   add_sound("mercado","El estruendo es terible en el marcado, con tanto comerciante pregonando sus mercancias y precios, asi como los regateos de los compradores que muchas veces acaban a gritos\n");
   set_light(70);
   set_zone("mercado");
   
 
}
void long_desc_mercado()
{

string *descripciones1 = ({"Este es el mercado de la ciudad, aqui puedes encontrar casi de todo, desde "
      "armas a comida. ",
 "Este es el mercado de la ciudad, aqui puedes ver la vida economica de la ciudad. ",
 "Estas en el mercado de Keroon, el sitio mas bullicioso de toda la ciudad, mires a donde mires solo ves puestos ambulantes llenos de gente admirando sus mercaderias.",
 "En este mercado se venden todos los productos que necesita la sociedad duergar, ves puestos de alegres colores por todos lados, los mercaderes gritan y "
      "chillan a los clientes para que se acerquen a ver sus mercancias. ",
 "Estas en el mercado de Keroon,los comerciantes pregonan a gritos la calidad y caracteristicas de sus mercacias, en un intento de atraer a los posibles compradores.",
 "Estas en el mercado de Keroon, aqui es donde tiene lugar gran parte del comercio de la ciudad, comerciantes, "
       "tenderos y clientes se reunen en la zona, unos para ofertar sus productos y otros para realizar sus compras."});
 
 string descripcion1;

 string *descripciones2 = ({"Con la multitud que pasa por aqui es facil cruzarse con algun ladronzuelo que te robe la bolsa, debes andar con mucho ojo. ",
 "Hay tanta gente, paseando por el mercado mientras realizan sus compras, que resulta dificil andar sin tropezar con alguno.",
 "Hay clientes regateando los precios a los mercaderes, ladrones intentando sacar tajada del bullicio y algun que otro guardia vigilando la zona sin mucho interes. ",
 "Si te acercas a alguno de los puestos es facil que encuentras algo de lo que necesitas. Otra cosa es que puedas permitirte sus precios."});
 string descripcion2;

 string *descripciones3 = ({"La mayoria de los mercaderes exponen sus mercancias en tenderetes de estridentes colores intentando que los clientes puedan verlos bien",
 "Algunos mercaderes exponen sus mercancias en el mismo suelo del mercado, otros tienen su propio tenderete con sus mercancias colgadas de el para que las puedan ver los clientes",
 "Debes tener ciudado con los mercaderes mas espabilados seguro que intentaran cobrarte el doble de lo que valen sus articulos"});
 
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}
