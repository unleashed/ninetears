#include "../path.h"

object *malos;

void create()
{
   seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
}

void anyadir_malo(object gilipollas)
{
   malos+=({ gilipollas });
}

void mover_guardianes()
{
   int i, n;
   
   object *guardias;
   
   guardias=children(NPC+"guardian.c");
   n=sizeof(guardias);
   for (i=0; i<n; i++)
   {
      if (environment(guardias[i]))
         if (malos != ({ }))
            guardias[i]->buscar(malos[0]);
       
   }
}

void borrar_malo(object puto)
{
   malos-=({ puto });
}
