//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Ascenso al Quinto Nivel");
set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Ascenso al Quinto Nivel\n\n"
          "Una oscura y l�gubre escalinata que asciende hasta el piso superior. Tanto la "
          "escalera como la pared son de piedra negra, como la mayor�a de construcciones de "
          "Asgard. Unas antorchas descansan sobre unos agarraderos de metal que sobresalen de "
          "la pared, iluminando el camino.\n\n");
	
        set_exit_color("red");
        add_exit ("arriba", "/d/asgard/room/hechiceros/esc5-4.c", "stairs");
	add_exit ("este", "/d/asgard/room/hechiceros/baul.c", "door");
	add_exit ("sur", "/d/asgard/room/hechiceros/tablon.c", "door");
	
	
}
