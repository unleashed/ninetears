//Paris. Abr'98. Anyado la entrada secreta para los Garra Negra.

#include "../path.h"
inherit ANDUAR+"roadroom.c";

void init()
{
	::init();
	add_action("do_abajo","abajo");
	add_action("do_abajo","bajar");
	add_action("do_abajo","ab");
}
int do_abajo()
{
	  
	if(TP->query_group_name() == "La Garra Negra")
	{	  
	  tell_object(TP,"Abres una pequenya trampilla en el suelo que da acceso a un "
	        "tunel que te lleva a la Sala de reuniones del Clan Garra Negra.\n");
	  tell_room(environment(TP),TP->query_cap_name()+" abre una trampilla "
	            "secreta que deja entrever un pequenyo tunel, se mete por "
	            "el y desaparece.\n",({TP}));
           TP->move("/d/clanes/garra_negra/rooms/main.c");
	   TP->look_me();
	   return 1;
	 }
	 else
	  return 0;
} 
void setup()
{
   base_desc();
   add_exit("northeast",ANDUAR+"c3","road");
   add_exit("south",ANDUAR+"c1","road");
   crea_bichos();
}


void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
