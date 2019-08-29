//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Biblioteca de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Ala Sur");
set_long ("Biblioteca de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Ala Sur\n\n"
          "Una de las alas de la biblioteca, llena de estanterías repletas de libros. "
          "Observas pequeños montoncitos de libros al lado de algunas estanterías esperando "
          "ser colocados. La iluminación de la biblioteca es especialmente intensa en "
          "comparación con lo habitual en la ciudad.\n\n");
          
        set_light (60);
        set_exit_color("blue");
	add_exit("norte","/d/asgard/room/hall/biblio1.c","corridor");
		
	add_item(({"estantería","estanterías"}),"Miles de libros ocupan los estantes.\n"); 
}
