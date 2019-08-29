 inherit "std/pub";
#include "../../path.h"
#include "/include/pub.h"
 void setup()
 {
 
    add_menu_item("Licor de Pretyus", ALCOHOL, 300, 10, 30, 100,
           "bebes un licor de Pretyus muy fuerte", "se bebe un licor de Pretyus");

       
    add_menu_item("Cereales quemados", FOOD, 1750, 35, 50, 0,
       " quemas al comer los cereales", "salta al comer los "
       "cereales, parece haberse quemado");
    add_menu_item("Ternera frita", FOOD, 1000, 20, 30, 0,
       " comes ternera frita", "se come un pequenyo cacho "
       "de ternera frita");
     

    add_menu_alias("licor", "Licor de Pretyus");
    add_menu_alias("cereales", "Cereales quemados");
     add_menu_alias("ternera", "Ternera frita");
 
 
    set_short("%^BLUE%^BOLD%^Taberna de Grandhum%^RESET%^\n");
    set_long("%^BLUE%^BOLD%^Taberna de Gandhum%^RESET%^\n\n"
       "Estas en el la taberna de Grandhum, una pobre taberna"
       "llena de telranyas, esta muy sucia. Notas que es una "
       " taberna poco transitada, la cocinera esta detras de una"
       "larga barra.\n\n");
    add_clone(NPC+"cocinera_grandhum.c",1);
    add_clone(NPC+"habitante_grandhum.c",1);
    add_clone(NPC+"comerciante_grandhum.c",1);
    add_exit("fuera",ROOMGRAN"GRAN14.c","door");
    set_light(50);
    
    add_item("barra", "Es una barra que te llega por el pecho, "
    " la barra esta muy sucia.\n");      
 }
 