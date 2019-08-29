//.oO JaDe Oo. Noviembre'02
inherit "/std/room";
object board;

void setup ()
{
set_short ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Discusi�n\n");
set_long ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Discusi�n\n\n"
           "En este sal�n se discuten los asuntos internos del gremio. Aqu� los Sacerdotes "
           "del Caos pueden dejar sus opiniones sobre los diferentes temas que se expongan. "
           "Es una habitaci�n peque�a, con un gran tabl�n de notas y una mesa con un libro "
           "de anotaciones.\n\n");
        
	set_exit_color("cyan");
	add_exit ("este", "/d/asgard/room/sacerdotes/baul.c", "door"); 
        add_exit ("norte", "/d/asgard/room/sacerdotes/sala.c", "door");
        
}
void reset ()
{
	if (!board)
	{
		board = clone_object ("/obj/misc/board");
		board-> move (this_object ());
		board-> set_datafile ("sacerdotecaosguild");
	}
}

void dest_me ()
{
	if (board)
		board-> dest_me ();
	::dest_me ();
}