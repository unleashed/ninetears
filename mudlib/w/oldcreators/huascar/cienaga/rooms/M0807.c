//Huascar

#include "../path.h"
inherit "/std/room.c";
void setup()
{
set_short("%^WHITE%^Panteon del Mausoleo%^RESET%^");
set_long("%^WHITE%^Panteon del Mausoleo%^RESET%^\n\n Ante ti se encuentra el mausoleo resultado de la "
	 "mitica batalla que tuvo lugar por estas tierras anyos atras. La debastacion de "
	 "aquella guerra fue tal que debido a las numerosas bajas, los dos bandos pactaron "
 	 "una tregua para la construccion de este mausoleo y la sepultura en el de todos "
	 "los caidos. No obstante fueron tantos que no pudieron meterlos a todos.\n\n");
		
set_light(70);
set_zone("cienaga");
add_clone(NPC"guarda.c",random(3)-1);
add_exit("oeste",MAR"M0806.c","road");
add_exit("norte",MAR"M0907.c","road");
}
