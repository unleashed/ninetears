//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("oeste",ROOMBQDB"BQDB_56.c","standard");
add_exit("norte",ROOMBQDB"BQDB_52.c","standard");
add_exit("este",ROOMBQDB"BQDB_58.c","standard");
add_exit("sudeste",ROOMBQDB"CBQDB_18.c","standard");
}
