//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Meditaci�n");
set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Meditaci�n\n\n"
          "La funci�n de esta sala es la de proporcionar a los miembros del gremio un "
          "lugar de meditaci�n y concentraci�n. Un amplio sal�n con escritorios, sillones "
          "y c�modos divanes.\n\n");
	
        set_exit_color("red");
	add_exit ("norte", "/d/asgard/room/hechiceros/esc1-0.c", "door");
	
}
