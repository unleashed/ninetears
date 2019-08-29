//.oO JaDe Oo.  Noviembre'02
inherit "/std/vaults/vault_room";

void setup ()
{
  ::setup();
  set_guild_owner( ({"hechicero del caos"}) );
  set_saqueable(1);	// saq. con opts por defecto
  set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Ba�l");
  set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Ba�l\n\n"
     "Te encuentras en una peque�a sala pr�cticamente sin decoraci�n a excepci�n "
     "de unos grandes colgadores para armas y armaduras y unos estantes para todo "
     "tipo de equipamiento de combate. "
     "Tambi�n puedes ver un gran baul en el centro de la sala.\n\n");
  add_item("ba�l","Es un gran cofre de metal rojizo.");
  
  set_exit_color("red");
  add_exit ("oeste", "/d/asgard/room/hechiceros/esc4-5.c", "door");
  add_exit ("sur", "/d/asgard/room/hechiceros/esc4-3.c", "door");
}

/*int clean_up()
{
 return 1;
}*/
