//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Descenso al Segundo Nivel");
set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Descenso al Segundo Nivel\n\n"
          "Una oscura y l�gubre escalinata que desciende hasta el piso inferior. Tanto la "
          "escalera como la pared son de piedra negra, como la mayor�a de construcciones de "
          "Asgard. Unas antorchas descansan sobre unos agarraderos de metal que sobresalen de "
          "la pared, iluminando el camino.\n\n");
	
        set_exit_color("red");
        add_exit ("abajo", "/d/asgard/room/hechiceros/esc2-3.c", "corridor");
	add_exit ("norte", "/d/asgard/room/hechiceros/laboratorio.c", "corridor");
		
	
}
