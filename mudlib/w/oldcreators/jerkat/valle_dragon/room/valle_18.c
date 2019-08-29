inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("norte","w/jerkat/valle_dragon/room/valle_17","road");
add_exit("este","w/jerkat/valle_dragon/room/valle_19","road");
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
  	add_exit("dentro","w/jerkat/valle_dragon/room/poblado_valle_02_entrada","door");
  	renew_exits();
  	return 1;
  }
 else
 	{
 		write("�Hacer que ? Una pirueta ?");
	 }
}
/* Atencion.. el say  el say lo leera todo el que este en la room y el write solo el player*/
int do_senyal()
	{
	write("Haces unos gestos raros sin que tengan sentido.\n");
  	write("Uno de los guardias de mira de manera extranya.\n\n");
	write("Los guardianes te abren paso al poblado mostrandote\n");
	write("una entrada escondida entro los arbustos");
  	add_exit("dentro","w/jerkat/valle_dragon/room/poblado_valle_02_entrada","door");
  	modify_exit("dentro",({"function","do_entrar"}));
  	renew_exits();
  	return 1;
}
int do_entrar() {
	remove_exit("dentro");
	renew_exits();
 return 1;
}