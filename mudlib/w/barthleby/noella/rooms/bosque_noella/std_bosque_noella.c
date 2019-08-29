/* Archivo base a partir del que se generan las descripciones del bosque de Noella */

#define CREATOR "barthleby"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "/w/barthleby/path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()
{
   set_dark_long("La absoluta oscuridad que te envuelve no te permite ver nada, solo sabes que te encuentras en el bosque.\n\n");
   add_item(({"camino", "Camino"}),"El t�pico camino de trierra salpicado de piedras " +
        "erosionadas por estar a la intemperie y por el espor�dico paso de animales " +
        "y caminantes a lo largo de los a�os.\n");
   add_item(({"rama", "ramas", "arbol", "arboles", "bosque", "�rbol", "�rboles", "vegetaci�n"}), 
        "Un claro y limpio bosque de con�feras " +
        "que alberga sin duda una rica fauna aut�ctona. Se trata de un paraje digno " +
        "de ser contemplado con tranquilidad en noches claras de luna llena, a " +
        "pesar incluso del alto grado de humedad de la zona.\n");
   add_smell("aire","Un olor fresco y h�medo te imprenga cuando te paras a respirar profundamente.\n");
   set_light(40);
   set_zone("bosque_noella");
   add_sound("murmullo","Cuando te paras tranquilamente a escuchar, puedes oir el murmullo que produce el viento "
    "entre las ramas de los �rboles.\n");

}
/* DESCRIPCIONES CALLE DEL MAR */

void long_desc_bosque_noella()
{

string *descripciones1 = ({
      "El camino atraviesa las partes m�s altas de los bosques que circundan la "
         "ciudad de Noella. Trazado en tiempos inmemoriales con el fin de encontrar "
         "un paso sobre el Trabasir lo suficientemente alejado de Noella para llevar a "
         "cabo con �xito el traslado de tropas numerosas sin ser detectadas. ",
      "El aire que se respira en las partes del bosque por las que discurre este camino es realmente "
         "puro. De vez en cuando es necesario sortear alg�n que otro arbusto o piedra lo que hace un "
         "poco m�s ameno tu paseo por este bosque. "
      });
 string descripcion1;

 string *descripciones2 = ({
      "A tu alrededor puedes ver como las ramas de los �rboles "
         "que pueblan este bosque danzan placidamente a causa del viento, lo que produze un murmullo adormezedor "
         "que te acompa�a a lo largo del camino",
      "A veces logras distinguir unas formas sombr�as entre los �rboles que identificas con las de alg�n "
         "animal temeroso de ser localizado. Tal vez sea as�, o tal vez no.."
      });
 string descripcion2;


 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+".\n\n");
}
