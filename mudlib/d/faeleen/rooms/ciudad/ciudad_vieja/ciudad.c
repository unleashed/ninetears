
/*
Handler de la Ciudad de Faeleen, por Flangerant, 2002:

Control de las descripciones, las move_zones y los items de las distintas zonas de la ciudad
*/


inherit "/std/ciudad.c";
void moeste()
{
   set_zone("faeleen_muralla");
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla oeste");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla oeste \n\n"
            "	Esta �s la parte oeste de la muralla de la ciudad de Faeleen. Desde las almenas"
            " tienes una gran vista de buena parte de la ciudad, como de las tierras exteriores."
            " Al oeste puedes ver una basta extensi�n de playa y , al fondo, el "
            "mar. Un peque�o poblado pesquero se alza entre la ciudad y la costa. Mirando atras"
            " ves la majestuosa ciudad comercial, llena de colorido y diversidad.\n\n");
   add_item("ciudad","La ciudad de Faeleen te queda al este, la capital del comercio.\n");
   add_item("poblado","Entre ti y el mar se alza un peque�o pueblo costero.\n");
   add_item("mar","Basta extensi�n de agua que delimita las fronteras del Driade.\n");
   add_item("playa","Una inmensa playa de arena, con algunas zonas de arbustos.\n");
   add_item("almenas","Grandes almenas de resistente piedra coronan la muralla de la ciudad.\n");
   
} 

void meste()
{
   set_zone("faeleen_muralla");
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla este");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla este \n\n"
            "	Esta �s la parte este de la muralla de la ciudad de Faeleen. Desde las almenas"
            " tienes una gran vista de buena parte de la ciudad, como de las tierras exteriores."
            " Al lado oeste puedes observar la ciudad de Faeleen. En el lado opuesto llegas a "
            "ver el rio que separa las tierras de Faeleen de Taur-Ithilien, cruzado por un majestuoso"
            " puente de piedra. Tambi�n desde aqui se divisa el viejo molino, usando la fuerza"
            " del rio para mover la enorme rueda.\n\n");
   add_item("almenas","Grandes almenas de resistente piedra coronan la muralla de la ciudad.\n");
   add_item("ciudad","La ciudad de Faeleen te queda al oeste, la capital del comercio.\n");
   add_item("rio","El rio Nahur, que desciende hasta desembocar al sur del continente.\n");
   add_item("puente","Un s�lido puente de piedra que cruza el rio.\n");
   add_item("molino","El viejo molino, con la rueda trabajando incansable al ritmo del agua.\n");
   
} 

void mnorte()
{
   set_zone("faeleen_muralla");
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla norte");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla norte \n\n"
            "	Esta �s la parte norte de la muralla de la ciudad de Faeleen. Desde las almenas"
            " tienes una gran vista de buena parte de la ciudad, como de las tierras exteriores."
            " Desde aqui divisas las tierras del norte, con los poblados de "
            "Grandhum y Ormerod, y al oeste el inmenso oceano. Mirando atras"
            " ves la majestuosa ciudad comercial, llena de colorido y diversidad.\n\n");
   add_item("almenas","Grandes almenas de resistente piedra coronan la muralla de la ciudad.\n");
   add_item("ciudad","La ciudad de Faeleen te queda al sur, la capital del comercio.\n");
   add_item("poblados","Ves al noreste el poblado de Ormerod y al noroeste el de Grandhum.\n");
   add_item("grandhum","Un pequenyo poblado de agricultores donde se cultiva la preciosa Pretyus.\n");
   add_item("ormerod","Un poblado ganadero que subministra la carne a la capital.\n");
}

void msur()
{
   set_zone("faeleen_muralla");
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla sur");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Muralla sur \n\n"
            "	Esta �s la parte sur de la muralla de la ciudad de Faeleen. Desde las almenas"
            " tienes una gran vista de buena parte de la ciudad, como de las tierras exteriores."
            " Desde esta parte de la muralla puedes observar una arboleda al sur "
            "de la ciudad, y mas al sur, las peque�as colinas de la zona de Mebiriand,"
            " el hogar de los halflings. Tambien puedes ver la antigua puerta sur de"
            " la ciudad, clausurada desde hace mucho tiempo.\n\n");
   add_item("almenas","Grandes almenas de resistente piedra coronan la muralla de la ciudad.\n");
   add_item("ciudad","La ciudad de Faeleen te queda al norte, la capital del comercio.\n");
   add_item("puerta","La silueta de lo que anteriormente fu� la puerta de la ciudad, en la fr�a piedracg.\n");
   add_item("merbiriand","La verdre y alegre comarca halfling se extiende al sur de Faeleen.\n");
   add_item("arboleda","Una espesa arboleda al sur de la ciudad.\n");
}

