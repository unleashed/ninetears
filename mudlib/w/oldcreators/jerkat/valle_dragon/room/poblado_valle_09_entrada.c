inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("noreste","w/jerkat/valle_dragon/room/poblado_valle_03","road");
add_exit("sudoeste","w/jerkat/valle_dragon/room/poblado_valle_10_entrada","door");
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_08","road");
add_clone("w/jerkat/valle_dragon/nopc/guardia_poblado",2);
}
void init() 
{
  ::init();
  add_action("do_senyal","senyal");
}
int hacer(string str)
{
 if (str == "senyal")
 {
 	write("Haces unos gestos raros sin que tengan sentido.\n");
  	write("Uno de los guardias de mira de manera extranya.\n\n");
	write("Los guardianes te abren paso al poblado mostrandote\n");
	write("una entrada escondida entro los arbustos.\n\n");
  add_exit("fuera","w/jerkat/valle_dragon/room/valle_08","door");
  renew_exits();
  return 1;
  }
 else
  {
    write("�Hacer que ? Una pirueta ?");
    return 1;
  }
}
int do_senyal()
	{
	write("Haces unos gestos raros sin que tengan sentido.\n");
  	write("Uno de los guardias de mira de manera extranya.\n\n");
	write("Los guardianes te abren paso al poblado mostrandote\n");
	write("una entrada escondida entro los arbustos");
  	add_exit("fuera","w/jerkat/valle_dragon/room/valle_08","door");
  	modify_exit("fuera",({"function","do_fuera"}));
  	renew_exits();
  	return 1;
  	}
int do_fuera()
 {
 remove_exit("fuera");
 renew_exits();
 return 1;
 }