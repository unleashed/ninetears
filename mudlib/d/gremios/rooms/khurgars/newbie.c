//Gareth 8.12.02

#include "/d/gremios/path.h"
inherit "/std/vaults/vault_room";

void setup () {
	::setup();
  	set_saqueable(0);
    	set_short("%^RED%^%^BOLD%^Gremio de los Khurgars: %^WHITE%^%^BOLD%^Baul Newbie%^RESET%^");
  	set_long(query_short()+"\n\n    Te encuentras en una pequenya sala sin muebles ni"
  					" ningun tipo de decoracion, excepto un gran baul"
  					" al final. Este baul esta destinado a los Khurgars"
  					" mas novatos.\n\n");
  	
  	add_item("baul","Un gran baul de madera muy lisa y sin imperfecciones, con una gran cerradura de acero.\n");
  	add_item("puerta","Una gruesa puerta de acero que protege la entrada a la sala.\n");
  	
  	add_exit("sudeste",GUILD_KHURGARS+"tablon","door");
}