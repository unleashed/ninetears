/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

// inherit "std/room.c";

object ayudante;

void setup()
{

   set_light(80);

   set_exit_color("white");
   
   set_short("%^BOLD%^CYAN%^Catedral de Brethem: Habitacion de Resureccion%^RESET%^");
//   set_save_file(BRETHEM +"raise");
//   set_helper_name("Herm");
   set_long("%^BOLD%^CYAN%^Catedral de Brethem: Habitacion de Resureccion%^RESET%^\n\n"
            "Esta estancia esta destinada a la resurreccion de aquellas almas en pena "
            "que aun no han acabado su tarea sobre estos reinos.\n"
            "Un cartel cuelga de la pared.\n\n");
//   set_percentage(100);

   add_sign("Es un cartel metalico puesto en una de las paredes.\n", 
            "/---------------------------------------------\\\n" +
            "|                                             |\n" +
            "|  Servicio de levantamiento de muertos de    |\n" +
            "|  Brethem.                                   |\n" +
            "|  Necesitas una cuenta aqui para que te      |\n" +
            "|  podamos cobrar.                            |\n" +
            "|                                             |\n" +
            "|  Pon 'crear' para abrir una cuenta.         |\n" +
            "|  'ingresar' para ingresar dinero.           |\n" +
            "|  'balance' para ver cuanto dinero te queda. |\n" +
            "|  'raise me' cuando necesites resucitar.     |\n" +
            "|  'raise <fantasma>' cuando uses tu cuenta   |\n" +
            "|  para resucitar a otra persona.             |\n" +
            "|                                             |\n" +
            "|  Un levantamiento cuesta 1 moneda de        |\n" +
            "|  platino por cada nivel.                    |\n" +
            "|                                             |\n" +
            "| NOTA: Si tu nivel es superior a 9 perderas  |\n" +  
            "| un punto de 'con' para siempre. Busca a un  |\n" +  
            "| clerigo con 'resurrect'.                    |\n" +  
            "| De estas cuentas no se puede sacar dinero.  |\n" +  
            "| Si te matan mucho, no podras resucitar mas  |\n" +  
            "| aqui, tendras que buscar otros lugares.     |\n" +  
            "|                                             |\n" +
            "\\---------------------------------------------/\n" );

   add_exit("sur",      BRETHEM + "catedral1.c","room");

   ayudante=clone_object(BRETHEM + "npcs/herm.c");
   ayudante->move(this_object());
}

void dest_me()
{
   if (ayudante)
      ayudante->dest_me();
}



