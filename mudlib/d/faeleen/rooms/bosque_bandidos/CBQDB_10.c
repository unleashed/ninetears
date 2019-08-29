//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(1);
add_exit("oeste",ROOMBQDB"CBQDB_9.c","standard");
add_exit("este",ROOMBQDB"CBQDB_11.c","standard");
add_exit("sur",ROOMBQDB"BQDB_70.c","standard");
add_exit("noroeste",ROOMBQDB"BQDB_53.c","standard");
}
