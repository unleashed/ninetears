//.oO JaDe Oo.  Junio'02
inherit "/std/room.c";
void setup() 
{
	 
  set_short("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Pasillo.");
  set_long("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Pasillo.\n\n"
	"Un l�gubre y estrecho pasillo decorado con multitud de tapices y emblemas. "
	"A ambos lados del corredor hay sendos candelabros de pie con decenas de "
	"velas encendidas permanentemente. En la parte derecha hay un banco de madera "
	"maziza con m�ltiples grabados. En la parte izquierda observas un gran tapiz "
	"con un gran ojo esmeralda bordado en el centro.\n\n");

   set_exit_color("magenta");
   add_exit ("sur", "/d/asgard/room/caballeros/tablon.c", "corridor"); 
   add_exit("norte","/d/asgard/room/caballeros/entrada.c","corridor");

}
