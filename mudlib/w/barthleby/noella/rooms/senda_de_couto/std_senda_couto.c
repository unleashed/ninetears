/* Archivo base a partir del que se generan las descripciones de la senda de Couto */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No puedes ver nada en la senda con esta oscuridad.\n\n");
   add_item("arbustos", "Vegetaci�n peque�a t�pica del lugar como pueden ser zarzas " +
        "silvestres, helechos y alg�n que otro �rbol joven.\n");
   add_item(({"senda", "Senda"}),"Una senda sobre la tierra del ancho de una a dos " +
        "personas dependiendo de la zona, con hierbajos silvestres al ambos lados.\n");
   //add_smell(({"smellA","smellB","smellC"}),"Descripci�n bla, bla, bla.\n");
   set_light(40);
   set_zone("sendas");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LA SENDA DE COUTO */

void long_desc_couto()
{

string *descripciones1 = ({
      "Un estrecho camino bordeado por distintos arbustos y alguna que otra roca, "
         "que comunica las aldeas y pueblos pr�ximos a Noella, abierta por sus habitantes. ",
      "Caminas por una de las antiguas sendas que comunica la ciudad de Noella con las "
         "aldeas circundantes, no es una senda muy ancha pero si lo suficiente. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "Suele ser una v�a alternativa de acceso para viajeros y comerciantes o para alguien "
         "que pretenda pasar desapecibido",
      "Una senda con agradables vistas para los que buscan un agradable paseo"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
