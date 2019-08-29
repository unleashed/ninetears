#define CREATOR "Llyr"

inherit "/std/room.c";

void setup()
 {
    set_short("Stockroom");

    set_long("\nVillage stockroom.\n\n"
        "     Before you stands the food and materials commonly "
	"stocked by the villagers. Here lies all that is needed "
	"for the everyday life of the elves, including arms and 
	"armours for hunt and defense of life and home. "
	"There is an elven male guarding and assorting the "
	"goods."
	"The stockroom continues up by the stairs."
	"\n\n");
 
    set_light(80);
   
	// should add an NPC later
    add_item("window","   \n");   
   
    add_smell(({"room","air"}),"A fresh smell streams from the open "
	"windows adding some of the natures aroma. \n");
               
        
    add_exit("east","/d/newbie/half-elf/v5.c","door");	
    add_exit("west","/d/newbie/half-elf/t5.c","door");
    add_exit("up","/d/newbie/half-elf/F5.c","door");
  
   }