//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("noroeste",ROOMBQDB"BQDB_92.c","standard");
add_exit("norte",ROOMBQDB"BQDB_93.c","standard");
add_exit("este",ROOMBQDB"BQDB_103.c","standard");
}
