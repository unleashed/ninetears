/* By Shimmer */

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "../../path.h"

inherit "/std/outside.c";

int n, init=0;

void base_desc()   
{
   set_dark_long("Solo sabes que te encuentras en la ciudad de Brethem.\n\n");
   add_item("suelo", "El suelo esta formado por pequenyos adoquines.\n");   
   add_smell("aire","Un olor fresco y humedo te imprenga cuando te paras a respirar profundamente.\n");               set_light(50);
   set_zone("brethem");
   add_sound("ciudad","Cuando te paras tranquilamente a escuchar, puedes oir el bullicio de la "
    "gente que va y viene por las calles de la ciudad\n");

}
void long_desc()
{

 string *ciudades = ({"ciudad de paso de numerosos viajeros y aventureros de distintas razas",
 "es una gran ciudad en la que conviven gentes de diversas razas, por lo que suele haber altercados a menudo",
 "ciudad grande y bonita donde las haya",
 "es una de las ciudades mas bellas que has visto en tus viajes",
 "si miras alrededor puedes ver lo majestuosa que es la ciudad",
 "una de las ciudades mas grandes y antiguas del reino",
 "un conjunto de casas de planta baja",
 "unas casas con muchas ventanas",
 "alguna que otra casa al lado de la calle",
 "unas bonitas casas"});
 string ciudad;
 string *descripciones = ({"altas casas bastante ciudadas",
 "algunas casas pequenyas",
 "unas cuantas casas de piso bajo",
 "varios edificios y casas",
 "una solitaria casa al lado de la calle",
 "algunos edificios bastante altos",
 "un conjunto de casas de planta baja",
 "unas casas con muchas ventanas",
 "alguna que otra casa al lado de la calle",
 "unas bonitas casas"});
 string descripcion;
 string *descripciones2 = ({"varios humanos",
 "algunos elfos",
 "unos cuantos halflinos",
 "una pareja de orcos",
 "unos pocos enanos",
 "unos hombres-lagarto",
 "algunos drows",
 "una pareja de humanos",
 "algunos enanos",
 "varios halflinos",
 "unos pocos orcos",
 "dos hombres-lagarto",
 "tres drows",
 "unos humanos",
 "una pareja de duergars",
 "varios duergars"});
 string descripcion2;
 string *descripciones3 = ({"tener una discusion",
 "charlar tranquilamente",
 "intentar pasar desapercibidos",
 "nerviosos con tu presencia",
 "ocupados en sus tareas",
 "estar tramando algo",
 "mirarte amenazantemente",
 "hablar sin tapujos unos con otros",
 "alborotarse con tu presencia",
 "asustarse al verte",
 "discutir a algo a gritos",
 "temer algo con tu presencia"});
 string descripcion3;
 string *descripciones4 = ({" gato maulla y sale corriendo despavorido al verte",
 " perro te ladra fuertemente al ver como te acercas",
 " pajaro escapa volando cuando te acercas",
 " ninyo se asusta cuando vuestras miradas se cruzan",
 "a ninya se pone a lloriquear asustada al verte",
 "a mujer te saluda efusivamente dandote la bienvenida",
 "a ninya se va corriendo por la calle al verte llegar",
 " ninyo se va corriendo asustado mientras te grita insultandote",
 " perro escapa ladrando cuando te ve",
 " gato se espanta cuando sin querer le pisas el rabo",
 " pequenyo raton escapa a un agujero pasandote entre las piernas",
 " senyor te saluda desde una ventana dandote la bienvenida a la ciudad",
 " senyor sonrie al verte llegar",
 "a mujer sonrie cuando la miras",
 "a mujer te mira de arriba abajo y maldice unas cuantas palabras"});
 string descripcion4;
 string *descripciones5 = ({"una alta verja",
 "un gran seto",
 "un pequenyo muro de piedra",
 "una larga verja de metal",
 "una verja de madera",
 "una cerca de madera",
 "un alto muro ",
 "una verja baja",
 "una hilera de columnas",
 "un muro alto de piedras "});
 string descripcion5;
 string *descripciones6 = ({"es preciosa",
 "es muy bonita",
 "llama tu atencion por su belleza",
 "esta bastante limpia",
 "te gusta bastante",
 "parece tranquila",
 "esta muy tranquila",
 "te parece bastante tranquila",
 "es grande y bonita",
 "te gusta por su tranquilidad",
 "te asombra por su tranquilidad",
 "parece estar bien cuidada por sus habitantes",
 "parece estar tranquila a estas horas"});
 string descripcion6;

 descripcion6=descripciones6[random(sizeof(descripciones6))];
 descripcion5=descripciones5[random(sizeof(descripciones5))];
 descripcion4=descripciones4[random(sizeof(descripciones4))];
 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion=descripciones[random(sizeof(descripciones))];
 ciudad=ciudades[random(sizeof(ciudades))];

set_long("Te encuentras en Brethem, "+ciudad+". A una lado puedes ver "+descripcion+". Delante, a un lado "
  "observas "+descripcion2+" que parecen "+descripcion3+". Un"+descripcion4+" y en frente "+descripcion5+" custodia algunos terrenos. La ciudad "+descripcion6+".\n\n");

}

void crea_bichos()
{
   int tipo, i;

   n=random(4);
   for (i=0; i<n; i++)
   {
      tipo=random(12);
      switch (tipo)
      {
         case 0: add_clone(BRETHEM+"npcs/guardian", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/drow", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/humano", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/duergar", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/pajaro", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/guardian", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 8: add_clone(BRETHEM+"npcs/orco", 1);
                 break;
         case 9: add_clone(BRETHEM+"npcs/hombrelagarto", 1);
                 break;
         case 10: add_clone(BRETHEM+"npcs/nomada", 1);
                 break;
         case 11: add_clone(BRETHEM+"npcs/halflino", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}

