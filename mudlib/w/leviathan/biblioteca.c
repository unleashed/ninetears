inherit "/std/room.c";
void setup() { 
set_short("%^BOLD%^WHITE%^Biblioteca de %^BOLD%^RED%^Leviathan%^RESET%^.\n");

  set_long("%^BOLD%^WHITE%^Biblioteca de %^BOLD%^RED%^Leviathan%^RESET%^.\n\n    Aqui es donde %^BOLD%^RED%^"
	"Leviathan %^RESET%^trabaja y se mantiene separado del mundanal ruido, es una estancia"
	" amplia y con las paredes rodeadas de libros y papeles, algunos de ellos aun mas"
	" antiguos incluso que el mundo. Una mesa en un lateral y una buena iluminacion "
	"hacen que este sitio cumpla su papel a la perfeccion.\n\n");

   set_light(50);
   add_exit("fuera","/w/leviathan/workroom.c","door");
return(0);
}
