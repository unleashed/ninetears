// Minimap 2.3b.   (c) 1998 Spp .
// By MatatunoS '02
#include "../path.h"
inherit "/std/underground.c";

void setup()
{
   set_short("%^BOLD%^YELLOW%^Caverna%^BLACK%^ Sombria%^RESET%^: Entrada.\n");
   set_long("%^BOLD%^%^YELLOW%^Caverna%^BOLD%^BLACK%^ Sombria%^RESET%^: "
        "Entrada. \n\n Te encuentras en una lugubre caverna, horadada "
        "por el agua filtraza de la zona superior con el paso de los "
        "milenios, las paredes estan llenas de musgo, y algunas "
        "plantas crecen aqui, donde aun llega la luz, el suelo se "
        "inclina ligeramente hacia abajo segun desciendes por la "
        "cueva, un pequenyo reguero corretea de lado a lado, "
        "salpicandote de agua embarrada, segun desciendes el sonido "
        "del agua se va haciendo mas y mas fuerte.\n.\n");
   set_light(40);
   add_exit("norte"     ,"/w/leviathan/workroom.c","road");
   add_exit("sur"     ,"/w/leviathan/workroom.c","road");
   add_exit("este"     ,"/w/leviathan/workroom.c","road");
   add_exit("oeste"     ,"/w/leviathan/workroom.c","road");
   add_exit("noreste"     ,"/w/leviathan/workroom.c","road");
   add_exit("noroeste"     ,"/w/leviathan/workroom.c","road");
   add_exit("sudeste"     ,"/w/leviathan/workroom.c","road");
   add_exit("sudoeste"     ,"/w/leviathan/workroom.c","road");
   modify_exit("norte",({"function","do_desvio"}));
   modify_exit("sur",({"function","do_desvio"}));
   modify_exit("este",({"function","do_desvio"}));
   modify_exit("oeste",({"function","do_desvio"}));
   modify_exit("noreste",({"function","do_desvio"}));
   modify_exit("sudeste",({"function","do_desvio"}));
   modify_exit("sudoeste",({"function","do_desvio"}));
   modify_exit("noroeste",({"function","do_desvio"}));

}


int do_desvio()
{


if (random((this_player()->query_int())*10)<20)
{
	tell_object(TP, "%^BOLD%^WHITE%^OUCHH!!%^RESET%^\nTropiezas en una roca al salir de la cueva pegandote una buena costalada contra una estalagtita cercana. \n");
	tell_room(ENV(TP), TP->QCN+" patina y se machaca una costilla contra una estalagtita.\n", TP);
	this_player()->adjust_hp(-random(20));
}

write("..............................");

return 0;
}

