/* ESTE ES EL ARCHIVO BASE A PARTIR DEL CUAL SE GENERAN LAS DESCRIPCIONES DE LAS ROOMS, NPCS Y DEMAS DE BRETHEM */


/* By Shimmer */

#define CREATOR "shimmer"

/* Genera automaticamente varias descripciones para las rooms de la ciudad y crea los npcs correspondientes */

#include "../../path.h"

inherit "/std/outside.c";


int n, init=0;

/* DESCRIPCIONES BASICAS DE LAS ROOMS */

void base_desc()   
{
   set_dark_long("Esta todo muy oscuro y solo sabes que te encuentras en la ciudad de Brethem.\n\n");
   add_item("suelo", "El suelo esta formado por pequenyos adoquines.\n");   
   add_smell("aire","Un olor fresco y humedo te imprenga cuando te paras a respirar profundamente.\n");
   set_light(70);
   set_zone("brethem");
   add_sound("ciudad","Cuando te paras tranquilamente a escuchar, puedes oir el bullicio de la "
    "gente que va y viene por las calles de la ciudad\n");

}

/* DESCRIPCIONES PARA LAS CALLES IMPORTANTES DE LA CIUDAD */

void long_desc()
{

 string *ciudades = ({"ciudad de paso de numerosos viajeros y aventureros de distintas razas",
 "es una gran ciudad en la que conviven gentes de diversas razas, por lo que suele haber altercados a menudo",
 "ciudad grande y bonita donde las haya",
 "es una de las ciudades mas bellas que has visto en tus viajes",
 "si miras alrededor puedes ver lo majestuosa que es la ciudad",
 "una de las ciudades mas grandes y antiguas del reino",
 "ciudad en la que numerosas razas intentan convivir armoniosamente",
 "unas de las mas antiguas ciudades en la que numerosas razas son bienvenidas siempre y cuando no causen problemas",
 "te maravillas ante la belleza y la majestuosidad de esta ciudad, miras a tu alrededor y quedas extasiado",
 "la ciudad mas bella de todas en las que has estado"});
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

set_long(short_d+"\n\nTe encuentras en Brethem, "+ciudad+". A un lado puedes ver "+descripcion+". Delante, a un lado "
  "observas "+descripcion2+" que parecen "+descripcion3+". Un"+descripcion4+" y en frente, "+descripcion5+" custodia algunos terrenos. La ciudad "+descripcion6+".\n\n");

}



/* NPCS VARIOS PARA LAS CALLES IMPORTANTES */

void crea_npcs()
{
   int tipo, i;

   n=random(5);
   for (i=0; i<n; i++)
   {
      tipo=random(21);
      switch (tipo)
      {
         case 0: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/noble", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/pajaro", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 8: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 9: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 10: add_clone(BRETHEM+"npcs/nomada", 1);
                 break;
         case 11: add_clone(BRETHEM+"npcs/noble", 1);
                 break;
         case 12: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 13: add_clone(BRETHEM+"npcs/pajaro", 1);
                 break;
         case 14: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 15: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 16: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 17: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 18: add_clone(BRETHEM+"npcs/noble", 1);
                 break;
         case 19: add_clone(BRETHEM+"npcs/nomada", 1);
                 break;
         case 20: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
      }
   }
}

/* DESCRIPCIONES CALLE DEL MAR */

