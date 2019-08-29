/* Archivo base a partir del que se generan las descripciones del camino nordeste de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("No distingues nada en esta oscuridad, pero sabes que te encuentras en uno de los accesos a Noella.\n\n");
   add_item("camino","Es un camino lo suficientemente ancho como para un gran carro " +
        "que se va estrechando cada d�a m�s por el lento pero imparable avance de " +
        "la vegetaci�n de sus bordes. \n");
   add_item("vegetaci�n","Puedes ver como la densa y frondosa vegetaci�n a ambos lados del camino " +
        "amenaza con engullirlo. \n");
   //add_smell("loquesea","Descripci�n bla, bla, bla.\n");
   set_light(40);
   set_zone("caminos");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DEL CAMINO NORDESTE */

void long_desc_cne()
{

string *descripciones1 = ({
      "Una de las principales v�as de comunicaci�n de Noella con el exterior. Se "
         "trata de un camino empedrado pero no muy bien cuidado, con una frondosa "
         "vegetaci�n a los bordes del mismo. ",
      "Te encuentras en el acceso del nordeste a la ciudad de Noella. Puedes o�r el chasquido "
         "que tus pies producen sobre el camino empedrado mientras caminas. Cuando la vegetaci�n "
         "de los bordes del camino lo permite, hay una bonita vista de la ciudad desde aqu�. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "Dicha vegetaci�n amenaza cada d�a m�s con engullirlo, por mucho que las gentes de "
         "Noella, al sudoeste del camino, se empe�en en limpiarlo amenudo",
      "Te preguntas c�mo el gobierno y los habitantes de la ciudad no ponen un poco m�s "
         "de empe�o en adecentar con mayor frecuencia el camino y devolverle as� el hermoso "
         "aspecto que debi� tener en su d�a"
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