void barrio_han()
{
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Hanuk");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Hanuk \n\n"
            "	Te encuentras en uno de los barrios pobres de la ciudad de Faeleen."
            " En esta parte las casas estan bastante desgastadas, y las calles no "
            "disponen de un sistema de limpieza y son bastante estrechas. Es una zona"
            " muy gris que contrasta con el colorido de la ciudad.\n\n");
   set_night_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Hanuk \n\n"
   	          "	Te encuentras en uno de los barrios pobres de la ciudad de Faeleen."
   	          " Incluso siendo de noche, te sorprende la cantidad de gente que puedes"
   	          " ver en las calles. Parece como si el descanso no llegara nunca a este lugar."
   	          " Las casas aqui estan bastante desgastadas, y en general contrasta en casi "
   	          "todos los aspectos con las zonas mas ricas de la ciudad.\n\n");
   set_zone("faeleen_pobre");
   add_item("calles","Las calles de esta parte estan bastanet sucias y descuidadas.\n");
   add_item("casas","Montones de casas peque�as, algunas en bastante mal estado.\n");
}

void barrio_alf()
{
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Alfanar");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Alfanar \n\n"
            "	Te encuentras en uno de los barrios pobres de la ciudad de Faeleen."
            " En esta parte las casas estan bastante desgastadas, y las calles no "
            "disponen de un sistema de limpieza y son bastante estrechas. Es una zona"
            " muy gris que contrasta con el colorido de la ciudad.\n\n");
   set_night_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Alfanar \n\n"
   	          "	Te encuentras en uno de los barrios pobres de la ciudad de Faeleen."
   	          " Incluso siendo de noche, te sorprende la cantidad de gente que puedes"
   	          " ver en las calles. Parece como si el descanso no llegara nunca a este lugar."
   	          " Las casas aqui estan bastante desgastadas, y en general contrasta en casi "
   	          "todos los aspectos con las zonas mas ricas de la ciudad.\n\n");
   set_zone("faeleen_pobre");
   add_item("calles","Las calles de esta parte estan bastanet sucias y descuidadas.\n");
   add_item("casas","Montones de casas peque�as, algunas en bastante mal estado.\n");
}

void pobre()
{
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Callejon");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Callejon \n\n"
            "	Te encuentras en uno de los barrios pobres de la ciudad de Faeleen."
            " En esta parte las casas estan bastante desgastadas, y las calles no "
            "disponen de un sistema de limpieza y son bastante estrechas. Es una zona"
            " muy gris que contrasta con el colorido de la ciudad.\n\n");
   set_night_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Barrio Alfanar. \n\n"
   	          "	Te encuentras en uno de los barrios pobres de la ciudad de Faeleen."
   	          " Incluso siendo de noche, te sorprende la cantidad de gente que puedes"
   	          " ver en las calles. Parece como si el descanso no llegara nunca a este lugar."
   	          " Las casas aqui estan bastante desgastadas, y en general contrasta en casi "
   	          "todos los aspectos con las zonas mas ricas de la ciudad.\n\n");            
   set_zone("faeleen_pobre");
   add_item("calles","Las calles de esta parte estan bastanet sucias y descuidadas.\n");
   add_item("casas","Montones de casas peque�as, algunas en bastante mal estado.\n");
}

void mercado()
{
   set_short("%^BOLD%^%^MAGENTA%^Mercado%^RESET%^ de la Ciudad de %^BOLD%^Faeleen%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Mercado%^RESET%^ de la Ciudad de %^BOLD%^Faeleen%^RESET%^ \n\n"
            "	Estas en el mercado situado en la parte norte de la ciudad de Faeleen."
            " Alrededor ves tiendas y paradas, de colores y formas muy variadas. Un viejo "
            "probervio del oeste dice que si algo no lo encuentras en estos mercados, o lo"
            " pueden conseguir o no existe.\n\n");
   set_zone("faeleen_mercado");
   add_item("tiendas","Multitud de establecimientos donde se venden las cosas mas insolitas.\n");
   add_item("paradas","Multitud de establecimientos donde se venden las cosas mas insolitas.\n");
}

