//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("noroeste",ROOMBQDB"BQDB_60.c","standard");
add_exit("este",ROOMBQDB"BQDB_70.c","standard");
add_exit("sudoeste",ROOMBQDB"BQDB_81.c","standard");
}
