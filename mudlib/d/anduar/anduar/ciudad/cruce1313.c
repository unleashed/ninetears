// Aokromes
#include "../path.h"
inherit ANDUAR"rica.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Entrada al monumento de Osucaru.%^RESET%^");
 set_long("Estas en el centro de Anduar, ante ti se alza el monumento en "
     "memoria de Osucaru, una gran persona, un gran amigo, un gran "
     "programador. Unas grandes columnas sostienen el techo del hermoso "
     "templo echo en las mas nobles piedras, talladas y ensambladas con la "
     "habitual habilidad de los mismos.\n"
     "Dandole sombra al templo un gigantesco arbol, que dicen las "
     "leyendas que fue plantado cuando la ciudad fue fundada, y que cuando "
     "el arbol muera, Anduar morira.\n");
   add_item("arbol","Es un colosal arbol, las leyendas dicen que es un ent "
   "dormido, y que en realidad nunca fue plantado si no que fue el, el que "
   "decidio quedarse");
   add_exit("norte"   ,ANDUAR"cruce1213.c","road");
   add_exit("oeste"   ,ANDUAR"cruce1312.c","road");
   add_exit("este"    ,ANDUAR"cruce1314.c","road");
   add_exit("sur"     ,ANDUAR"cruce1413.c","road");
   add_exit("dentro"  ,ANDUAR"templo/templo.c", "road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}

void init()
{
  ::init();
  add_action("subir","subir");
}

int subir(string str)
{
 if (str == "arbol")
  {
  write("Subes al ent y encuentras una casa escondida entre los arboles.\n");
  tell_room(environment(TP),TP->query_cap_name()+" empieza a subir por "
   "algun lado.\n",TP);
  TP->move(load_object(ANDUAR+"casa.c"));
   this_player()->look_me();
  tell_room(environment(TP),TP->query_cap_name()+" sube de la calle.\n",TP);
  return 1;
  }
 notify_fail("Que pretendes subir?.\n");
 return 0;
}
