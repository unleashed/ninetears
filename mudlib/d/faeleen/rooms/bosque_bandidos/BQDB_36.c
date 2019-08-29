//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("oeste",ROOMBQDB"BQDB_35.c","standard");
add_exit("norte",ROOMBQDB"BQDB_29.c","standard");
add_exit("sur",ROOMBQDB"BQDB_49.c","standard");
}
