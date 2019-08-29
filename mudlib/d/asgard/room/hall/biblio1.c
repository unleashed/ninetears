//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Biblioteca de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada");
set_long ("Biblioteca de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada\n\n"
          "Una gran sala dividida en dos alas, en el centro, donde te encuentras ahora, "
          "ves una gran mesa rectangular con muchas sillas. Alrededor de la mesa multitud "
          "de estanterías repletas de libros. También observas pequeños montoncitos de libros "
          "al lado de algunas estanterías esperando ser colocados. La iluminación de la "
          "biblioteca es especialmente intensa en comparación con lo habitual en la ciudad.\n\n");
	
        set_exit_color("blue");
	add_exit("norte","/d/asgard/room/hall/biblio2.c","corridor");
	add_exit("sur","/d/asgard/room/hall/biblio3.c","corridor");
	add_exit("abajo","/d/asgard/room/hall/pasillo.c","corridor");
	
	add_item("mesa","Bastante grande, rectangular y de madera maziza.\n");
	add_item(({"estantería","estanterías"}),"Miles de libros ocupan los estantes.\n"); 
}
