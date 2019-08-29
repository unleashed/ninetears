// En fase de pruebas por Leviathan 2002


inherit "std/pub";
#include "pub.h"
#include "/w/leviathan/path.h"

object comellas, globo, tablon, gerente;

//nombre.tipo.coste.heal.volumen.intox

void setup()
{
// El primer menu es el "gratix" pa la epoca de pruebas...

   add_menu_item("Mac Chupiguay", FOOD, 1, 100, 30, 0,
      "te comes una grasienta y nutritiva zamburguesa", "se come una apestosa zamburguesa "
      "y empieza a ponerse verdoso");

   add_menu_item("Licor del Montanyero", ALCOHOL, 300, 10, 30, 100,
      "bebes un licor muy fuerte", "se bebe un licor y seguidamente se le "
      "suben los colores a la cara");
   
   add_menu_item("Cerveza Negra", ALCOHOL, 150, 5, 20, 50,
      "bebes con gusto una fria cerveza negra", "se bebe con gusto una "
      "fria cerveza negra");
      
   add_menu_item("Cochinillo Asado", FOOD, 1750, 35, 50, 0,
      "comes tranquilamente un cochinillo asado entero", "se come un "
      "apetitoso cochinillo asado");
   add_menu_item("Pollo Hervido", FOOD, 1000, 20, 30, 0,
      "comes un pollo hervido con verduras", "se come un pollo hervido "
      "con verduras");
    
   add_menu_alias("mac", "Mac Chupiguay");
   add_menu_alias("licor", "Licor del Montanyero");
   add_menu_alias("cerveza", "Cerveza Negra");
   add_menu_alias("cochinillo", "Cochinillo Asado");
   add_menu_alias("pollo", "Pollo Hervido");

   set_short("%^BLUE%^BOLD%^Garito L'Esperteyu%^RESET%^\n");
   set_long("%^BLUE%^BOLD%^Garito L'Esperteyu%^RESET%^\n\n"
	    "Estas en el Garito L'Esperteyu, el unico garito que hay "
	    "en el poblado de Avalon. Aqui descansan y reponen fuerzas "
            "los exploradores y aventureros que quieren darse chope sin descanso. "
            "Es un sitio rustico adornado casi todo con "
            "articulos hechos de madera. Puedes ver una larga barra donde "
            "se sirve la comida.\n\n");
   
   add_exit("fuera", "/room/entryroom");
   set_light(60);
   
   add_item("barra", "Es una larga barra por la cual se sirven las bebidas "+
                     "o comidas que los clientes piden.\n");	
}



void reset()
{
        if (!gerente) {
                gerente = clone_object("/room/tabernero.c");
                gerente->move(this_object());
        }
}


