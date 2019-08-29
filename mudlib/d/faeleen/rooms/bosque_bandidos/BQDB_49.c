//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("norte",ROOMBQDB"BQDB_36.c","standard");
add_exit("este",ROOMBQDB"BQDB_50.c","standard");
add_exit("sudeste",ROOMBQDB"CBQDB_6.c","standard");
}