void cnorte()
{
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Calle Norte");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Calle Norte \n\n"
            "	Esta es la calle que da la entrada a la majestuosa ciudad de Faeleen"
            " por el norte. Edificios de todas las formas y colores regodean tu vista, y "
            "la vision del mercado al sur es espectacular. El suelo, empedrado con adoquines"
            " muestra un aspecto estupendo.\n\n");
   set_zone("faeleen_ciudad");
   add_item("suelo","El suelo esta empedrado a base de adoquines.\n");
   add_item("adoquines","Miles y miles de piedras de forma rectangular situadas en linea.\n");
   add_item("edificios","Majestuosas casas.\n");
}

void csur()
{
   set_short("Ciudad de %^BOLD%^Faeleen%^RESET%^: Calle Sur");
   set_long("Ciudad de %^BOLD%^Faeleen%^RESET%^: Calle Sur \n\n"
            "	Esta es la calle que daba la entrada a la majestuosa ciudad de Faeleen"
            " por el sur, pero la entrada por el sur a la ciudad permanece cerrada desde"
            " hace muchisimos a�os. Edificios de todas las formas y colores regodean tu vista, y "
            "la vision del mercado al sur es espectacular. El suelo, empedrado con adoquines"
            " muestra un aspecto estupendo.\n\n");
   set_zone("faeleen_ciudad");
   add_item("suelo","El suelo esta empedrado a base de adoquines.\n");
   add_item("adoquines","Miles y miles de piedras de forma rectangular situadas en linea.\n");
   add_item("edificios","Majestuosas casas.\n");
}

void artes()
{
   set_zone("faeleen_ciudad");
   set_short("Ciudad de Faeleen: %^BOLD%^Avenida de las Artes%^RESET%^");
   set_long("Ciudad de Faeleen: %^BOLD%^Avenida de las Artes%^RESET%^\n\n"
            "	Te encuentras en una de las dos grandes avenidas que traspasan la ciudad "
            "de Faeleen de norte a sur. En esta zona las calles son anchas, las casas "
            "altas y blancas, bastante uniformes. Esta es famosa por la acumulaci�n de"
            " artistas que hay en ella y por albergar el templo de Thyriand. La avenida"
            " desborda de vitalidad y oyes alrededor gritos y canciones.\n\n");
   set_night_long("Ciudad de Faeleen: %^BOLD%^Avenida de las Artes%^RESET%^\n\n"
                  "	Te encuentras en una de las dos grandes avenidas que traspasan la ciudad "
                  "de Faeleen de norte a sur. En esta zona las calles son anchas, las casas "
                  "altas y blancas, bastante uniformes. Esta es famosa por la acumulaci�n "
                  "de artistas que hay en ella y por albergar el templo de Thyriand. Durante"
                  " la noche la avenida parece apagada.\n\n");
}

void plata()
{
   set_zone("faeleen_ciudad");
   set_short("Ciudad de Faeleen: %^BOLD%^Avenida de la Plata%^RESET%^");
   set_long("Ciudad de Faeleen: %^BOLD%^Avenida de la Plata%^RESET%^\n\n"
            "	Te encuentras en una de las dos grandes avenidas que traspasan la ciudad "
            "de Faeleen de norte a sur. En esta zona las calles son anchas, las casas "
            "altas y blancas, bastante uniformes. En otros tiempos los comercios de esta "
            "avenida habian competido con los del mercado, aunque su prosperidad ha decaido "
            "en los ultimos tiempos.La avenida desborda de vitalidad y oyes alrededor gritos "
            "y canciones.\n\n");
   set_night_long("Ciudad de Faeleen: %^BOLD%^Avenida de la Plata%^RESET%^\n\n"
                  "	Te encuentras en una de las dos grandes avenidas que traspasan la ciudad "
                  "de Faeleen de norte a sur. En esta zona las calles son anchas, las casas "
                  "altas y blancas, bastante uniformes. En otros tiempos los comercios de esta "
                  "avenida habian competido con los del mercado, aunque su prosperidad ha "
                  "decaido en los ultimos tiempos. Durante la noche la avenida parece "
                  "apagada.\n\n");
}

