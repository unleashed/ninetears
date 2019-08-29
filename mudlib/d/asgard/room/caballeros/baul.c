//.oO JaDe Oo.  Junio'02
inherit "/std/vaults/vault_room";

void setup ()
{
  ::setup();
  set_guild_owner( ({"caballero de jade"}) );
  set_saqueable(1);	// saq. con opts por defecto
  set_short ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Armer�a");
  set_long ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Armer�a\n\n"
     "Te encuentras en una peque�a sala pr�cticamente sin decoraci�n a excepci�n "
     "de unos grandes colgadores para armas y armaduras y unos estantes para todo "
     "tipo de equipamiento de combate. "
     "Tambi�n puedes ver un gran baul en el centro de la sala.\n\n");
  add_item("baul","Es un gran cofre de piedra y metal.");
  
  set_exit_color("magenta");
  add_exit ("oeste", "/d/asgard/room/caballeros/circulo.c", "door");
}

/*int clean_up()
{
 return 1;
}*/
