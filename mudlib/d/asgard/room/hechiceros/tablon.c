//.oO JaDe Oo. Noviembre'02
inherit "/std/room";
object board;

void setup ()
{
set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Reuni�n\n");
set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Reuni�n\n\n"
           "En este sal�n se discuten los asuntos internos del gremio. Aqu� los Hechiceros "
           "del Caos pueden dejar sus opiniones sobre los diferentes temas que se expongan. "
           "Es una habitaci�n peque�a, con un gran tabl�n de notas y una mesa con un libro "
           "de anotaciones.\n\n");
        
	set_exit_color("red");
	add_exit ("este", "/d/asgard/room/hechiceros/esc4-3.c", "door"); 
        add_exit ("norte", "/d/asgard/room/hechiceros/esc4-5.c", "door");
        
}
void reset ()
{
	if (!board)
	{
		board = clone_object ("/obj/misc/board");
		board-> move (this_object ());
		board-> set_datafile ("hechicerocaosguild");
	}
}

void dest_me ()
{
	if (board)
		board-> dest_me ();
	::dest_me ();
}