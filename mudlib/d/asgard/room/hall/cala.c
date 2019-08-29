//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Calabozo de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada");
set_long ("Calabozo de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada\n\n"
          "Esta es la entrada al calabozo de la ciudad. Aqu� cumplen condena los pocos "
          "con el valor (o tal vez inconsciencia) suficiente para infringir alguna de las "
          "leyes de Asgard. Puedes ver cuatro celdas, una a cada lado de esta escalera de "
          "caracol. Un incesante goteo resuena contra el suelo de piedra de la prisi�n. "
          "Este hediondo agujero apenas est� iluminado por un par de l�mparas de aceite.\n\n");
	set_light (60);
        set_exit_color("blue");
	add_exit("arriba","/d/asgard/room/hall/sala.c","corridor");
	add_exit("norte","/d/asgard/room/hall/calan.c","corridor");
	add_exit("sur","/d/asgard/room/hall/calas.c","corridor");
	add_exit("este","/d/asgard/room/hall/calae.c","corridor");
	add_exit("oeste","/d/asgard/room/hall/calao.c","corridor");
		
}
