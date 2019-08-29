/* By Shimmer adaptado By Thalos */

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "../../path.h"

inherit "/std/underground.c";

int n, init=0;

void base_desc()   
{
   add_item("suelo", "Ves una alfomra de musgos y liquenes con algunas setas y hongos dispersos alrededor de un camino un tanto embarrado.\n");   
   add_smell("aire","Un olor fresco y humedo te impregna cuando te paras a respirar profundamente.\n");               
   set_light(40);
   set_zone("parque");
   

}
void parque_desc()
{

 string *parques = ({"en un parque lleno de setas y hongos",
 "si miras alrededor puedes ver un bello parque",
 "estas en el corazon verde de la ciudad",
 "no esperabas encontrarte un parque en medio de la ciudad",
 "es dificil de imaginar un sitio como este aqui"});
 string parque;
 
 string *descripciones = ({"bancos para que se sienten las parejitas",
 "algunos hongos dispersos",
 "una gran seta de varios metros de altura",
 "varios hongos y setas",
 "un solitario hongo",
 "un camino lleno de moho y liquenes",
 "un bello camino empedrado",
 "un camino lleno de barro"});
 string descripcion;
 
 string *descripciones2 = ({"varios chulos",
 "algunas prostitutas",
 "unos cuantos goblins",
 "una pareja de orcos",
 "unos pocos medio-orcos",
 "unos duergars",
 "algunos chulos",
 "una pareja de prostitutas",
 "algunos orcos",
 "varios goblins",
 "unos pocos orcos",
 "unas prostitutas",
 "una pareja de duergars",
 "varios duergars"});
 string descripcion2;
 
 string *descripciones3 = ({"tener una discusion",
 "charlar tranquilamente",
 "intentar buscar clientes",
 "ocupados en sus tareas",
 "estar tramando algo",
 "mirarte amenazantemente",
 "hablar sin tapujos unos con otros",
  "asustarse al verte",
 "discutir a algo a gritos"});
 string descripcion3;
 
 string *descripciones4 = ({"es precioso",
 "es muy bonito",
 "llama la atencion por su belleza",
 "esta bastante limpio, cosa extranya",
 "te gusta bastante",
 "parece tranquilo",
 "esta muy tranquilo",
 "te parece bastante tranquilo",
 "es grande y bonito",
 "te asombra por su tranquilidad",
 "parece estar tranquila a estas horas"});
 string descripcion4;
 
 descripcion4=descripciones4[random(sizeof(descripciones4))];
 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion=descripciones[random(sizeof(descripciones))];
 parque=parques[random(sizeof(parques))];

set_long(short_d+"\n\nTe encuentras en Keroon, "+parque+".Su nombre esta dedicado a todos aquellos valerosos duergars que derramaron su sangre por la mayor gloria de Keroon."
  "A una lado puedes ver "+descripcion+". Delante, a un lado observas "+descripcion2+" que parecen "+descripcion3+". El parque "+descripcion4+".\n\n");

}
