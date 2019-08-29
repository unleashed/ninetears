//.oO JaDe Oo.  Junio'02
inherit "/std/room";
object board;

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Tabl�n\n");
set_long ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Tabl�n\n\n"
           "En esta parte el pasillo se ensancha ligeramente terminando en una "
           "impresionante arcada que da a la sala principal del gremio. A un "
           "lado del pasillo puedes ver un tabl�n de notas. Aqui se dejan los "
           "mensajes para que el resto de miembros del gremio los lean.\n\n");
        
	set_exit_color("magenta");
	add_exit ("sur", "/d/asgard/room/caballeros/trono.c", "corridor"); 
        add_exit ("norte", "/d/asgard/room/caballeros/pasillo.c", "corridor");
        
}
void reset ()
{
	if (!board)
	{
		board = clone_object ("/obj/misc/board");
		board-> move (this_object ());
		board-> set_datafile ("caballerojadeguild");
	}
}

void dest_me ()
{
	if (board)
		board-> dest_me ();
	::dest_me ();
}