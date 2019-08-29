//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada");
set_long ("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada\n\n"
	  "Te encuentras en la zona comercial de Asgard. Aqu� venden sus productos los artesanos "
	  "y orfebres de la ciudad. Algunas caravanas de mercaderes se aventuran a venir hasta este "
	  "mercado, pues a pesar de que el trayecto es peligroso, las mercancias que aqu� se comercian son "
	  "muy preciadas en el resto de driade. Puedes ver multitud de tenderetes, toldos y tiendas.\n\n");
	set_light (60);
        set_exit_color("yellow");
        
	add_exit ("sudeste", "/d/asgard/room/mercado/mer2.c", "path"); 
        add_exit ("sudoeste", "/d/asgard/room/mercado/mer1.c", "path");
      
}