void jardin()
{
   set_zone("faeleen_ciudad");
   set_short("%^BOLD%^Paseo alrededor de los %^GREEN%^Jardines%^RESET%^%^GREEN%^ de%^BOLD%^ Faeleen%^RESET%^");
   set_long("%^BOLD%^Paseo alrededor de los %^GREEN%^Jardines%^RESET%^%^GREEN%^ de%^BOLD%^ Faeleen%^RESET%^\n\n"
            "	Estas en un hermosos paseo que rodea los antiguos jardines de Faeleen. Construidos"
            " en los primeros tiempos de la ciudad, han sido durante largos a�os simbolo de la "
            "fertilidad de las tierras que rodean la ciudad. Plantas y arboles de todos los "
            "tama�os y colores hacen de este un lugar extremadamente peculiar. Ex�ticos olores "
            "inundan el lugar y mil sensaciones llegan a tu mente al contemplar la enormidad de "
            "los jardines dentro de la ciudad. Sin duda son un s�mbolo realmente ostentoso."
            " Por razones desconocidas, la entrada a los jardines est� completamente prohibida, y"
            " una verja los rodea para impedir que la gente entre.\n"
            "	A pleno dia, el jardin muestra unos tonos claros y vivos, y se observa movimiento de"
            "peque�os roedores y aves dentro, las baldosas del suelo se ven de un color gris claro y "
            "las pocas partes de tierra que restan sin vegetaci�n son claramente visibles, contrastando"
            " con el resto del jard�n.\n\n");
   set_long("%^BOLD%^Paseo alrededor de los %^GREEN%^Jardines%^RESET%^%^GREEN%^ de%^BOLD%^ Faeleen%^RESET%^\n\n"
            "	Estas en un hermosos paseo que rodea los antiguos jardines de Faeleen. Construidos"
            " en los primeros tiempos de la ciudad, han sido durante largos a�os simbolo de la "
            "fertilidad de las tierras que rodean la ciudad. Plantas y arboles de todos los "
            "tama�os y colores hacen de este un lugar extremadamente peculiar. Ex�ticos olores "
            "inundan el lugar y mil sensaciones llegan a tu mente al contemplar la enormidad de "
            "los jardines dentro de la ciudad. Sin duda son un s�mbolo realmente ostentoso."
            " Por razones desconocidas, la entrada a los jardines est� completamente prohibida, y"
            " una verja los rodea para impedir que la gente entre.\n"
            "	Durante la noche, las plantas parecen tomar un tono mas oscuro y siniestro, y sus olores"
            " se ven un poco disipados, las baldosas del suelo toman un color oscuro y te �s bastante "
            "complicado llegar a ver que hay exactamente en el interior de los jardines.\n\n");
            
   add_item("verja","Una hermosa verja de metal que rodea los jardines, decorada con algunos motivos ex�ticos.\n");
   add_item("baldosas","El suelo aqui est� completamente cubierto de baldosas de un extra�o mineral, que"
             " parece cambiar el color segun la hora del dia en que se encuentre.\n");
   add_item("plantas","Ves infinidad de plantas de todas las formas, colores y tama�os, extra�amente concentradas"
            " todas en un espacio relativamente tan peque�o.\n");
   add_item("arboles","Arboles grandes y peque�os, destacando entre ellos una enorme secuoia en el centro mismo del jardin.\n");
   add_item("secuoia","Un arbol gigantesco, de una edad incalculable, se erige en el centro de los jardines.");
}

void exterior()
{
   set_zone("faeleen_ciudad");
   set_short("%^ORANGE%^Exteriores de Faeleen:%^RESET%^%^BOLD%^ Muralla%^RESET%^");
   set_long("%^ORANGE%^Exteriores de Faeleen:%^RESET%^%^BOLD%^ Muralla%^RESET%^\n\n"
            "	Exterior de Faeleen "
            " "
            " "
            " "
            " "
            ".\n\n");
   set_night_long("%^ORANGE%^Exteriores de Faeleen:%^RESET%^%^BOLD%^ Muralla%^RESET%^\n\n"
   		  "	Exterior de Faeleen by Night "
                  " "
                  " "
                  " "
                  " "
                  ".\n\n");
}