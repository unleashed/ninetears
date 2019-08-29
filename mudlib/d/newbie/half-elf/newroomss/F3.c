#define CREATOR "Llyr"

inherit "/std/room.c";

void setup()
 {
    set_short("Stockroom");

    set_long("\nVillage stockroom.\n\n"
        "     This is the second floor of the stockroom. "
	"Here have the arms and armours of the village been "
	"placed as the guardpost lies to the east. "
	"	There seems to be plenty enough with equipment "	
	"for everybody. Maybe you should ask for a 'weapon' "
	"or an 'armour' from the keeper downstairs? "
	"\n\n");
 
    set_light(80);
   
	// should add an NPC later
    add_item("window","Looking through the window to the north you "
	"get a center view of the village. The work down at the "
	"ground seems to pass by with impressive ease. Here you also "
	"see the small river pass through the elven village streaming "
	"east and bit later turning southeast."  \n");   
   
    add_smell(({"room","air"}),"A fresh smell streams from the open "
	"windows adding some of the nature's aroma. \n");
               
        
    add_exit("east","/d/newbie/half-elf/F5.c","door");	
    add_exit("down","/d/newbie/half-elf/v5.c","door");
    
  
   }