void long_desc_callemar()
{

string *descripciones1 = ({"Te encuentras en la calle mas al sur de Brethem, discurre siguiendo la line de la "
      "costa pegada al mar, puedes ver las olas rompiendo contra las rocas que protegen la zona. ",
 "Estas en la calle del mar, recibe este nombre por la cercania del oceano, la calle discurre paralela al mismo "
      "hasta la entrada del puerto, en esta zona las casas son mas bajas y descuidadas, propias de los pescadores. ",
 "Ante ti se abre una amplia y larga calle que discurre pegada a la linea del mar, las pequenyas casas de "
       "los pescadores se amontonan al otro lado de la calle. "});
 string descripcion1;

 string *descripciones2 = ({"A tu alrededor puedes ver como los pescadores mueven sus aparejos de un lado para "
        "otro sin cesar y como charlan acerca de sus aventuras y peripecias en el mar. ",
 "Ves varios grupos de pescadores charlando al borde de la calzada, cuantan historias de marineros y viajes por el "
        "ancho mar. ",
 "Unos cuantos pescadores charlan cerca de ti contando historias sobre el mar y las aventuras de otros pescadores "
        "mientras otros mueven aparejos de pesca de un lado para otro. "});
 string descripcion2;

 string *descripciones3 = ({"Las gaviotas y los gatos buscan sin cesar restos de pescado que llevarse a la boca "
         "peleandose entre ellos por los restos que los pescadores tiran",
 "Puedes ver como las gavionas sobrevuelan la zona buscando algunos restos de las capturas del dia que los pescadores "
         "puedan haber tirado",
 "Un conjunto de gaviotas se pelean por unos trozos de pescado podrido en una esquina, mientras los gatos acechan "
         "para hacerse con los restos"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}

/* DESCRIPCIONES PARA EL PUERTO */


void long_desc_puerto()
{

string *descripciones1 = ({"Estas en la zona portuaria de Brethem, un enorme saliente construido sobre unas rocas "
      "en plena costa, el agua choca contra el rompeolas que protege el puerto de la ciudad produciendo una espesa "
      "espuma blanca que lo cubre todo. ",
 "Te encuentras en el puerto, una zona creada artificialmente sobre unas grandes rocas que fueron cubiertas y "
      "rellenadas hasta formar una especie de saliente ganado al mar, una brisa fria y cargada con la espuma "
      "producida por las olas al romper te pega en la cara continuamente. ",
 "Ante ti se abre una amplia y larga explanada construida sobre unas grandes rocas, el puerto de Brethem, a los "
      "lados puedes ver como el mar rompe fuertemente contra las rocas. "});
 string descripcion1;

 string *descripciones2 = ({"En la parte interior del puerto, la que da a la pequenya ensenada protegida por el "
        "rompeolas numerosas barcas y chalanas se balancean suavemente al ritmo que marcan las olas.",
 "Puedes ver algunas barcas aboyando en la ensenada del puerto, cargadas con los aparejos de pesca y balanceandose "
        "al compas de las olas.",
 "Algunas barcas se mecen al son de las olas en la parte interior del puerto, si te fijas en ellas puedes ver "
        "los aparejos de pesca dispuestos sobre ellas. "});
 string descripcion2;

 string *descripciones3 = ({"Los pescadores y marineros contemplan el mar esperando a que amaine su constante "
         "y fuerte batir para poder salir a faenar con sus barcas",
 "A tu alrededor ves como los marineros y pescadores maldicen y sueltan palabrotas quejandose por las escasas "
         "capturas de pescado que tienen en los ultimos tiempos",
 "Ves como los marineros y pescadores atareados organizan y arreglan sus aparejos de pesca y como numerosas  "
         "gaviotas revolotean alrededor buscando restos de pescado por todo el puerto"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}

/* DESCRIPCIONES PARA CALLEJONES Y CALLES PEQUE�AS */


void long_desc_callejon()
{

string *descripciones1 = ({"Caminas por una callejuela de la ciudad de Brethem, ante ti se elevan altas casas "
      "que apenas dejan que asome el sol un poco por encima de sus tejados. ",
 "Estas en uno de los numerosos callejones de los que cuenta la ciudad, es una calle estrecha y tortuosa que "
      "une otras dos calles mas importantes, estos callejones son unas de las zonas mas peligrosas de la ciudad. ",
 "Te encuentras en un callejon estrecho y oscuro que lleva a alguna otra calle importante de la ciudad, las casas "
      "son altas y viejas y te da la sensacion de que este no es un lugar muy seguro para perderse. "});
 string descripcion1;

 string *descripciones2 = ({"Las casas son de piedra, frias y oscuras, parecen bastante humedas, ya que el sol "
        "apenas da en estos callejones. ",
 "En estos callejones no notas tanto el bullicio de las calles transitadas de la ciudad, aqui el ajetreo es menor. ",
 "Es un callejon oscuro y humedo por el que apenas pasa gente, debes tener ciudado con los delincuentes que suelen "
        "esconderse en sitios como este. "});
 string descripcion2;

 string *descripciones3 = ({"Puedes ver algunos perros y gatos abandonados buscando comida entre los despojos "
         "que amontonan los habitantes en las esquinas, el mal olor te hace tener ganas de salir rapido de aqui",
 "Perros y gatos vagan por estos callejones buscando algo de alimento que llevar a sus bocas mientras notas como "
         "desde algunas ventanas eres vigilado constantemente",
 "Algunos ciudadanos se cruzan contigo al pasar por aqui, cuando estan a tu altura te saludan con la "
         "mirada y continuan su camino"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}

/* DESCRIPCIONES CALLE DEL MONUMENTO */

void long_desc_monumento()
{

string *descripciones1 = ({"Estas en la calle que conduce al Monumento a Shimmer, uno de los heroes "
      "mas importantes de la ciudad. ",
 "Esta calle te conduce al Monumento a Shimmer, famoso heroe antiguo de la ciudad, estas en una calle formada "
      "por adoquines de muchos colores, salteados unos con otros.",
 "Ante ti se abre una amplia y larga calle que discurre hasta el Monumento al heroe Shimmer, es una calle amplia "
       "y muy transitada a pesar de no tener salida."});
 string descripcion1;

 string *descripciones2 = ({"Gentes de distintas razas vienen y van por la calle de un lado para otro continuamente, "
        "la mayoria de ellos simplemente para ver el monuemnto.",
 "Numerosas personas pasan sin parar por esta calle hacia el monumento con la simple idea de contemplar su "
        "fantstica belleza.",
 "Unas cuantas personas charlan cerca de ti contando historias sobre Shimmer y sus aventuras recordando la historia "
        "de la propia ciudad. "});
 string descripcion2;

 string *descripciones3 = ({"En esta calle casi todos los edificios son altos y tienen sus fachadas adornadas "
         "con bandas y telas de colores con escudos dibujados.",
 "La calle te transmite una sensacion de paz y tranquilidad al ver toda la gente desfilando uniformemente hacia el "
         "monumento",
 "Es una calle tranquila y pacifica en la que apenas hay altercados y esta muy decorada por todos lados, con casas, "
         "puertas y balcones todos adornados. "});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}


/* DESCRIPCIONES BARRIOS BAJOS */

void long_desc_barrios_bajos()
{

string *descripciones1 = ({"Estas en los barrios bajos de la ciudad, estas calles son estrechas y  "
      "sucias, las casas descuidadas y sucias dan un aspecto que atemoriza al que pasa. ",
 "Los barrios bajos de la ciudad son la zona mas peligrosa de la misma, aqui las calles estan sucias y "
      "descuidadas y las casas son bajas y pequenyas. ",
 "Estas en una calle estrecha de los barrios bajos de la ciudad, aqui todo es mas oscuro y peligroso, las "
       "casas estan muy descuidadas y sucias. "});
 string descripcion1;

 string *descripciones2 = ({"Por aqui apenas pasan mas que borrachos, delincuentes y algun que otro ciudadano "
        "descuidado que no sabe donde se mete. ",
 "Puedes ver borrachos y deliencuentes que se te quedan mirando atontados preguntandose que pintas tu por aqui, "
        "sera mejor que te andes con ciudado. ",
 "La zona es muy peligrosa debido a los delincuentes y ladrones que andan sueltos por aqui. Los guardias de "
        "la ciudad apenas vigilan esta zona. "});
 string descripcion2;

 string *descripciones3 = ({"Algunos perros y gatos abandonados corretean de un lado para otro intentando pillar "
         "alguna de las ratas que infestan la zona",
 "Ratas gordas te pasan por delante escapando de los perros y gatos abandonados y hambrientos que infestan la zona "
         "y la convierten en desagradable",
 "En esta zona parece que no conocen el significado de las palabras limpieza y cuidado, solo el olor ya te produce "
         "nauseas y dolores"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}


/* DESCRIPCIONES MERCADO */

void long_desc_mercado()
{

string *descripciones1 = ({"Este es el mercado de la ciudad, aqui puedes encontrar casi de todo, desde "
      "armas a comida. ",
 "En este mercado se venden muchas cosas diversas, ves puestos por todos lados, los tenderos gritan y "
      "chillan a los clientes para que se acerquen a comprar. ",
 "Estas en el mercado de Brethem, aqui es donde tiene lugar gran parte del comercio de la ciudad, comerciantes, "
       "tenderos y clientes se reunen en la zona para vender y comprar casi de todo. "});
 string descripcion1;

 string *descripciones2 = ({"Con la multitud que pasa por aqui es facil cruzarse con algun ladron o delincuente "
        "que te internte robar, debes tener ciudado. ",
 "Hay clientes intentando rebajar precios a los mercaderes, ladrones intentando sacar tajada del bullicio y "
        "algun que otro guardia vigilando la zona. ",
 "Si te acercas a alguno de los puestos es facil que encuentras algo de tu agrado. otra cosa es lo que tengas que "
        "pagar por ello. "});
 string descripcion2;

 string *descripciones3 = ({"La mayoria de los mercaderes exponen sus mercancias en el suelo sobre grandes telas "
         "y alfombras para que los clientes puedan verlos bien",
 "Algunos mercaderes exponen sus mercancias en el mismo suelo del mercado, otros tienen su propio tenderete con sus "
         "mercancias colgadas de el para que las puedan ver los clientes",
 "Debes tener cuidado con los mercaderes mas espabilados que intentaran timarte si no sabes bien cuanto puede "
         "costar algo de lo que llevan"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}


/* DESCRIPCIONES CEMENTERIO */

void long_desc_cementerio()
{

string *descripciones1 = ({"Estas en el cementerio de la ciudad, es un lugar oscuro, humedo y rodeado por " 
      "una espesa bruma que lo cubre todo. ",
 "Tumbas, criptas y panteones te rodean por todos lados, estas en el cementerio de la ciudad, es un lugar "
      "frio y oscuro, apenas puedes ver mas alla de unos metros dado que una bruma flota sobre el lugar. ",
 "A pesar de la bruma que lo cubre todo puedes ver como cientos de tumbas y criptas se reparten por toda la "
       "zona. "});
 string descripcion1;

 string *descripciones2 = ({"Grandes arboles de cientos de anyos con las ramas peladas crecen entre las "
        "tumbas absorviendo el agua de una rica tierra gracias restos de cuerpos y huesos enterrados. ",
 "Entre las tumbas crecen algunos arboles enormes y deshojados, que dan un aspecto mas lugubre aun "
        "al cementerio. ",
 "Algunos arboles gigantescos con cientos de anyos crecen entre las numerosas tumbas cargadas de musgos y "
        "setas, parecen muy antiguas e inalteradas por el paso del tiempo. "});
 string descripcion2;

 string *descripciones3 = ({"Solo unos cuantos ciudadanos y algun que otro enterrador te acompanyan, la "
         "gente de la ciudad es muy temerosa y no suele venir por aqui",
 "La gente no suele venir por el cementerio debido al temor y la orcuridad que cubren este lugar lleno "
         "de almas en pena y espiritus intranquilos",
 "Este lugar no es muy frecuentado por la gente, que temerosa acerca de las historias y oscuras leyendas sobre "
         "el cementerio no se atreven a pisar la zona"});
 string descripcion3;

 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion1=descripciones1[random(sizeof(descripciones1))];

set_long(short_d+"\n\n"+descripcion1+descripcion2+descripcion3+".\n\n");

}

/* NPCS CALLE DEL MAR */

void crea_npcs_callemar()
{
   int cual, j;

   n=random(5);
   for (j=0; j<n; j++)
   {
      cual=random(21);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/comerciante", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/gaviota", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 8: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 9: add_clone(BRETHEM+"npcs/nomada", 1);
                 break;
         case 10: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
         case 11: add_clone(BRETHEM+"npcs/gaviota", 1);
                 break;
         case 12: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 13: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
         case 14: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 15: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
         case 16: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 17: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 18: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 19: add_clone(BRETHEM+"npcs/nomada", 1);
                 break;
         case 20: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
      }
   }
}


/* CREA NPCS PARA EL PARQUE */

void crea_npcs_parque()
{
   int cual, j;

   n=random(4);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/pajaro", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/ninyo", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/ninya", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
      }
   }
}

/* CREA NPCS PARA EL PUERTO */

void crea_npcs_puerto()
{
   int cual, j;

   n=random(4);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/marinero", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/gaviota", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/pescador", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/gaviota", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/marinero", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
      }
   }
}

/* CREA NPCS PARA LOS CALLEJONES Y CALLES PEQUENYAS */

void crea_npcs_callejon()
{
   int cual, j;

   n=random(3);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/ladron", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/delincuente", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/borracho", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
      }
   }
}


/* CREA NPCS PARA EL LOS BARRIOS BAJOS (BARRIOS CHUNGOS xD) */

void crea_npcs_barrios_bajos()
{
   int cual, j;

   n=random(4);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/ladron", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/bandido", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/borracho", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/delincuente", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
      }
   }
}


/* CREA NPCS PARA EL MERCADO DE LA CIUDAD */

void crea_npcs_mercado()
{
   int cual, j;

   n=random(6);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/guardia", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/ladron", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/mercader", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/mercader", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
      }
   }
}

/* CREA NPCS PARA EL CEMENTERIO */

void crea_npcs_cementerio()
{
   int cual, j;

   n=random(4);
   for (j=0; j<n; j++)
   {
      cual=random(8);
      switch (cual)
      {
         case 0: add_clone(BRETHEM+"npcs/enterrador", 1);
                 break;
         case 1: add_clone(BRETHEM+"npcs/perro", 1);
                 break;
         case 2: add_clone(BRETHEM+"npcs/espiritu", 1);
                 break;
         case 3: add_clone(BRETHEM+"npcs/gato", 1);
                 break;
         case 4: add_clone(BRETHEM+"npcs/pajaro", 1);
                 break;
         case 5: add_clone(BRETHEM+"npcs/espiritu", 1);
                 break;
         case 6: add_clone(BRETHEM+"npcs/ciudadana", 1);
                 break;
         case 7: add_clone(BRETHEM+"npcs/ciudadano", 1);
                 break;
      }
   }
}

void destruye_npcs()
{
}

