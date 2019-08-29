/* Archivo base a partir del que se generan las descripciones de los parques de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("La oscuridad que inunda el parque no te permite ver nada.\n\n");
   add_item(({"camino","caminos"}),"Los caminos de este parque est�n cubiertos por una gravilla " +
        "blanca que cruge al caminar sobre ella.\n");
   add_item("magnolios","Grandes y anticu�simos magnolios pueblan todo este parque, sus ramas y " +
        "hojas crean un techo natural que protege del agua en d�as de lluvia.\n");
   add_item(({"construcciones","aparato","aparatos"}),"Hay numerosos y extra�os aparatos por aqu� " +
        "que son utilizados por los ni�os y ni�as para sus juegos, algunos en forma de " +
        "balancines, rampas, peque�as torres de madera y cosas por el estilo.\n");
   add_item(({"arboles","�rboles","alamos","�lamos","sauces","palmeras"}),"Los �rboles de este parque est�n colocados " +
        "de forma que las clases de estos queden intercaladas. Sea cual sea la �poca del a�o, " +
        "Suleithel hace bailar sus ramas continuamene.\n");
   add_item("suelo","Las piedras que forman el suelo deber�an hacer un claro dibujo que, debido a " +
        "la falta de muchas de ellas y otras sueltas que no se encuentran en su lugar, resulta " +
        "inidentificable.\n");
   //add_smell(({"smellA","smellB","smellC"}),"Descripci�n bla, bla, bla.\n");
   set_light(40);
   set_zone("parques");
   //add_sound("loquesea","Descripci�n bla, bla, bla.\n");

}
/* DESCRIPCIONES DE LOS PARQUES DE NOELLA, CARCHANIM*/

void long_desc_carchanim()
{

string *descripciones1 = ({
      "Unos gigantescos y anticu�simos magnolios presiden estos parques, es un paisaje "
         "maravilloso el que se contempla aqu� cuando los �rboles florecen. Los caminos de los "
         "parques estan recubiertos con una gravilla blanca que produce un caracter�stico "
         "crujido al caminar. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "En en la parte este del parque se encuentra una fuente con la estatua de Carchan�m en el centro"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
/* DESCRIPCIONES DE LOS PARQUES DE NOELLA, RECREO*/

void long_desc_recreo()
{

string *descripciones1 = ({
      "Est�s en la zona de la ciudad destinada a los juegos de los m�s j�venes de la misma. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "Puedes ver extra�as construcciones y aparatos destinados a ser los juguetes de los "
         "ni�os, algunos est�n oxidados y resultan peligrosos pero a nadie parece preocuparle "
         "demasiado. Por las noches se pueden ver algunas parejas por la zona"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
/* DESCRIPCIONES DE LOS PARQUES DE NOELLA, SULEITHEL*/

void long_desc_suleiyhel()
{

string *descripciones1 = ({
      "El Paseo de Suleithel ha tomado su nombre del viento fr�o del noreste que sopla en "
         "la regi�n durante todo el a�o. Aqu� Suleithel hace bailar las copas de los alamos, "
         "sauces y ex�ticas palmeras de todo el paseo. "
      /*" "
         ". "*/
      });
 string descripcion1;

 string *descripciones2 = ({
      "El suelo empedrado est� en perpetua "
         "reparaci�n debido a que el gobierno de Noella nunca se ha afanado en reparalo "
         "debidamente, alegando que supone un excesivo gasto, aunque todos saben que reparalo "
         "continuamente supone un gasto mayor. En d�as lluviosos es imposible no mojarse a "
         "causa de las piedras mal asentadas"
      /*""
         ""*/
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
