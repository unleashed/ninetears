//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Sala de Juntas");
set_long ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Sala de Juntas\n\n"
          "En esta sala se celebran los plenos de la junta de ciudadan�a. Aqu� "
          "se discuten los pormenores referentes a los temas civiles de Asgard. "
          "Tambi�n es aqu� donde se redactan las normas, leyes y estamentos. Otra "
          "de sus funciones es la de velar por el cumplimiento de dichas normas "
          "mediante la asignaci�n de instituciones que guarden la ciudad.\n\n");
	set_light (60);
        set_exit_color("blue");
	add_exit("norte","/d/asgard/room/hall/pasillo.c","corridor");
	add_exit("abajo","/d/asgard/room/hall/cala.c","corridor");
	
	
}
