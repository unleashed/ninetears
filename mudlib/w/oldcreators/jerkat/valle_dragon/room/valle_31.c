inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("norte","w/jerkat/valle_dragon/room/valle_32","road");
add_exit("sudeste","w/jerkat/valle_dragon/room/valle_30","road"); 
add_exit("sur","w/jerkat/valle_dragon/room/valle_29","road");
modify_exit("sur",({"function","do_sur"}));
}
int do_sur()
{
	if (TP->query_str()>=18)
		{
			write ("Consigues atajar un poco el camino");
			return 1;
		}
	else
		{
			if (TP->query_str()>=17)
				{
					if (random(2) == 1)
						{
							write("Atajas con un poco de dificultat... \n");
							return 1;
						}
					else
						{
							write("Vuelvelo a intentar\n");
							return 0;
						}
				}
			else
				{
					write("No eres lo suficientemente fuerte para pasar \n");
				}
		}
}