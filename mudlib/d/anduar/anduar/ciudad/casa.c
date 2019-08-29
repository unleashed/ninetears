// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";
int n, init=0;

void setup()
{
   set_short("Casa en el arbol");
   set_long("Has subido a lo alto del gran arbol situado en el centro de "
   "Anduar, es enorme y sus ramaje es tan espeso que te llama la atencion. "
   "Parece que este arbol haya sido creado por algun Dios que pretendia dar "
   "una huida a los ataques de las razas malvadas que habitan este reino. "
   "Te deleitas mirando los vivos colores de sus hojas, algunas de las ramas "
   "son tan largas que no alcanzas a ver su final, la vista es realmente "
"espectacular desde aqui. ");
//   add_exit("arriba"   ,ANDUAR"casa2.c","road");
   add_exit("abajo"   ,ANDUAR"cruce1313.c","road");
   base_desc();
}

void init()
{
  ::init();
  add_action("subir","subir");
}

int subir(string str)
{
 if (str == "rama")
  {
  write("Te subes a una rama del ent y caminando por ella bajas en una de las "
  "multiples calles de Anduar.\n");
  tell_room(environment(TP),TP->query_cap_name()+" empieza a subir por "
   "algun lado.\n",TP);
{
   int tipo;
      tipo=random(7);
      switch (tipo)
      {
         case 0: TP->move(load_object(ANDUAR+"cruce0101.c"));
                 break;
         case 1:   TP->move(load_object(ANDUAR+"cruce0619.c"));
                 break;
         case 2:   TP->move(load_object(ANDUAR+"cruce0725.c"));
                 break;
         case 3:   TP->move(load_object(ANDUAR+"cruce1312.c"));
                 break;
         case 4:   TP->move(load_object(ANDUAR+"cruce1413.c"));
                 break;
         case 5:   TP->move(load_object(ANDUAR+"cruce1907.c"));
                 break;
         case 6:   TP->move(load_object(ANDUAR+"cruce1918.c"));
                 break;
         case 7:   TP->move(load_object(ANDUAR+"cruce2504.c"));
                 break;
   }
}
   this_player()->look_me();
  tell_room(environment(TP),TP->query_cap_name()+" baja de un arbol.\n",TP);
  return 1;
  }
 notify_fail("Que pretendes subir?.\n");
 return 0;
}
