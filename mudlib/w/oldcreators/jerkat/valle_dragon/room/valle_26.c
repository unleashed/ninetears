inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("sudoeste","w/jerkat/valle_dragon/room/valle_27","road");
add_exit("norte","w/jerkat/valle_dragon/room/valle_25","road");
add_exit("desvio","w/jerkat/valle_dragon/room/valle_33","door");
modify_exit("desvio",({"function","do_desvio"}));
}
int do_desvio()
{
	if (TP->query_dex()>16)
		{
			write ("\n Oleee.... \n Consigues pasar sin ninguna dificultad\n\n");
			return 1;
		}
	else
		{
			if (TP->query_dex()==16)
				{
					write("Te enganchas con una zarza...\n");		
					write("Esto debe doler. Ouch!!! \n");
					TP->adjust_hp(-(5+random(10)));
					return 1;
				}
			else
				{
				write("No puedes pasar el arbol que te bloquea el camino\n");
				return 0;
				}
		}
}