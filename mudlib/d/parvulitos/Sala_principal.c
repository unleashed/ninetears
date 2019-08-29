//VALDOR '99. <- Esto que ves es un comentario. Si vas a hacer comentarios pon dos barras antes de la linea.
// Si quieres poner comentarios diversos en lineas diversas( o desabilitar una zona del fichero atento:
/*
  lalalalal
   esto no lo leera 
  por las barras y estrellas ;)
  aunque suena americano jejej
   yata
*/

#include "path.h"  //Esto llama al fichero en cuestion para buscar aliases y demas..como el de APRENDICES que uso abajo

inherit "/std/room.c"; //Esto llama al fichero base de la habitacion en las librerias...podria ser una room.c como guild.c shop.c underground.c etc

void setup()  // Esta es la funcion principal de cualquier fichero de habitacion. Inicializa cualquier habitacion.
{
   set_short("%^BOLD%^Sala Principal%^RESET%^\n");  // Frase que sale en pantalla vayas en modo abreviado o en detallado.

   set_long("Te encuentras en la sala principal de aprendizaje. En esta zona aprenderas lo basico"
		" que hay que saber para  empezar a programar como creador. Como no, antes de empezar"
		" tu trabajo como creador deberas pasar una \"prueba\" para ver tu capacidad sobre el"
		" tema. Pon %^BOLD%^info%^RESET%^ para saber lo que tienes que hacer exactamente. Que "
		"hagas mas no importa. TIenes una semana de plazo. Hasta que no hallas visitado todas las " 
            "habitaciones del complejo no se te permitira volver a tu home, joven aprendiz. "
		"Te recomiendo encarecidamente que uses el %^BOLD%^more here%^RESET%^ siempre que acabes "
		"de ver una habitacion con detalle para ver como se hace. Todo lo contenido "
		"en esta zona esta disponible para tu aprendizaje en /d/parvulitos/.\n\n Ves un tablon.\n\n");
   //Solo sale en el detallado. Es la descripcion de la pantalla por general. 

   set_light(60); //Intensidad de luz en la habitacion...lo corriente es desde 0(oscuro total) a 180 o asin...lo normal entre 30 y 90.
 
   add_item ("tablon","Ves un tablon de madera que te indica 2 subapartados:\n"
			     "           1-\"comandos\" basicos del unix para moverse entre ficheros.\n"
			     "           2-\"editor\" del mud.\n\n"
			     " Teclea una de las dos opciones entre comillas.\n");
   /*El add_item crea una definicion que se vera cuando hagas mirar tablon(en el caso que he puesto).
     Suele usarse para hacer quests..o cosas escondia porque puede que este en la descripcion como que no.*/  

   add_clone(NPC+"",1);//pone el fichero NPC+"" si es un bicho u objeto fisico en la habitacion, el 1 es la cantidad de esos que pone.

   add_exit("norte",APRENDICES+"pasillo_1","door");
}

void init()//funcion de inicializacion..por norma general pon las acciones aqui.
{
   ::init();//Activa el init()
   add_action("info","info");//crea funciones a las cuales les definiras ciertos comandos para la room. El primer entrecomillado
   add_action("editor","editor");// te da el nombre de la funcion, el segundo como se activa.Veremos mas mas adelante.
   add_action("comandos","comandos");
   add_action("trampa",({"go","goto","goback","dest","home","ed"}));
}

int info() //el int de delante quiere decir que requiere un valor de salida par funcionar.
{
 write("\nTu examen consistira en crear 5 habitaciones distintas..una de las cuales se llamara "
       "workroom.c y sustituiras por la que tienes en tu directorio. Luego has de crear algun"
	 " npc como minimo(un bicho) con tal de que sepamos que podemos dejarte hacer una zona "
	 "entera con sus peligros y demas. Luego de ello has de crear algun objeto(arma,armadura o"
	 " cualquier otra cosa). Para terminar has de crear algo oculto, como una puerta secreta, "
	 "un bicho oculto en la habitacion o cualquier cosa que se te ocurra que pueda ser divertida"
       " de forma que, logicamnte leyendo en la habitacion o en otras habitaciones se pueda descubrir"
	 ". No quiero replicas de ningun tipo..me conozco todos los examenes de los demas, por lo tanto"
       " cuidado con lo que se hace. Todo lo que necesitas se encuentra en esta zona y no tienes"
	 " porque mirar el resto sin permiso.\n         %^RED%^BOLD%^"+CREATOR+"%^RESET%^\n\n");
  return 1;//Es el valor que devuelve la funcion...si es 0 quiere decir que fallo, 1 con exito.
}

int editor()
{
 if (TP->query_property("editor_dado"))
 {
  write("Pero que has hecho con el anterior bestia!!!\n\n.Te vuelve a aparecer un papel en las manos.\n\n");
  //El write sirve para decirle a la persona que realiza el comando algo en concreto.
  TP->add_clone(OBJ+"obj/papelito2",1);//TP o this_player() como prefirais es pa indicar que haga algo con el jugador que realiza el comando.
  say("Aparece de la nada un papel en las manos de "+TP->query_cap_name()+".\n");
  //El say le dice al resto(y no al propio jugador) algo en concreto..El uso de say y write hace
  // del uso de ciertos comandos como mas veridicos.El TP->query_cap_name() retorna el nombre del jugador.   
  return 1;
 }
 else //else es la otra opcion del if...si lo del if no se cumple siemrpe puedes recurrir al else para que ocurra algo..es opcional.
 {
  write("Con cara de sorpresa contemplas como te aparece un papel extranyo de la nada.\n\n");
  say("Aparece de la nada un papel en las manos de "+TP->query_cap_name()+".\n");
  TP->add_property("editor_dado",1);//Esto mas tarde.
  TP->add_clone(OBJ+"papelito2",1);
  return 1;
 }
 notify_fail("Este notify_fail nunca rulara pero lo pongo pa que sepas que se puede poner...mas que nada"
	"por si falla al hacer la accion. En otra habitacion ya veras como pero ten en cuenta para"
      " que se usa.\n\n");//eso mismo
 return 0;	

}

int comandos()
{
 if (TP->query_property("comandos_dados"))
 {
  write("Siempre perdiendolo todo lenyes. Aqui tienes otro.\n Leviathan te da otro papel.\n");
  TP->add_clone(OBJ+"papelito",1);
  say("Leviathan aparece ante el rostro asustado de "+TP->query_name()+" y le entrega un papel antes de irse.\n");
  return 1;
 }
 else
 {
  write("Leviathan aparece en frente de ti y te da un papel rugoso y aceitoso. Luego Leviathan desaparece.\n");
  say("Leviathan aparece ante el rostro asustado de "+TP->query_name()+" y le entrega un papel antes de irse.\n");
  TP->add_clone(OBJ+"papelito",1);
  TP->add_property("comandos_dados",1);
  return 1;
 }
}

int trampa()
{
  write("Nonono...Saldras cuando sepas salir.\n");
  return 1;
}



