inherit "/std/room";
#include "path.h"

object guardia;

object board;

void setup ()
{
set_short ("%^BOLD%^WHITE%^Hall del Guild de Paladines%^RESET%^\n\n");
set_long ("%^BOLD%^WHITE%^Hall del Guild de Paladines%^RESET%^\n\n"+
"This is the Guildhall of Fighters.  This is where they wrack their "+
"brains thinking of new and improved ways of wracking brains.  Upstairs "+
   "is the fabled Round Table, where fighters gather from across the "+
   "realms to discuss deeds both great and mighty, and to talk of "+
   "matters pertaining to the Guild.\n\n");

	set_light (60);

	add_exit ("noroeste", "/room/paladines/barracks", "door"); 
        add_exit ("sudeste", "/room/entryroom", "door");
   //     modify_exit("noroeste", ({"function", "comprueba_paso"}));
    
}


void reset()
{
   if (!guardia) 
   {
   guardia = clone_object("/room/paladines/guardia.c");
   guardia->move(this_object());
   }
}



int comprueba_paso()
{
    if (!guardia) 
    {
    	notify_fail("Te aprovechas de que no estan los guardias para colarte en el gremio de Paladines.\n");
	return 1;
    }
    else
    {
        if((string)this_player()->query_guild_ob() != "/d/gremios/guerreros/paladin")
        {
	        if((string)this_player()->query_guild_ob() != "0")
		{
	        	notify_fail("La guardia te impide la entrada al gremio.\n");
	        	return 0;
		}
	 }
	 else
	 {
	         return 1;
	 }
     }
}

