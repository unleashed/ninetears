//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Sala de Reflexi�n");
set_long ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Sala de Reflexi�n\n\n"
          "La funci�n de esta sala es la de proporcionar a los miembros del gremio un "
          "lugar de descanso y meditaci�n. Colocados por toda la sala, unos bancos de "
          "madera cubiertos por ricas telas y c�modos cojines finamente bordados. "
          "Lo que mas llama tu atenci�n, una luz cenital que desciende iluminando toda "
          "la sala. Te preguntas acerca de la procedencia de esa luz, pues a Asgard "
          "nunca llega la luz del sol. Sin duda debe tratarse de algun tipo de luz "
          "creada m�gicamente.\n\n");
	
        set_exit_color("magenta");
	add_exit ("este", "/d/asgard/room/caballeros/entrada.c", "door");

}
