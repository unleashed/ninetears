//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Calabozo de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Ala Este");
set_long ("Calabozo de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Ala Este\n\n"
          "Esta es una de las cuatro celdas del calabozo. Los barrotes son de un extra�o "
          "y oscuro metal, al observarlo de cerca sabes con certeza que no hay medio f�sico "
          "que pueda romperlos. Un sucio camastro y una letrina apestosa es lo �nico que hay "
          "en su interior. Observas algunos restos de comida mohosa a medio comer por las ratas.\n\n");
	set_light (60);
        set_exit_color("blue");
	add_exit("oeste","/d/asgard/room/hall/cala.c","corridor");
		 
}
