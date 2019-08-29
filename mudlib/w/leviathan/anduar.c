inherit "/std/room.c";
void setup() { 
set_short("%^BOLD%^WHITE%^Distribuidor de Anduar%^RESET%^.\n");

  set_long(query_short()+"\n\nAqui es donde %^BOLD%^RED%^"
	"Leviathan %^RESET%^trabaja y se mantiene separado del mundanal ruido, es una estancia"
	" amplia y con las paredes rodeadas de libros y papeles, algunos de ellos aun mas"
	" antiguos incluso que el mundo. Una mesa en un lateral y una buena iluminacion "
	"hacen que este sitio cumpla su papel a la perfeccion.\n\n");

   add_exit("poeste","/w/leviathan/anduar/rooms/puerta1403.c","door");
   add_exit("peste","/w/leviathan/anduar/rooms/puerta1425.c","door");
   add_exit("psur","/w/leviathan/anduar/rooms/puerta2514.c","door");
   add_exit("pnorte","/w/leviathan/anduar/rooms/puerta0314.c","door");
return(0);
}
