//.oO JaDe Oo.  Noviembre'02
inherit "/std/vaults/vault_room";

void setup ()
{
  ::setup();
  set_guild_owner( ({"sacerdote del caos"}) );
  set_saqueable(1);	// saq. con opts por defecto
  set_short ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Ba�l");
  set_long ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Ba�l\n\n"
     "Te encuentras en una peque�a sala pr�cticamente sin decoraci�n a excepci�n "
     "de unos grandes colgadores para armas y armaduras y unos estantes para todo "
     "tipo de equipamiento de combate. "
     "Tambi�n puedes ver un gran baul en el centro de la sala.\n\n");
  add_item("ba�l","Es un gran cofre de m�rmol azulado.");
  
  set_exit_color("cyan");
  add_exit ("norte", "/d/asgard/room/sacerdotes/expiacion.c", "door");
  add_exit ("oeste", "/d/asgard/room/sacerdotes/tablon.c", "door");
}

/*int clean_up()
{
 return 1;
}*/
