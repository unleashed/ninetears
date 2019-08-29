#define CREATOR "gareth"
/* Mas informacion sobre la creacion de rooms - Vilat 21.10.2002 */

// Esto ya se explica en workroom.c
inherit "/std/room.c";
void setup() {
	set_short("Sala de trabajo de "+capitalize(CREATOR));
	set_long(query_short()+"\n   La habitacion donde te encuentras ha sido pintada recientemente. Unos pocos muebles adornan la habitacion, algunos todavia en sus embalajes. Los mas importantes son el escritorio y su silla, que parecen haber pasado antes por otras manos a juzgar por su deterioro. En mitad del techo, una lampara oscila dando a la sala una iluminacion bastante tenue. Sin lugar a dudas deberias reacondicionar este lugar pronto.\n\n");

   	add_clone("/obj/misc/button.c",1);

   	add_exit("comun","/w/common","door");
   	"/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
	}

// Aqui viene lo nuevo
void init() {
	// Esta linea no la podemos olvidar porque si no no cargara correctamente
	// Viene a significar que se ejecute el init() del nivel superior
	// Es decir, que primero se carga el init() del archivo heredado (en este caso room.c)
   	::init();
	// add_action() sirve para anyadir acciones a una room. Sus parametros son:
	// - Funcion de destino: La funcion que llamaremos. Tiene que estar en el archivo o en un nivel superior
	// - Verbo: Lo que hay que escribir para ejecutar la accion
   	add_action("clean_desk","limpiar"); // Esto se ejecutara si ponemos 'limpiar' y ejecutara la funcion clean_desk
   	add_action("move_desk","mover"); // Esto ya deberiais entenderlo
	}

// Una funcion adicional, que se llama por el add_action() correspondiente. str es lo que escribamos despues del verbo.
// Si no nos va a importar lo que pongamos despues, podemos omitirlo.
// Las funciones llamadas por add_action() tienen que ser de tipo int, de modo que si devuelve 0 no se habra ejecutado la accion
// con exito, y si devuelve 1 si se habra ejecutado.
int clean_desk(string str) {
	// Aqui estamos procesando str, para saber si coincide con 'escritorio'
	// La sentencia if ejecutara lo que haya entre llaves si se cumple lo que hay entre parentesis
	if(str == "escritorio") {
		// tell_object() sirve para escribir un mensaje en la consola de un objeto. Sus parametros son:
		// - Objeto: A quien pasamos el mensaje. En este caso TP significa this_player(), que es quien ha ejecutado la accion
		// - Mensaje
      		tell_object(TP,"Empiezas a limpiar el escritorio y encuentras un periodico.\n");
		// tell_room() es lo mismo que tell_object() pero pasa el mensaje a todos los objetos de la room
		// - Room: El objeto de room. TO significa this_object() y se refiere a esta room
		// - Mensaje. query_cap_name() se ejecuta sobre un objeto y devuelve el nombre en mayusculas
		// - Mascara: Un objeto o conjunto que no reciben el mensaje
		tell_room(TO,TP->query_cap_name()+" limpia el escritorio y encuentra algo.\n",TP);

		// clone_object() crea un objeto nuevo (el que se le pasa como parametro)
		// move() se ha de llamar sobre un objeto y lo mueve al inventario de su parametro
		clone_object("/obj/misc/newcreator_paper.c")->move(TO);

		// Devolvemos 1 porque se ha ejecutado con exito
		// Return detiene la funcion, por lo que ya no se ejecutara lo que haya despues
		return 1;
   		} // Cerramos el if
	// Esta parte se ejecuta despues del if
	// Podriamos haber puesto directamente 'return 0' pero entonces nos saldria 'Ein?'
	// notify_fail() nos sirve para cambiar el mensaje de error
   	notify_fail("Todo parece limpio menos el escritorio.\n");
   	return 0;
	}

int move_desk(string str) {
   	if(str == "escritorio") {
      		tell_object(TP,"Con un gran esfuerzo, mueves el escritorio descubriendo una puerta oculta debajo.\n");
		tell_room(TO,this_player()->query_cap_name()+" mueve el escritorio.\n",TP);

      		add_exit("trampilla","/room/void.c","door");

		// Esta funcion apenas la he comentado porque se supone que ya sabeis lo que hace
		// Aqui hay algo nuevo: renew_exits() recarga las salidas de la room, y hay que llamarlo cuando pongamos o kitemos salidas
		// fuera del setup()
      		renew_exits();
      		return 1;
   		}

	// notify_fail() cuenta como un 0, asi que podemos resumirlo asi:
	return notify_fail("Mover que?\n");
   	}

// Bueno, a estas alturas debes estar preparado para hacer buenas rooms. Es el momento de construir tu casa, la primera fase de tu examen :)
