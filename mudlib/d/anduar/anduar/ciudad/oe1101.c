// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom2.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: calle Oeste%^RESET%^");
   long_desc();
   add_exit("norte"   ,ANDUAR"cruce1001.c","road");
   add_exit("sur"     ,ANDUAR"oe1201.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
void init()
{
  ::init();
  add_action("atar","atar");
}

int atar(string str)
{
 object *olist;
 int i,OK=0;
 
 if ( (str!="cuerda") && (str!="cuerda a almena") ) return 0;
 
 olist=all_inventory(TP);
 for(i=0;i<sizeof(olist);i++)
  if((string)(olist[i]->query_short())=="Cuerda")
   OK=1; 
  
 if (OK) 
 {
 if (TP->query_guild_ob()=="/std/guilds/rogues/thief")
 {
   tell_object(TP,"  Atas la cuerda a la almena y comienzas a subir por la "
   "misma. Llegas a la parte superior y empiezas a bajar al interior.\n\n");
   tell_room(ENV(TP),TP->query_cap_name()+" ata una cuerda a una almena y "
   "sube por la muralla.\n",TP);
   TP->add_timed_property("guardias_anduar", 1, 1000);
   if(random( TP->query_level() + TP->query_dex()) > 30)
   {
// Cambiar la siguiente linea para la room de destino.
   TP->move(ANDUAR+"muralla0500");
// Cambiar la linea anterior para la room de destino.
   TP->look_me();
   return 1;
   }
else
   {
   tell_object(TP,"  Pero te pegas un batacazo.\n\n");
   TP->adjust_hp(-10);
// Cambiar la siguiente linea para la room de destino.
   TP->move(ANDUAR+"muralla0500");
// Cambiar la linea anterior para la room de destino.
   TP->look_me();
   return 1;
   }
   return 1;
 }
 tell_object(TP,"No eres un ladron, entra por la puerta como dios manda!!.\n");
 return 1;
 }
 else {
   tell_object(TP,"Tal vez necesites una cuerda para poder atarla.\n");
 return 1;
 }
}
