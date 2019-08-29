//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(1);
add_exit("oeste",ROOMBQDB"CBQDB_5.c","standard");
add_exit("este",ROOMBQDB"CBQDB_7.c","standard");
add_exit("noroeste",ROOMBQDB"BQDB_49.c","standard");
}
