//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Capilla");
set_long ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Capilla\n\n"
          "Esta peque�a pero ricamente decorada sala es el lugar donde los Caballeros "
          "rinden culto a su Diosa. Aqui proclaman su servidumbre y elevan sus rezos "
          "y plegarias en busca del favor de JaDe. Ves un pequenyo altar al fondo de la "
          "capilla, cubierto por un delicado manto de seda purpura. Observas peque�os "
          "utensilios rituales encima del altar. La iluminacion de la sala proviene de "
          "un par de candelabros de pie situados a ambos lados del altar.\n\n");
	
        set_exit_color("magenta");
	add_exit ("oeste", "/d/asgard/room/caballeros/entrada.c", "door");

}
