//Kryger 2003//
inherit "/d/faeleen/handlers/base_handler_bb.c";
#include "../path.h"
void setup()
{

	habitacion(0);
add_exit("norte",ROOMBQDB"BQDB_104.c","standard");
add_exit("este",ROOMBQDB"BQDB_114.c","standard");
add_exit("sudoeste",ROOMBQDB"BQDB_118.c","standard");
}
