//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Templo de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Columna");
set_long ("%^BOLD%^%^BLACK%^Templo de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Columna\n\n"
         "Est�s delante de uno de los cuatro pilares del templo. Al observar a tu "
          "alrededor ves estatuas de criaturas horribles que extra�amente parecen tener "
          "vida, a pesar de estar inm�viles. Contienes tu respiraci�n, como si un resuello "
          "demasiado fuerte pudiera sacar de su eterno sue�o a estas criaturas. Todo lo "
          "que te rodea parece sacado directamente de la peor de tus pesadillas, hasta el "
          "punto que te hace pensar si esto ser� tan siquiera real.\n\n");
	
        set_exit_color("magenta");
	add_exit("noreste","/d/asgard/room/templo/entrada.c","corridor");
	
	add_item("columna","Grotesca y retorcida, completamente negra.\n");
	add_item(({"estatua","estatuas"}),"Arp�as, Grifos, Hydras, Gargolas, Demonios e "                      
        "infinidad de seres que no logras identificar.\n"); 
}
