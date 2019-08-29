inherit "/std/room";
object g1;

void setup()
{
   set_short("%^BOLD%^ %^RED%^Puesto de control.\n");

   set_long("%^BOLD%^ %^RED%^Puesto de control%^RESET%^.\n\n"
	    "Estas en uno de esos puestos de control que hay por algunos caminos."
	    " Ya sabes que si quieres pasar tendras que matar al guardian .\n\n");
  
  
   add_exit("norte","/w/monhal/camino/camino6.c","road");
   add_exit("sur","/w/monhal/camino/camino8.c","road");
   set_light(45);

  
  g1 = new("/w/monhal/npc/guardian.c",1);
  g1 -> move(this_object());
  
  
  modify_exit( "sur",( { "function","pasar" } ), );
}

int pasar()
{
if ( !g1)
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
