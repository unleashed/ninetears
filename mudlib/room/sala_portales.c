//Kryger 2003//
inherit "/std/outside";
object tablon;

void setup()
{
	set_short("%^BOLD%^GREEN%^Sala de los %^BLUE%^Portales%^RESET%^");
	set_long(query_short()+"\n\n"+"Estamos en una sala donde vemos muchos portales "
	"conducen a distintos puntos de Driade. La sala se ha formado por una transformaci�n "
	"de la fuerza, es un agujero espacio-tiempo abierto por error, y que no se sabe como, "
	"cuanto durara, de todas formas yo no me quedaria m�s del tiempo necesario aqui.\n");
	set_exit_color("red");
    add_exit("sur","/room/plaza/campo_discordia_22.c","path");
	add_exit("ormerod","/d/faeleen/rooms/ormerod/caminos/camino_ormerod_1.c","door");
	add_exit("rongrond","/d/faeleen/rooms/rongrond/caminos/camino_rongrond_6.c","door");
        add_exit("reino_keroon","/d/keroon/portal.c","door");
	add_exit("noella","/w/barthleby/entrada_provisional_a_noella.c","corridor");

}//cerrar setup

void reset()
{
	if(!tablon)
	{
		tablon=clone_object("/obj/misc/board");
		tablon->set_datafile("visitas");
		tablon->move(TO);
	}
	::reset();
    }
	void dest_me() 
	{
		if(tablon) tablon->dest_me();
		::dest_me();
	}
