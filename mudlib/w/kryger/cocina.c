#define CREATOR "kryger"

inherit "/std/vaults/vault_room.c";
// inherit the file "/std/outside.c" if you want clouds and such.


void setup()
{
   set_short("Cocina de "+CREATOR+".");

   set_long("\nCocina de "+CREATOR+".\n\n"

   "    En esta habitacion podemos ver la tipica cocina,con horno,frigorifico,lavavajillas y fregador."
       	"\n\n");
       	// sets the level of light in the room.   "help light" for details
   set_light(80);
   
   add_item("frigorifico","Es un frigorifico como los de toda la vida. \n");
   
   add_exit("fuera","/w/kryger/workroom","door");
}
