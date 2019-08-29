/* By Shimmer adaptado By Thalos */

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "../../path.h"

inherit "/std/suboscuridad.c";

int n, init=0;

void base_desc()   
{
   add_item("suelo", "Ves una alfomra de cuidados musgos y liquenes de diversos colores con algunas setas y hongos dispersos alrededor de un camino empedrado cuidado con gran esmero.\n");   
   add_smell("aire","Un olor fresco y humedo te impregna cuando te paras a respirar profundamente.\n");               
   set_light(40);
   set_zone("jardines""keroon_rico");
   

}
void jardines_desc()
{

 string *parques = ({"en un jardincillo lleno de setas y hongos",
 "si miras alrededor puedes ver un bello jardin",
 "estas en el corazon verde de la parte alta de la ciudad ciudad",
 "no esperabas encontrarte unos jardines de tal belleza en la ciudad"});
 string parque;
 
 string *descripciones = ({"bancos para que se sienten las parejitas",
 "algunos hongos dispersos",
 "una bella fuente con un chorrito para beber agua"
 "una gran seta de varios metros de altura",
 "varios hongos y setas",
 "un solitario hongo",
 "un bello camino empedrado"});
 string descripcion;
 
 string *descripciones2 = ({"varios jovenes charlando",
 "algunos ninyos jugando",
 "un soldado disfrutando de la tarde",
 "una pareja de novios, acampanyados por una carabina",
 "un grupo de ninyera charlando animadamente, mientras vigilan a sus pequenoys",
 "un soldado ligandose a un preciosa jovencita",
 "varios ancianos duergars discutiendo de politica o algun otro tema",
 "varios duergars"});
 string descripcion2;
 
 string *descripciones3 = ({"son preciosos",
 "son muy bonitos",
 "llaman la atencion por su belleza",
 "estan limpios y cuidados",
 "te gustan mucho",
 "son muy tranquilos",
 "son ideales para descansar un rato y olvidarse de las preocupaciones",
 "es grande y bonito",
 "son bellos y armoniosos",
 "su tranquilidad contrasta, con el bullicio del resto de la ciudad"});
 string descripcion3;
 
 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion=descripciones[random(sizeof(descripciones))];
 parque=parques[random(sizeof(parques))];

set_long(short_d+"\n\nTe encuentras en los jardines reales, "+parque+".en estos jardines los duergars de clase pudientas se dedican a pasear y descansar de sus tribulaciones diarias, mientras sus hijos se dedican a jugar en las amplias avenidas."
  "A una lado puedes ver "+descripcion+". Delante, a un lado observas "+descripcion2+". Los jardines "+descripcion3+".\n\n");

}
