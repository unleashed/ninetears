//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Laboratorio");
set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Laboratorio\n\n"
          "Esta es la sala donde los miembros del gremio realizan sus pr�cticas m�gicas bajo "
          "la atenta mirada de sus tutores. Repartidas por la estancia observas varias mesas "
          "con todo tipo de utensilios e ingredientes para los conjuros.\n\n");
	
        set_exit_color("red");
	add_exit ("sur", "/d/asgard/room/hechiceros/esc3-2.c", "door");
	add_exit ("sudeste", "/d/asgard/room/hechiceros/esc3-4.c", "door");
	
}
