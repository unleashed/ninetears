#include "puesto.h"
inherit "/std/room";
object g1;
object g2;

void setup()
{
   set_short("%^YELLOW%^%^BOLD%^P%^BLUE%^uertas %^YELLOW%^D%^BLUE%^oradas\n");

   set_long("%^YELLOW%^%^BOLD%^P%^BLUE%^uertas %^YELLOW%^D%^BLUE%^oradas\n\n"
	    "Unas puertas de acero frio y macizo, con dibujos y sombreados de"
	    " oro a su alrededor. No parecen estar abiertas a los invitados no"
	    " deseados.\n\n");
  
   
   add_exit("norte", ROOM+"camino6.c","road");
   add_exit("sur", ROOM+"camino8","path");
   set_light(45);

  
  
  g1->move(NPC+"guardia.c",1);//Pero por algo no lo hago =)
    g2->move(NPC+"guardia.c",1);
   
modify_exit( "sur",( { "function","pasar" } ), );
}

int pasar()
{
if ( !g1 && !g2)
     {
     tell_object(TP,"Pasas libremente al no haber ningun Guardia en el camino.\n",TP);
     return(1);
     }
   else
     {
   notify_fail("Guardia te dice: �Donde pretendes ir?\n");
   return(0);
     }
}
