inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);

// mirar para que sirve el do_desc(1) este...  //

add_exit("norte","w/jerkat/valle_dragon/room/valle_09","road");
add_exit("sudoeste","w/jerkat/valle_dragon/room/valle_07","road");
add_clone("w/jerkat/valle_dragon/nopc/guardia_poblado",2);
}
void init() 
{
	::init();
	add_action("do_senyal","senyal");
}

/* Atencion.. el say  el say lo leera todo el que este en la room y el write solo el player*/
int do_senyal()
	{
	write("Haces unos gestos raros sin que tengan sentido.\n");
  	write("Uno de los guardias de mira de manera extranya.\n\n");
	write("Los guardianes te abren paso al poblado mostrandote\n");
	write("una entrada escondida entro los arbustos.\n\n");
  	add_exit("dentro","w/jerkat/valle_dragon/room/poblado_valle_09_entrada","door");
  	// do_command("glance");
  	modify_exit("dentro",({"function","do_entrar"}));
  	renew_exits();
  	return 1;
	}
int do_entrar() {
	remove_exit("dentro");
	renew_exits();
	return 1;
}


//poner que si alguien mata a los guardianes...... y pone buscar entrada. Se le abra la entrada //
