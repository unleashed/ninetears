// Thalos

inherit "/std/raiseroom";
#include "../../path.h";

object ayudante;

void setup()
{
   set_short("%^BOLD%^Capilla de %^BLACK%^Keeron%^RESET%^");
   set_save_file(KEROONPOBRE +"raise");
   //set_helper_name("Durbub");
   set_long("Has entrado en la capilla de Durbub. "
            "La habitacion esta un poco mal decorada pero limpia. Puedes "
            "ver a muchos curanderos de aspecto serio moviendose por la "
            "sala atendiendo a los pacientes que van llegando, aun asi no dan a basto para atenderlos a todos.\n"+
            "Un cartel cuelga de la pared.\n");
    set_percentage(100);
    set_light(60);

   add_item(({"curandero", "curanderos"}), "Son unos jovenes clerigos duergars,"+
   "estan aqui bajos las ordenes de Durbub para curar y resucitar, aunque debido"+
   "a su inexperiencia no obtienen grandes resultados. Se mueven por la habitacion"+
   "con movimientos fluidos i organizados. Son gente ocupada, y no parece que sonrian a menudo. \n");

   add_sign("Es un cartel metalico puesto en una de las paredes.\n", 
            "/---------------------------------------------\\\n" +
            "|                                             |\n" +
            "|  Servicio de levantamiento de muertos de    |\n" +
            "|  Keroon.                                    |\n" +
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
            "\\--------------------------------------------//\n" );

add_exit("fuera",KEROONPOBRE+"keroon_76.c","standard");
   ayudante=clone_object(NPCS+"durbub");
   ayudante->move(this_object());
}

void dest_me()
{
   if (ayudante)
      ayudante->dest_me();
}
