//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Biblioteca de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Ala Sur");
set_long ("Biblioteca de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Ala Sur\n\n"
          "Una de las alas de la biblioteca, llena de estanter�as repletas de libros. "
          "Observas peque�os montoncitos de libros al lado de algunas estanter�as esperando "
          "ser colocados. La iluminaci�n de la biblioteca es especialmente intensa en "
          "comparaci�n con lo habitual en la ciudad.\n\n");
          
        set_light (60);
        set_exit_color("blue");
	add_exit("norte","/d/asgard/room/hall/biblio1.c","corridor");
		
	add_item(({"estanter�a","estanter�as"}),"Miles de libros ocupan los estantes.\n"); 
}
