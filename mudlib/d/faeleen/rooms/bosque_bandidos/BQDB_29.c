//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("noroeste",ROOMBQDB"BQDB_19.c","standard");
add_exit("noreste",ROOMBQDB"BQDB_20.c","standard");
add_exit("sur",ROOMBQDB"BQDB_36.c","standard");
}
