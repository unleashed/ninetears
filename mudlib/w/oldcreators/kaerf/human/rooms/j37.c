#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Te encuentras al borde de un gran foso, hay una hendidura humeda en "
    "la roca por la que puedes retroceder. El aire esta lleno de insectos "
    "volando y oyes el sonido de agua. Una pequenya cascada parece correr "
    "abajo en el foso, en alguna parte a tu derecha. El agua del mar surge "
    "a intervalos inundando el fondo del foso, parece que un tunel conecta "
    "con el mar ahi abajo en alguna parte. Alrededor del borde del foso, algo "
    "mas abajo a la izquierda, parece haber una repisa. Un arbol de poca altura "
    "crece, sobresaliendo del borde ,justo sobre tu cabeza. "
    "\n\n");
   set_night_long("\nIsla de Havmand: Jungla\n\n"
      "   En la oscuridad te llega el sonido de una cascada, aunque no sabes "
      "donde puede estar. Justo sobre ti puedes ver la silueta de lo que parece "
      "un arbol no muy grande, y algo mas abajo a la izquierda una sombra mas "
      "oscura apunta a posibilidad de una repisa. Llegar hasta ella es un desafio "
      "cuando menos. "
      "\n\n");
    add_sound(({"cascada","agua"}),"El traqueteo constante de la cascada se mezcla "
    "con el sonido del agua que entra y sale por el tunel de abajo."
    "\n");
   add_item("foso","Un gran agujero en el suelo a tus pies, tiene el fondo "
      "lleno de agua arremolinandose, y no ves forma de llegar tan abajo.\n\n");
    add_item("insectos","Cientos de mosquitos, y algun bicho mas grande, que parecen "
    "sedientos de tu sangre. \n");
    add_smell("agua","Puedes sentir fuertemente el olor a agua marina.\n");
    add_item("cascada","Desde aqui no puedes verla, pero la oyes con la suficiente "
    "claridad.\n");
    add_item("tunel","Solo puedes ver la parte mas alta de la boca del tunel mientras "
    "el agua rompe en espuma al entrar y salir con fuerza. \n");
    add_item("repisa","Te agarras al arbol y te asomas un poco al borde.\n"
    "Parece haber algo tirado en la repisa de abajo, pero necesitarias algo con lo "
    "que volver a subir, no parece haber mas salidas ahi abajo, y eso en caso que no te "
    "rompieras la crisma al \"saltar\"."
    "\n");
    add_item("arbol","Es un arbol de ramas bajas, no ha crecido mucho pero sin embargo "
    "su tronco es ancho, y parece tener sus raices bien asentadas entre las grietas de la roca.\n");
//add_item("cleft","This is a section of cliff which has been washed away, allowing "
//"access to the sea.  Unfortunately, it is several hundred feet straight DOWN.  \n");
}
void init()
{
    add_exit("este",HAVMAND+"j36.c","path");
    add_action("do_rope","saltar");
    ::init();
}

int do_rope(string str)
{
    object *olist;
    olist = find_match("liana",this_player());
    if(!sizeof(olist))
    {
        write("No puedes hacerlo, sin una cuerda te quedarias atrapado para siempre "
        "en el foso.\n");
       say((string)this_player()->query_cap_name()+" mira "
       "la repisa de abajo calculando por unos segundos, se tensa, "
       "y entonces salta con fuerza.\n",this_player());
       return 1;
   }
   write("Atas firmemente un extremo de la liana al arbol, respiras con fuerza, "
   "calculas la distancia con cuidado... y con un grito salvaje, producto de la "
   "sensacion de peligro, saltas con decision hacia la repisa!\n");
   say("YEEEEEEEEEEE HAAAAAAAAAAaaaaa...!\n");
   this_player()->move(HAVMAND+"pit.c");
   this_player()->look_me();
   return 1;
}




