/* A temple for raising..
 * Needs money to work...
 * Inherits /std/raiseroom.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

inherit "/std/raiseroom";
#include "path.h";

object helper;

void setup()
  {
   set_helper_name("june");
  set_short("Isla de Havmand: Resurrecion");
  set_save_file(file_name(this_object()));
    set_long("\nIsle of Havmand: Resurrecion.\n\n"
    "   Este es el cuarto al que has de venir, en espiritu, en caso de resultar muerto "
    "y quieres volver a la vida. Es un cuarto muy tranquilo y lleno de paz, en contraste "
    "con el resto del poblado esta bien cuidado. Las paredes y el suelo estan limpios y la "
   "pintura se ve fresca, ademas se respira un olor agradable. Algo brilla al fondo.\n"
         "Si necesitas ser resucitado deberias hecharle un vistazo al signo que hay en "
	 " la pared. \n\n");
  set_percentage(100);
  set_light(60);

    add_smell("aire","Un agradable olor a flores inunda el ambiente.\n");
add_item("brillo", "Un pequenyo altar al dios Hokemj esta colocado en una esquina.  A su "
	"alrededor hay unas cuantas velas encendidas, otras velas hacen un pasillo que "
	"conduce al centro del cuarto donde hay una especie de catre"
	".\n");
add_item(({"catre", "cot"}), "Unas cuantas tablas de madera hacen las veces de cama, "
	"es donde los cuerpos son examinados y tratados.\n");
//add_item(({"healer", "healers"}), "Stern looking individuals who spend their"
//	" days raising people from the dead.  They move about the"
//	" room, their movements fluid and purposeful.  They are busy"
//	" people, and don't look like they smile often. \n");
  add_sign("/---------------------------------------------\\\n" 
           "|                                             |\n" 
           "|   Isla de Havmand: Cuarto de resurrecion    |\n" 
           "|                                             |\n" 
           "| Escribe resucita <fantasma> para devolverlo |\n"
	   "|              a la vida.                     |\n" 
           "|_____________________________________________|\n" 
             "\n\n");


   add_exit("este",HAVMAND+"t07.c","door");
}

void reset()
  {
  if (!helper)
    {
   helper = clone_object("/baseobs/monsters/healer");
    helper->move(this_object());
    }
   helper->set_name("june");
   helper->set_gender(2);
   helper->set_short("June");
   helper->set_long("Una alta mujer de mediana edad, con el pelo oscuro y los ojos "
   "de un marron tan oscuro que casi es negro. Tiene un aire un tanto extranyo, pero "
   "los fantasmas tampoco pueden permitirse ser muy quisquillosos.\n");
} /* void reset */ 

void dest_me()
  {
  if (helper)
    helper->dest_me();
   ::dest_me();
} /* void dest me */
