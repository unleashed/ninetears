
inherit "std/pub";
#include "pub.h"
#include "/w/leviathan/path.h"

object comellas, globo, tablon, gerente;

//nombre.tipo.coste.heal.volumen.intox

void setup()
{

 add_menu_item("Pollo Asado", FOOD, 0, 1000, 30, 0,
"te comes una racion de pollo asado", "se come una racion de "
"pollo asado");

add_menu_item("Casalla Valenciana", ALCOHOL, 0, 10, 30, 150,
"bebes un licor muy fuerte", "se bebe un licor y seguidamente se le"
"suben los colores a la cara");

add_menu_item("Cerveza Negra", ALCOHOL, 0, 5, 20, 50,
"bebes con gusto una fria cerveza negra", "se bebe con gusto una "
"fria cerveza negra");

add_menu_item("Surtidos de varios mariscos", FOOD, 0, 3500, 50, 0,
"comes tranquilamente unos surtidos mariscos", "se come un "
"apetitoso bogabante servido en una bandeja de oro");

add_menu_item("Entrecot de Ciclope", FOOD, 0, 2000, 30, 0,
"comes un sabroso entrecot de ciclope", "se como un entrecot de "
"ciclope con caviar de fardatxo peludo");

add_menu_alias("pollo", "Pollo Asado");
add_menu_alias("licor", "Casalla Valenciana");
add_menu_alias("cerveza", "Cerveza Negra");
add_menu_alias("mariscos", "Surtidos de varios mariscos");
add_menu_alias("entrecot", "Entrecot de Ciclope");

set_short("%^GREEN%^Restaurante de Casa Sharka%^RESET%^.");

set_long("%^GREEN%^Restaurante de Casa Sharka%^RESET%^.\n\nNo sabes la suerte "
" que tienes al poner acceder al exclusivo restaurante del poderoso inmortal "
" Sharka que gracias a sus extraordinarios poderes creo este recinto\n\n");

set_light (60);

add_sound("Cheff","Que desea que les prepare???\n");
add_sound("Cheff","Tomaran los senyores algun plato en especial o les sirvo el menu del dia???\n");
add_sound("Cheff","Quizas preferiran tomar algunas copas o bebidas refrescantes\n???");

add_exit("oeste","/w/sharka/casa/bar.c","door");

add_item("barra", "Es una larga barra por la cual se sirven las bebidas"
                      "o comidas que los clientes piden.\n");
}


void reset()
{

if (!gerente) {
              gerente = clone_object("/room/tabernero.c");
              gerente->move(this_object());
              }
}